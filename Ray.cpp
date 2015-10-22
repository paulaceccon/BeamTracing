/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ray.cpp
 * Author: pceccon
 * 
 * Created on October 22, 2015, 10:05 AM
 */

#include "Ray.h"

Ray::Ray() 
{
}


Ray::Ray(core::Pointf& o, core::Vectorf& d)
{
    _origin = o;
    _direction = d;
}


Ray::Ray(const Ray& r) 
{
    _origin = r.getOrigin();
    _direction = r.getDirection();
}


Ray::~Ray() 
{
}


const core::Pointf Ray::getOrigin() const
{
    return _origin;
}


const core::Vectorf Ray::getDirection() const
{
    return _direction;
}

