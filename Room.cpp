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


Room::Room(const std::vector<int> w, const int id)
{
    _wallsIdx = w;
    _id = id;
}


Room::Room(const Room& r) 
{
    _wallsIdx = r.getWallsIdx();
    _id = r.getRoomIdx();
}


Room::~Room() 
{
}


const std::vector<int>& Room::getWallsIdx() const
{
    return _wallsIdx;
}


void Room::addWallIdx(const int w)
{
    _wallsIdx.push_back(w);
}


const int Room::getRoomIdx() const
{
    return _id;
}


void Room::setIdx(const int id)
{
    _id = id;
}

