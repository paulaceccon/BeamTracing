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
    _line.startPoint.x = 0.0;
    _line.startPoint.y = 0.0;
    _line.endPoint.x = 0.0;
    _line.endPoint.y = 0.0;
    
    _specularity = 0.0;
}


Wall::Wall(const Line<float>& l, const float s)
{
    _line = l;
    _specularity = s;
}


Wall::Wall(const Wall& w) 
{
    _line = w.getLine();
    _specularity = w.getSpecularValue();
}


Wall::~Wall() 
{
}


Line<float> Wall::getLine() const
{
    return _line;
}


float Wall::getSpecularValue() const
{
    return _specularity;
}

