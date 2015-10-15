/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Point.h
 * Author: pceccon
 *
 * Created on October 14, 2015, 12:40 PM
 */

#ifndef POINT_H
#define POINT_H

#include <cstdlib>

template<typename T> class Point
{
    public:

        T x; /**< X coordinate. */
        T y; /**< Y coordinate. */



        /// Constant points ///

        static const Point ZERO;   /**< Zero vector (0, 0, 0). */

        
        
        /// Constructors ///

        /**
         * Default constructor.
         * 
         * Instantiates a zero point.
         */
        Point() : x( T(0.0) ), y( T(0.0) )
        {
        }

        /**
         * Instantiates a point with x, y, z coordinates.
         * 
         * @param x X-coordinate.
         * @param y Y-coordinate.
         */
        Point(const T x, const T y) : x(x), y(y)
        {
        }

        /**
         * Copy constructor.
         */
        Point(const Point& p) : x(p.x), y(p.y)
        {
        }



        /// Methods ///



        /// Operators ///

        /**
         * Multiplication by a scalar (p * s).
         * 
         * @param s A scalar value.
         * @return  A translated point.
         */
        Point operator * (const T s) const
        {
            return Point(x * s, y * s);
        }

        /**
         * Multiplication by a scalar (p = p * s).
         * 
         * @param s A scalar value.
         * @return  @this translated.
         */
        Point& operator *= (const T s)
        {
            x *= s;
            y *= s;

            return *this;
        }

        /**
         * Point comparison.
         * 
         * @param p A 2-dimensional point.
         * @return  True if @this and @p have the same coordinates based on a EPSILON
         * error. Otherwise, return false.
         */
        bool operator == ( const Point& p ) const
        {
            return (std::abs(x - p.x) < T(1e-7) && std::abs(y - p.y) < T(1e-7));
        }

        /**
         * Point comparison.
         * 
         * @param p A 2-dimensional point.
         * @return  False if @this and @p have the same coordinates based on a EPSILON
         * error. Otherwise, return true.
         */
        bool operator != ( const Point& p ) const
        {
            return (std::abs(x - p.x) > T(1e-7) || std::abs(y - p.y) > T(1e-7));
        }
};

#endif /* POINT_H */

