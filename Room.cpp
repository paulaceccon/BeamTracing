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


Room::Room(const std::vector<int> w)
{
    _wallIdx = w;
}


Room::Room(const Room& r) 
{
    _wallIdx = r._wallIdx;
}


Room::~Room() 
{
}


std::vector<int> Room::getWallsIdx()
{
    return _wallIdx;
}


void Room::addWallIdx(const int w)
{
    _wallIdx.push_back(w);
}

