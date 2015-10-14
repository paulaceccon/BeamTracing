/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Polygon.h
 * Author: pceccon
 *
 * Created on October 14, 2015, 2:34 PM
 */

#ifndef POLYGON_H
#define POLYGON_H

#include "Point.h"
#include "Line.h"

#include <vector>

class Polygon 
{
    public:
        std::vector<Point> vertices;
        
        enum PointPosition 
        {
            INSIDE, 
            OUTSIDE, 
            ON
        };
        
        
        
        /// Constructors ///
        
        /**
         * Default constructor.
         * 
         * Instantiates a the points of a line as zero.
         */
        Polygon();
        
        /**
         * Instantiates a point with x, y, z coordinates.
         * 
         * @param x X-coordinate.
         * @param y Y-coordinate.
         * @param z Z-coordinate.
         */
        Polygon(const std::vector<Point> v, const std::vector<Line> e);

        /**
         * Copy constructor.
         */
        Polygon(const Polygon& p);
        
        /**
         * Destructor.
         */
        virtual ~Polygon();
        
        
        
        /// Methods ///
        
        /**
         * Verifies if the polygon is simple.
         * @param p A 2-dimensional point.
         * @return  True if an intersection between any pair of edges that defines
         * a polygon is found. False, otherwise.
         */
        bool polygonIsSimple (Point& p);
        
        /**
         * Return the point position in relation to the polygon.
         * @param p A 2-dimensional point.
         * @return  INSIDE, if @p is inside the polygon, OUTSIDE, if @p is outside
         * the polygon, or ON, if @p in on and edge of the polygon.
         */
        PointPosition Polygon::LocatePointUsingRotationIndex(const Point& p);
        
        void GrahamConvexHull();
        
        bool isCounterClockWise(const std::vector<Point> v);
    
    private:
};

#endif /* POLYGON_H */

