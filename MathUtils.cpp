/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MathUtils.cpp
 * Author: pceccon
 * 
 * Created on October 29, 2015, 11:01 AM
 */

#include "MathUtils.h"

void MathUtils::lineEquation(const core::Pointf& pa, const core::Pointf& pb, float& a, float& b, float& c)
{
    a = pa.y - pb.y;
    b = (pa.x - pb.x) * -1;
    c = pa.x * pb.y - (pa.y * pb.x); 
}

void MathUtils::pointOfIntersection(const core::Pointf& p1a, const core::Pointf& p2a,
       const core::Pointf& p1b, const core::Pointf& p2b, core::Pointf& out) 
{
    float a1 = p1a.y - p1b.y;
    float b1 = (p1a.x - p1b.x) * -1;
    float c1 = p1a.x * p1b.y - (p1a.y * p1b.x);
        
    float a2 = p2a.y - p2b.y;
    float b2 = (p2a.x - p2b.x) * -1;
    float c2 = p2a.x * p2b.y - (p2a.y * p2b.x);
        
    float u = b1 * c2 - (c1 * b2);
    float v = (a1 * c2 - (c1 * a2)) * -1;
    float w = a1 * b2 - (b1 * a2);
    
    if (w != 0)
    {
        out.x = u/w;
        out.y = v/w;
    }
}
