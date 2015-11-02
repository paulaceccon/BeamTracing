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
#include "MathUtils.h"

#include <iostream>

#define MAX 3

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


Tree& Environment::getBeamTree()
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
    if (max > MAX+1)
        return;
    
    for (unsigned int i = 0; i < adj[v].size(); i++)
    {       
        if (t.getThroughWall() != adj[v][i].wallIdx)
        {
            std::cout << v << " " << adj[v][i].wallIdx << " " << max << " " << t.getThroughWall() << std::endl;

            if (max == 1)
            {
                t.setPoint(1, _points[_walls[adj[v][i].wallIdx].getStartPoingID()]);
                t.setPoint(0, _points[_walls[adj[v][i].wallIdx].getEndPointID()]);
            }
                
            core::Pointf i1;
            core::Pointf i2;
            bool recheable = intersectBeam(t, _points[_walls[adj[v][i].wallIdx].getStartPoingID()], _points[_walls[adj[v][i].wallIdx].getEndPointID()], i1, i2);
            
            std::cout << v << " " << adj[v][i].wallIdx << " " << max << " " << t.getThroughWall() << " " << recheable << std::endl;
            if (recheable)
            {
                // Calculates the new source point
                soundPropagation(t, adj[v][i], i1, i2);
                // If it's a wall, continue in v
                if (_walls[adj[v][i].wallIdx].getSpecularValue() != INFINITY)
                    traverse(adj, v, t.getLastAddedChild(), max+1);
                // If it's not a wall, visit this new room
                else
                    traverse(adj, adj[v][i].roomIdx, t.getLastAddedChild(), max+1);
            }
        }
    }
}
 

void Environment::DFS(const std::vector<std::vector<GraphNode> >& adj, int v)
{
    // The root
    TreeNode n(v, -1, _source.getPosition(), _source.getPosition(), _source.getPosition());
    _beamTree.root = n;
    
    std::cout << "v" << v << std::endl;
    
    traverse(adj, v, _beamTree.root, 1);
    
    std::cout << std::endl;
    _beamTree.printTree(_beamTree.root, 0);
}


void Environment::getOrientedWallPoints(const int wId, const int rId, core::Pointf& sP, core::Pointf& eP)
{
    Wall w = _walls[wId];
    int ori = _rooms[rId].getWallOr(wId);
    
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
}


TreeNode& Environment::soundPropagation(TreeNode& t, const GraphNode &n, core::Pointf& i1, core::Pointf& i2)
{
    Wall w = _walls[n.wallIdx];
    
    core::Pointf sP, eP;
    getOrientedWallPoints(n.wallIdx, t.getInsideRoom(), sP, eP);
    
    core::Pointf srcP = t.getSourcePosition();
    
    // Reflection
    if (w.getSpecularValue() != INFINITY)
    {   
        // Rays coming from the current source
        core::Vectorf v1(i1.x - srcP.x, i1.y - srcP.y);
        core::Vectorf v2(i2.x - srcP.x, i2.y - srcP.y);
    
        // Getting the normal (given by @a and @b) of the plane in 
        // which the reflection will be performed.
        float a, b, c;
        MathUtils::lineEquation(sP, eP, a, b, c);
        
        core::Vectorf op(a, b);
            
        v1.normalize();
        v2.normalize();
        op.normalize();
        
        core::Vectorf rv1 = (2 * (v1 * op) * op - v1); 
        core::Vectorf rv2 = (2 * (v2 * op) * op - v2); 
        
        // Finding the point of intersection (new source point) between the reflected
        // rays
        // P = P0 + tV
        core::Pointf p1a(i1.x, i1.y);
        core::Pointf p1b(i1.x + rv1.x, i1.y + rv1.y);
        
        core::Pointf p2a(i2.x, i2.y);
        core::Pointf p2b(i2.x + rv2.x, i2.y + rv2.y);
        
        core::Pointf ns(0.0, 0.0);
       
        MathUtils::pointOfIntersection(p1a, p2a, p1b, p2b, ns);
        TreeNode tn(t.getInsideRoom(), n.wallIdx, ns, i2, i1);
        t.addChild(tn);
    }
    
    // Transmission
    // Source point keeps the same
    else
    {
        TreeNode tn(n.roomIdx, n.wallIdx, srcP, sP, eP);
        t.addChild(tn);
    }
    
    return t.getLastAddedChild();
}


bool Environment::intersectBeam(const TreeNode& t, const core::Pointf& pa, const core::Pointf& pb, core::Pointf& outA, core::Pointf& outB)
{
    core::Vectorf middle((t.getPoint(1).x - t.getSourcePosition().x) + (t.getPoint(2).x - t.getSourcePosition().x),
            (t.getPoint(1).y - t.getSourcePosition().y) + (t.getPoint(2).y - t.getSourcePosition().y));
    middle.normalize();
    
    // Getting the line equations that define the two rays
    float a1, b1, c1;
    float a2, b2, c2;
    MathUtils::lineEquation(t.getSourcePosition(), t.getPoint(1), a1, b1, c1);
    MathUtils::lineEquation(t.getSourcePosition(), t.getPoint(2), a2, b2, c2);
    
    core::Pointf test(t.getSourcePosition().x + middle.x, t.getSourcePosition().y + middle.y);
    
    // Adjusting normal of the lines
    if ((test.x * a1 + test.y * b1 + c1) < 0)
    {
        a1 *= -1;
        b1 *= -1;
        c1 *= -1;
    }
    if ((test.x * a2 + test.y * b2 + c2) < 0)
    {
        a2 *= -1;
        b2 *= -1;
        c2 *= -1;
    }
    
    float r1a = pa.x * a1 + pa.y * b1 + c1;
    float r1b = pb.x * a1 + pb.y * b1 + c1;
    float r2a = pa.x * a2 + pa.y * b2 + c2;
    float r2b = pb.x * a2 + pb.y * b2 + c2;
    
    // If the edge is outside the beam
    if ((r1a < 0 && r1b < 0) || (r2a < 0 && r2b < 0))
        return false;
    // If the edge is completely inside the beam
    if ((r1a >= 0 && r1b >= 0) && (r2a >= 0 && r2b >= 0))
    {
        outA = pa;
        outB = pb;
    }
    // If the edge cross the beam
    else
    {
        MathUtils::pointOfIntersection(pa, t.getSourcePosition(), pb, t.getPoint(1), outA);
        MathUtils::pointOfIntersection(pa, t.getSourcePosition(), pb, t.getPoint(2), outB);
        if (!MathUtils::pointInSegment(pa, pb, outA) || !MathUtils::pointInSegment(pa, pb, outB))
            return false;
    }
    return true;
}

