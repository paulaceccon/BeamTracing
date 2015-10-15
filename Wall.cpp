/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Wall.cpp
 * Author: pceccon
 * 
 * Created on October 15, 2015, 12:26 PM
 */

#include "Wall.h"

Wall::Wall() 
{
    _wall.startPoint.x = 0.0;
    _wall.startPoint.y = 0.0;
    _wall.endPoint.x = 0.0;
    _wall.endPoint.y = 0.0;
    
    _specularity = 0.0;
}


Wall::Polygon(const Line& l, const float s)
{
    _wall = l;
    _specularity = s;
}


Wall::Wall(const Wall& w) 
{
    _wall = w.getWall();
    _specularity = w.getSpecularValue();
}


Wall::~Wall() 
{
}


Line Wall::getWall()
{
    return _wall;
}


float Wall::getSpecularValue()
{
    return _specularity;
}

