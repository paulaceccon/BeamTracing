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
#include "Vector.h"

#include <vector>
#include <map>

template<typename T> class Polygon 
{
    public:
        std::vector<Point<T>> vertices;
        
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
        Polygon()
        {
        }
                
        /**
         * Instantiates a point with x, y, z coordinates.
         * 
         * @param x X-coordinate.
         * @param y Y-coordinate.
         * @param z Z-coordinate.
         */
        Polygon(const std::vector<Point<T>> v, const std::vector<Line> e)
        {
            vertices = v;
        }

        /**
         * Copy constructor.
         */
        Polygon(const Polygon& p)
        {
            vertices = p.vertices;
        }
        
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
        bool polygonIsSimple (Point<T>& p)
        {
            std::vector<Line<T>> lines;
            for (unsigned int i = 0; i < vertices.size(); i+=2) 
            {
                if (i == vertices.size() - 1) 
                    lines.push_back(Line(vertices.at(i)), Line(vertices.at(0)));
                else 
                    lines.push_back(Line(vertices.at(i)), Line(vertices.at(i+1)));
            }

            bool hasInnerIntersection = false;
            for (unsigned int i = 0; i < lines.size(); i++) 
            {
                for (unsigned int j = i + 1; j < lines.size(); j++) 
                {
                    hasInnerIntersection = Line.pointOfIntersection(lines.at(i), lines.at(j), p);
                    if (hasInnerIntersection) 
                        break;
                }
                if (hasInnerIntersection) 
                    break;
            }
            return hasInnerIntersection;
        }
        
        /**
         * Return the point position in relation to the polygon.
         * @param p A 2-dimensional point.
         * @return  INSIDE, if @p is inside the polygon, OUTSIDE, if @p is outside
         * the polygon, or ON, if @p in on and edge of the polygon.
         */
        PointPosition Polygon::LocatePointUsingRotationIndex(const Point<T>& p)
        {
            double rotationIndex = 0;

            for (unsigned int i = 0; i < vertices.size(); i++) 
            {
                Point p1 = vertices.at(i);

                Point p2;
                if (i == vertices.size() - 1) ? p2 = vertices.at[0] : p2 = vertices.at(i + 1);

                Vector v1(p, p1);
                Vector v2(p, p2);

                rotationIndex += v2.orientedAngle(v1);
            }

            rotationIndex /= 2 * M_PI;
            rotationIndex = round(rotationIndex);

            if (rotationIndex <= float(1e-7)) return OUTSIDE;
            else return INSIDE;
        }
        
        void GrahamConvexHull(Polygon<T> &ch)
        {
            int lowestYcoord = 0;

            for (unsigned int i = 0; i < vertices.size(); i++) 
                lowestYcoord = vertices.at(i).y > vertices.at(lowestYcoord).y ? i : lowestYcoord;

            std::map<float, int> orientedAngle = new std::map<>();
            for (unsigned int i = 0; i < vertices.size(); i++) 
            {
                if (i != lowestYcoord) {
                    Point p1 = vertices.at(lowestYcoord);
                    Point p2 = vertices.at(i);

                    Vector v1(p2, p1);
                    Vector v2(Point(INFINITY, 0), Point(0, 0));
                    orientedAngle.insert(v2.orientedAngle(v1), i);
                }
            }

            std::vector<int> orientedAngleIndex;
            orientedAngleIndex.push_back(lowestYcoord);

            std::map<float, int>::iterator it;
            for (it = orientedAngle.begin(); it != orientedAngle.end(); it++)
            {
                orientedAngleIndex.push_back(it->second);
            }

            ch.vertices.push_back(vertices.at(orientedAngleIndex.at(0)));
            ch.vertices.push_back(vertices.at(orientedAngleIndex.at(1)));
            ch.vertices.push_back(vertices.at(orientedAngleIndex.at(2)));

            Polygon points;
            unsigned int M = ch.vertices.size();
            for (int i = 3; i < orientedAngleIndex.size() + 1; i++) 
            {
                while (M > 2) 
                {
                    points.vertices.clear();
                    points.vertices.push_back(ch.vertices.at(M - 3));
                    points.vertices.push_back(ch.vertices.at(M - 2));
                    points.vertices.push_back(ch.vertices.at(M - 1));
                    if (!isCounterClockWise(points)) 
                    {
                        ch.vertices.erase(M - 2);
                        M--;
                    } 
                    else 
                    {
                        break;
                    }
                }

                if (i != orientedAngleIndex.size()) 
                {
                    ch.vertices.push_back(vertices.at(orientedAngleIndex.at(i)));
                    M++;
                } 
                else 
                {
                    while (M > 2) 
                    {
                        points.vertices.clear();
                        points.vertices.push_back(ch.vertices.at(M - 3));
                        points.vertices.push_back(ch.vertices.at(M - 2));
                        points.vertices.push_back(ch.vertices.at(M - 1));
                        if (!isCounterClockWise(points)) 
                        {
                            ch.vertices.erase(M - 2);
                            M--;
                        } 
                        else 
                        {
                            break;
                        }
                    }
                }
            }
        }
        
        bool isCounterClockWise(const Polygon<T>& p)
        {
            double crossProduct = 0;

            Point p1 = p.vertices.at(0);
            Point p2 = p.vertices.at(1);

            Vector v1(p2.x-p1.x, p2.y-p1.y);
            for (int i = 1; i < p.vertices.size() - 1; i++) 
            {
                p1 = p.vertices.at(i);

                if (i == p.vertices.size() - 1)  p2 = p.vertices.at(0);
                else p2 = p.vertices.at(i + 1);

                Vector v2(p2.x-p1.x, p2.y-p1.y);
                crossProduct += v1.orientedArea(v2);
                v1 = v2;
            }

            return crossProduct > 0;
        }
    
    private:
};

#endif /* POLYGON_H */

