/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Receiver.cpp
 * Author: paulaceccon
 * 
 * Created on October 21, 2015, 3:56 PM
 */

#include "Receiver.h"

Receiver::Receiver() 
{
}


Receiver::Receiver(const Room r)
{
    _insideRoom = r;
}


Receiver::Receiver(const Receiver& r) 
{
    _insideRoom = r._insideRoom;
}


Receiver::~Receiver() 
{
}


Room Receiver::getInsideRoom()
{
    return _insideRoom;
}



