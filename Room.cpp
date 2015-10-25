/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Room.cpp
 * Author: pceccon
 * 
 * Created on October 15, 2015, 12:35 PM
 */

#include "Room.h"

Room::Room() 
{
}


Room::Room(const std::vector<int> w, const std::vector<int> ori, const int id)
{
    _wallsIdx = w;
    _wallsOr = ori,
    _id = id;
}


Room::Room(const Room& r) 
{
    _wallsIdx = r.getWallsIdx();
    _wallsOr = r.getWallOrs();
    _id = r.getRoomIdx();
}


Room::~Room() 
{
}


const std::vector<int>& Room::getWallsIdx() const
{
    return _wallsIdx;
}


const std::vector<int>& Room::getWallOrs() const
{
    return _wallsOr;
}


const int Room::getWallOr(const int i) const
{
    for (unsigned int j = 0; j < _wallsIdx.size(); j++)
    {
        if (_wallsIdx[j] == i)
            return _wallsOr[j];
    }
}


void Room::addWall(const int w, const int o)
{
    _wallsIdx.push_back(w);
    _wallsOr.push_back(o);
}


const int Room::getRoomIdx() const
{
    return _id;
}


void Room::setIdx(const int id)
{
    _id = id;
}

