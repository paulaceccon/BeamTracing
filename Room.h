/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Room.h
 * Author: pceccon
 *
 * Created on October 15, 2015, 12:35 PM
 */

#ifndef ROOM_H
#define ROOM_H

#include "Room.h"

#include <vector>

class Room 
{
    public:
        
        /// Constructors ///
        
        /**
         * Default constructor.
         * 
         * Instantiates the points of a line as zero.
         */
        Room();
        
        /**
         * Instantiates a room with specifics walls.
         * 
         * @param w A set of walls that defines a room.
         */
        Room(const std::vector<int> w);
        
        /**
         * Copy constructor.
         */
        Room(const Room& r);
        
        /**
         * Destructor.
         */
        virtual ~Room();
        
        
        
        /// Methods ///
        
        /**
         * Gets the set of walls that define a room.
         * 
         * @return @_walls. 
         */
        const std::vector<int>& getWallsIdx() const;
        
        /**
         * Adds a wall to @this room.
         * 
         * @param w The wall to be added to @this.
         */
        void addWallIdx(const int w);
    
    private:
        
       std::vector<int> _wallsIdx; 

};

#endif /* ROOM_H */

