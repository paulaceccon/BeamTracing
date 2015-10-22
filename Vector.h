/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector.h
 * Author: pceccon
 *
 * Created on October 14, 2015, 3:00 PM
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

template<typename T> class Vector
{
    public:

        T x; /**< X coordinate. */
        T y; /**< Y coordinate. */



        /// Constructors ///

        /**
         * Default constructor.
         * 
         * Instantiates a zero vector.
         */
        Vector() : x( T(0.0) ), y( T(0.0) ) 
        {
        }

        /**
         * Instantiates a vector with x, y, z coordinates.
         * 
         * @param x X-coordinate.
         * @param y Y-coordinate.
         * @param z Z-coordinate.
         */
        Vector(const T x, const T y) : x(x), y(y)
        {
        }

        /**
         * Copy constructor.
         */
        Vector(const Vector& v) : x(v.x), y(v.y)
        {
        }



        /// Methods ///

        /**
         * Computes the magnitude of a vector (|v|).
         * 
         * @return A value representing the vector's magnitude.
         */
        T length() const
        {
            return std::sqrt(x * x + y * y);
        }

        /**
         * Computes the squared magnitude of a vector (|v|^2).
         * 
         * Squared magnitude is cheaper than magnitude because of there's no squared root calculation.
         * It's useful when comparing two lengths.
         * 
         * @return A value representing the vector's squared magnitude.
         */
        T slength() const
        {
            return x * x + y * y;
        }

        /**
         * Converts vector to unit vector.
         */
        void normalize()
        {
            if (std::abs(x) > T(1e-7) || std::abs(y) > T(1e-7))
            {
                T rLength = T(1.0) / std::sqrt(x * x + y * y);

                x *= rLength;
                y *= rLength;
            }
        }

        /**
         * Non-uniform vector scaling.
         * 
         * Uniform vector scaling is accomplished by operator* overload.
         * 
         * @param sX Scale factor in X axis.
         * @param sY Scale factor in Y axis.
         * @param sZ Scale factor in Z axis.
         */
        void scale(T sX, T sY, T sZ)
        {
            x *= sX;
            y *= sY;
        }

        /**
         * Computes the oriented area of a parallelogram which sides are @this
         * and @v.
         * 
         * This computation is like a cross product in a 2-dimensional vector in
         * which z-coordinate is zero. The result is a signed scalar representing
         * the "z" coordinate which actually is the area of a parallelogram build
         * by the two vectors. The sign of the area follows the right-hand rule
         * as the following example.
         * 
         * Example:
         * 
         * u = (1, 0)
         * v = (0, 1)
         * 
         * u X v = 1
         * v X u = -1
         * 
         * @param v A 2-dimensional vector.
         * @return  The oriented area value.
         */
        T orientedArea(const Vector& v) const
        {
            return (x * v.y - y * v.x);
        }

        /**
         * Project vector @v onto @this.
         * 
         * @param v A 2-dimensional vector.
         * @return  The projection of @v onto @this.
         */
        Vector project(const Vector& v) const
        {
            T f = (v.x * x + v.y * y) / (x * x + y * y);
            return Vector(f * x, f * y);
        }
        
        /**
         * Calculated the oriented angle between @this and @v.
         * @param v A 2-dimensional vector.
         * @return  The oriented angle between @this and @v.
         */
        float orientedAngle (Vector v) 
        {
            float angle = acos(this * v)/length(v) * length(this);
        
            if (this * v <= 0) return angle *-1;
            return angle;
        }



        /// Operators ///

        /**
         * Computes the dot product between @this and @v.
         * 
         * @param v A 2-dimensional vector.
         * @return  The dot product.
         */
        T operator * (const Vector& v) const
        {
            return x * v.x + y * v.y;
        }

        /**
         * Multiplication by a scalar (v * s).
         * 
         * @param s A scalar value.
         * @return  A scaled vector.
         */
        Vector operator * (const T s) const
        {
            return Vector(x * s, y * s);
        }

        /**
         * Multiplication by a scalar (s * v).
         * 
         * @param s A scalar value.
         * @param v A 2-dimensional vector to be scaled.
         * @return  A scaled @v.
         */
        friend Vector operator * (const T s, const Vector& v)
        {
            return Vector(v.x * s, v.y * s);
        }

        /**
         * Multiplication by a scalar (v = v * s).
         * 
         * @param s A scalar value.
         * @return  A scaled vector.
         */
        Vector& operator *= (const T s)
        {
            x *= s;
            y *= s;

            return *this;
        }

        /**
         * Division by a scalar (v / s).
         * 
         * @param s A scalar value
         * @return  A scaled vector.
         */
        Vector operator / (const T s) const
        {
            T rScalar = T(1.0) / s;

            return Vector(x * rScalar, y * rScalar);
        }

        /**
         * Division by a scalar (v = v / s).
         * 
         * @param s A scalar value
         * @return  A scaled vector.
         */
        Vector& operator /= (const T s)
        {
            T rScalar = T(1.0) / s;

            x *= rScalar;
            y *= rScalar;

            return *this;
        }

        /**
         * Vector addition (u + v).
         * 
         * @param v A 2-dimensional vector.
         * @return  The sum of @v and @this.
         */
        Vector operator + (const Vector& v) const
        {
            return Vector(x + v.x, y + v.y);
        }

        /**
         * Vector addition (u = u + v).
         * 
         * @param v A 2-dimensional vector.
         * @return  The sum of @v and @this.
         */
        Vector& operator += (const Vector& v)
        {
            x += v.x;
            y += v.y;

            return *this;
        }

        /**
         * Vector subtraction (u - v).
         * 
         * @param v A 2-dimensional vector.
         * @return  The subtraction of @this and @v.
         */
        Vector operator - (const Vector& v) const
        {
            return Vector(x - v.x, y - v.y);
        }

        /**
         * Vector subtraction (u = u - v).
         * 
         * @param v A 2-dimensional vector.
         * @return  The subtraction of @this and @v.
         */
        Vector& operator -= (const Vector& v)
        {
            x -= v.x;
            y -= v.y;

            return *this;
        }

        /**
         * Vector additive inverse (-v).
         * 
         * @return -@this.
         */
        Vector operator - () const
        {
            return Vector(-x, -y);
        }

        /**
         * Vector comparison.
         * 
         * @param v A 2-dimensional vector.
         * @return  True if @this and @v have the same coordinates based on a EPSILON
         * error. Otherwise, return false.
         */
        bool operator == ( const Vector& v ) const
        {
            return (std::abs(x - v.x) < T(1e-7) && std::abs(y - v.y) < T(1e-7));
        }

        /**
         * Vector comparison.
         * 
         * @param v A 2-dimensional vector.
         * @return  False if @this and @v have the same coordinates based on a EPSILON
         * error. Otherwise, return true.
         */
        bool operator != ( const Vector& v ) const
        {
            return (std::abs(x - v.x) > T(1e-7) || std::abs(y - v.y) > T(1e-7));
        }
};

#endif /* VECTOR_H */

