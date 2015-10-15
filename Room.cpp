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


Room::Room(const std::vector<Wall> w)
{
    _walls = w;
}


Room::Room(const Room& r) 
{
    _walls = r._walls;
}


Room::~Room() 
{
}


std::vector<Wall> Room::getWalls()
{
    return _walls;
}


void Room::addWall(const Wall& w)
{
    _walls.push_back(w);
}

