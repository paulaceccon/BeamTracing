/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Line.h
 * Author: pceccon
 *
 * Created on October 14, 2015, 1:19 PM
 */

#ifndef LINE_H
#define LINE_H

#include "Point.h"

template<typename T> class Line 
{
    public:
        
        Point<T> startPoint;
        Point<T> endPoint;
        
        enum PointPosition 
        {
            LEFT, 
            RIGHT, 
            ON
        };
        
        
        
        /// Constructors ///
        
        /**
         * Default constructor.
         * 
         * Instantiates the points of a line as zero.
         */
        Line() : startPoint( Point() ), endPoint( Point() )
        {
        }
        
        /**
         * Instantiates a line with a specified end and start points.
         * 
         * @param s Start point of the line segment.
         * @param e End point of the line segment.
         */
        Line(const Point s, const Point e) : startPoint(s), endPoint(e)
        {
        }
        
        /**
         * Copy constructor.
         */
        Line(const Line& l) : startPoint(l.startPoint), endPoint(l.endPoint)
        {
        }
        
        
        
        /// Methods ///
        
        /**
         * Determines the a point position in relation to a line.
         * @param l The line reference.
         * @param p The point to be tested against the line.
         * @return  LEFT if @p is at the left of @l, RIGHT if @p is at the right 
         * of @l or ON if @p is on @l.
         */
        PointPosition pointLinePosition(const Line l, const Point p) 
        {
            float xs = l.startPoint.x, ys = l.startPoint.y;
            float xe = l.endPoint.x,   ye = l.endPoint.y;
            float xp = p.x,            yp = p.y;

            float det = (xe-xs) * (yp-ys) - (xp-xs) * (ye-ys);

            if (det > 0) return PointPosition.RIGHT;
            if (det < 0) return PointPosition.LEFT;
            else return PointPosition.ON;  
        }
        
        /**
         * Define the point of intersection between two lines, if it exists.
         * @param l1 The first line.
         * @param l2 The second line.
         * @param i  A reference for the point of intersection to be written, if
         * it exists.
         * @return   True, if @l1 and @l2 intersects. False, otherwise.
         */
        bool pointOfIntersection(const Line l1, const Line l2, Point& i) {
            float xl1s = l1.startPoint.x, yl1s = l1.startPoint.y;
            float xl1e = l1.endPoint.x,   yl1e = l1.endPoint.y;
            float xl2s = l2.startPoint.x, yl2s = l2.startPoint.y;
            float xl2e = l2.endPoint.x,   yl2e = l2.endPoint.y;
        
            float det = (xl1e-xl1s) * (yl2e-yl2s) - (yl1e-yl1s) * (xl2e-xl2s);      
        
            float s = ( (xl1e-xl1s) * (yl1s-yl2s) - (yl2e-yl1s) * (xl1s-xl2s) ) / det;
            float t = ( (yl1s-yl2s) * (xl2e-xl2s) - (xl1s-xl2s) * (yl2e-yl2s) ) / det;
           
            if (det != 0) 
                if (s > 0 && s < 1 && t > 0 && t < 1)
                {
                    i.x( xl1s + (t * (xl1e-xl1s)) );
                    i.y( yl1s + (t * (yl1e-yl1s)) );
                    return true;
                }
            return false;
        }
};

#endif /* LINE_H */

