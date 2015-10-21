/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Source.cpp
 * Author: paulaceccon
 * 
 * Created on October 21, 2015, 3:48 PM
 */

#include "Source.h"

Source::Source() 
{
}


Source::Source(const Room r)
{
    _insideRoom = r;
}


Source::Source(const Source& s) 
{
    _insideRoom = s._insideRoom;
}


Source::~Source() 
{
}



Room Source::getInsideRoom()
{
    return _insideRoom;
}

