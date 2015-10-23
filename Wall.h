/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Wall.h
 * Author: pceccon
 *
 * Created on October 15, 2015, 12:26 PM
 */

#ifndef WALL_H
#define WALL_H

#include "Line.h"

class Wall 
{
    public:
        
        /// Constructors ///
        
        /**
         * Default constructor.
         */
        Wall();
        
        /**
         * Instantiates a wall with specifics start/end points and a 
         * default specular value.
         * 
         * @param sI The first point index.
         * @param sE The second point index.
         * @param s  The specular value.
         */
        Wall(const int sI, const int eI, const float s);
        
        /**
         * Copy constructor.
         */
        Wall(const Wall& w);
        
        /**
         * Destructor.
         */
        virtual ~Wall();
        
        
        
        /// Methods ///
        
        /**
         * Gets the start point that defines a wall.
         * 
         * @return @_startPointIdx.
         */
        const int getStartPoingID() const;
        
        /**
         * Gets the end point that defines a wall.
         * 
         * @return @_endPointIdx.
         */
        const int getEndPointID() const;
        
        /**
         * Gets the specular value of a wall.
         * 
         * @return @_specularity.
         */
        const float getSpecularValue() const;
        
        /**
         */
        
    private:
        
        float _specularity;
        
        int _startPointIdx;
        int _endPointIdx;

};

#endif /* WALL_H */

