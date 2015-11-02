/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MathUtils.h
 * Author: pceccon
 *
 * Created on October 29, 2015, 11:01 AM
 */

#ifndef MATHUTILS_H
#define MATHUTILS_H

#include "Core.h"

class MathUtils 
{
    
    public:

        /**
        * Finds the line equation (@a x + @b y + @c) 
        * given to points, @pa and @pb, on that line.
        * 
        * @param pa First point on the line  (start point).
        * @param pb Second point on the line (end point).
        * @param a  Value @a that defines the equation of a line. 
        * @param b  Value @b that defines the equation of a line.
        * @param c  Value @c that defines the equation of a line.
        */
       static void lineEquation(const core::Pointf& pa, const core::Pointf& pb, float& a, float& b, float& c);
       
       /**
        * Defines the point of intersection between two lines, if it exists.
        * 
        * @param p1a First point on the first line.
        * @param p2a First point on the second line. 
        * @param p1b Second point on the first line.
        * @param p2b Second point on the second line.
        * @param out A reference for the point of intersection to be written.
        */
       static void pointOfIntersection(const core::Pointf& p1a, const core::Pointf& p2a,
        const core::Pointf& p1b, const core::Pointf& p2b, core::Pointf& out);
       
       /**
        * Defines if given point is in a line segment or not.
        * 
        * @param p1a The first point that defines the line segment.
        * @param p1b The second point that defines the line segment.
        * @param p   The point to be checked.
        * @return    True, if @p is in the line segment. False, otherwise.
        */
       static int pointInSegment(const core::Pointf& p1a, const core::Pointf& p1b, const core::Pointf& p);

};

#endif /* MATHUTILS_H */

