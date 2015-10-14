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

template<typename T> class Point
    {
        public:

        T x; /**< X coordinate. */
        T y; /**< Y coordinate. */
        T z; /**< Z coordinate. */



        /// Constant points ///

        static const Point ZERO;   /**< Zero vector (0, 0, 0). */

        
        
        /// Constructors ///

        /**
         * Default constructor.
         * 
         * Instantiates a zero point.
         */
        Point() : x( T(0.0) ), y( T(0.0) ), z( T(0.0) )
        {
        }

        /**
         * Instantiates a vector with x, y, z coordinates.
         * 
         * @param x X-coordinate.
         * @param y Y-coordinate.
         * @param z Z-coordinate.
         */
        Point(const T x, const T y, const T z) : x(x), y(y), z(z)
        {
        }

        /**
         * Copy constructor.
         */
        Point(const Point& p) : x(p.x), y(p.y), z(p.z)
        {
        }



        /// Methods ///



        /// Operators ///

        /**
         * Multiplication by a scalar (p * s).
         * 
         * @param s A scalar value.
         * @return A translated point.
         */
        Point operator * (const T s) const
        {
            return Point(x * s, y * s, z * s);
        }

        /**
         * Multiplication by a scalar (p = p * s).
         * 
         * @param s A scalar value.
         * @return A translated point.
         */
        Point& operator *= (const T s)
        {
            x *= s;
            y *= s;
            z *= s;

            return *this;
        }

        /**
         * Point comparison.
         * 
         * @param p A 3-dimensional point.
         * @return True if @this and @p have the same coordinates based on a EPSILON
         * error. Otherwise, return false.
         */
        bool operator == ( const Point& p ) const
        {
            return (std::abs(x - p.x) T(1e-7) && std::abs(y - p.y) T(1e-7) &&
                    std::abs(z - p.z) T(1e-7));
        }

        /**
         * Point comparison.
         * 
         * @param p A 3-dimensional point.
         * @return False if @this and @p have the same coordinates based on a EPSILON
         * error. Otherwise, return true.
         */
        bool operator != ( const Point& p ) const
        {
            return (std::abs(x - p.x) > T(1e-7) || std::abs(y - p.y) > T(1e-7) ||
                    std::abs(z - p.z) > T(1e-7));
        }
    };

#endif /* POINT_H */

