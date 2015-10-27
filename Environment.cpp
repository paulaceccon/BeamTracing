/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Environment.cpp
 * Author: pceccon
 * 
 * Created on October 15, 2015, 1:02 PM
 */

#include "Environment.h"
#include "Ray.h"
#include "Tree.h"

#include <iostream>

#define MAX 2

Environment::Environment() 
{
}


Environment::Environment(const Environment& e) 
{
    _rooms = e.getRooms();
}


Environment::Environment(const std::vector<Room> r)
{
    _rooms = r;
}


Environment::~Environment() 
{
}


const std::vector<Room>& Environment::getRooms() const
{
    return _rooms;
}


void Environment::addRoom(const Room& r)
{
    _rooms.push_back(r);
}


const std::vector<Wall>& Environment::getWalls() const
{
    return _walls;
}


void Environment::addWall(const Wall& w) 
{
    _walls.push_back(w);
}


const std::vector<core::Pointf>& Environment::getPoints() const
{
    return _points;
}


void Environment::addPoint(const core::Pointf& p)
{
    _points.push_back(p);
}


void Environment::setSource(const Source& s) 
{
    _source = s;
}


void Environment::buildEdgesInRooms(std::vector<std::vector<int> >& adj)
{
    for (unsigned int i = 0; i < _rooms.size(); i++)
    {
        const std::vector<int>& wallsIdx = _rooms[i].getWallsIdx();
        for (unsigned int j = 0; j < wallsIdx.size(); j++)
        {            
            adj[wallsIdx[j]].push_back(i);
        }
    }
    
    for (unsigned int i = 0; i < adj.size(); i++)
    {
        std::cout << "Edge " << i << " present in room(s): ";
        for (unsigned int j = 0; j < adj[i].size(); j++)
        {
            std::cout << adj[i][j] << " ";
        }
        std::cout << std::endl;
    } 
}


const Tree& Environment::getBeamTree() const
{
    return _beamTree;
}


void Environment::buildAdjacencyGraph(std::vector<std::vector<GraphNode> >& adj)
{
    std::vector<std::vector<int> > edgesRooms;
    edgesRooms.resize(_walls.size());
    buildEdgesInRooms(edgesRooms);
    
    std::cout << "Number of walls: " << edgesRooms.size() << std::endl;
    for (unsigned int i = 0; i < edgesRooms.size(); i++)
    {
       for (unsigned int j = 0; j < edgesRooms[i].size(); j++)
       {
            for (unsigned int k = 0; k < edgesRooms[i].size(); k ++)
            {
                if (edgesRooms[i][k] != edgesRooms[i][j])
                {
                    GraphNode n;
                    n.roomIdx = edgesRooms[i][k];
                    n.wallIdx = i;
                    adj[edgesRooms[i][j]].push_back(n);
                }
            }
       }
    }
    
    std::cout << "Number of rooms: " << adj.size() << std::endl;
    for (unsigned int i = 0; i < adj.size(); i++)
    {
        std::cout << "Room " << i << " reaches room(s): " << std::endl;
        for (unsigned int j = 0; j < adj[i].size(); j++)
        {
            std::cout << "\t" << adj[i][j].roomIdx << " " << " through edge " << adj[i][j].wallIdx << std::endl;
        }
        std::cout << std::endl;
    } 
}


void Environment::traverse(const std::vector<std::vector<GraphNode> >& adj, int v, TreeNode& t, int max)
{
    if (max > MAX)
        return;
    
    for (unsigned int i = 0; i < adj[v].size(); i++)
    {     
        std::cout << "v" << v << " ";
        // Calculates the new source point
        auralization(t, adj[v][i]);
        // If it's a wall, continue in v
        if (_walls[adj[v][i].wallIdx].getSpecularValue() != INFINITY)
            traverse(adj, v, t.getChild(i), max+1);
        // If it's not a wall, visit this new room
        else
            traverse(adj, adj[v][i].roomIdx, t.getChild(i), max+1);
        
        std::cout << "<<" << std::endl;
    }
}
 

void Environment::DFS(const std::vector<std::vector<GraphNode> >& adj, int v)
{
    // The root
    TreeNode n(v, -1, _source.getPosition(), _source.getPosition(), _source.getPosition());
    _beamTree.root = n;
    
    traverse(adj, v, _beamTree.root, 1);
    
    std::cout << std::endl;
    _beamTree.printTree(_beamTree.root);
}


void Environment::auralization(TreeNode& t, const GraphNode &n)
{
    Wall w = _walls[n.wallIdx];
    int ori = _rooms[n.roomIdx].getWallOr(n.wallIdx);
    
    core::Pointf sP, eP;
    // Defining how to read the points (to follow the same orientation for 
    // each room)
    if (ori == 1)
    {
        sP = _points[w.getStartPoingID()];
        eP = _points[w.getEndPointID()];
    }
    else
    {
        sP = _points[w.getEndPointID()];
        eP = _points[w.getStartPoingID()];
    }
    
    core::Pointf srcP = t.getSourcePosition();
    
    // Rays coming from the current source
    core::Vectorf v1(sP.x - srcP.x, sP.y - srcP.y);
    core::Vectorf v2(eP.x - srcP.x, eP.y - srcP.y);
    
    // Reflection
    if (w.getSpecularValue() != INFINITY)
    {   
        // Opting for the right vector that is normal to the intersected line
        core::Vectorf lv(eP.x - sP.x, eP.y - sP.y);
        core::Vectorf op(sP.y - eP.y, eP.x - sP.x);
        if ((lv * op) / (lv.length() * op.length()) != 0)
        {
            op.x = eP.y - sP.y;
            op.y = sP.x - eP.x;
        }
            
        v1.normalize();
        v2.normalize();
        op.normalize();
        
        core::Vectorf rv1 = (2 * (v1 * op) * op - v1) * -1; // To change direction
        core::Vectorf rv2 = (2 * (v2 * op) * op - v2) * -1; 
        
        // Finding the point of intersection (new source point) between the reflected
        // rays
        // P = P0 + tV
        core::Pointf p1a(sP.x, sP.y);
        core::Pointf p1b(sP.x + rv1.x, sP.y + rv1.y);
        
        core::Pointf p2a(eP.x, eP.y);
        core::Pointf p2b(eP.x + rv2.x, eP.y + rv2.y);
        
        float a1 = p1a.y - p1b.y;
        float b1 = p1a.x - p1b.x;
        float c1 = p1a.x * p1b.y - (p1a.y * p1b.x);
        
        float a2 = p2a.y - p2b.y;
        float b2 = p2a.x - p2b.x;
        float c2 = p2a.x * p2b.y - (p2a.y * p2b.x);
        
        float u = b1 * c2 - (c1 * b2);
        float v = a1 * c2 - (c1 * a2);
        float w = a1 * b2 - (b1 * a2);

        core::Pointf ns(u/w, v/w);
        TreeNode tn(n.roomIdx, n.wallIdx, ns, eP, sP);
        t.addChild(tn);
    }
    
    // Transmission
    // Source point keeps the same
    else
    {
        TreeNode tn(t.getInsideRoom(), n.wallIdx, srcP, sP, eP);
        t.addChild(tn);
    }
}

