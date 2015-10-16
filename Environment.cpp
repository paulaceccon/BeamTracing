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

#include <iostream>

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
    
//    for (unsigned int i = 0; i < adj.size(); i++)
//    {
//        std::cout << "Edge " << i << " present in room(s): ";
//        for (unsigned int j = 0; j < adj[i].size(); j++)
//        {
//            std::cout << adj[i][j] << " ";
//        }
//        std::cout << std::endl;
//    } 
}


void Environment::buildAdjacencyGraph(std::vector<std::vector<Node> >& adj)
{
    std::vector<std::vector<int> > edgesRooms;
    edgesRooms.resize(_walls.size());
    buildEdgesInRooms(edgesRooms);
    
    for (unsigned int i = 0; i < edgesRooms.size(); i++)
    {
       for (unsigned int j = 0; j < edgesRooms[i].size(); j++)
       {
            for (unsigned int k = 0; k < edgesRooms[i].size(); k ++)
            {
                if (k != j)
                {
                    Node n;
                    n.roomIdx = k;
                    n.wallIdx = i;
                    adj[j].push_back(n);
                }
            }
       }
    }
    
    for (unsigned int i = 0; i < adj.size(); i++)
    {
        std::cout << "Room " << i << " reaches room(s): ";
        for (unsigned int j = 0; j < adj[i].size(); j++)
        {
            std::cout << adj[i][j].roomIdx << " " << " through edge " << adj[i][j].wallIdx;
        }
        std::cout << std::endl;
    } 
}

