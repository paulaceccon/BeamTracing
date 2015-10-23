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


Source::Source(const Room r, const core::Pointf p)
{
    _insideRoom = r;
    _position = p;
}


Source::Source(const Source& s) 
{
    _insideRoom = s.getInsideRoom();
    _position = s.getPosition();
}


Source::~Source() 
{
}


const Room Source::getInsideRoom() const
{
    return _insideRoom;
}


const core::Pointf Source::getPosition() const
{
    return _position;
}

