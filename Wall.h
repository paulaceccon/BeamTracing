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
         * @param l A line that defines the wall.
         * @param s The specular value.
         */
        Wall(const Line<float>& l, const float s);
        
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
         * Gets the line that define a wall.
         * 
         * @return @_wall.
         */
        Line<float> getLine() const;
        
        /**
         * Gets the specular value of a wall.
         * 
         * @return @_specularity.
         */
        float getSpecularValue() const;
        
    private:
        
        Line<float>  _line;
        float _specularity;

};

#endif /* WALL_H */

