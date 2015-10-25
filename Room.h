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
         * @param w  A set of walls that defines a room.
         * @param id The room id.
         */
        Room(const std::vector<int> w, const std::vector<int> ori, const int id);
        
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
        
        const std::vector<int>& getWallOrs() const;
        
        /**
         * Gets a wall orientation.
         * 
         * @param i The wall id.
         * 
         * @return @_wallsOr[i]. 
         */
        const int getWallOr(const int i) const;
        
        /**
         * Adds a wall to @this room.
         * 
         * @param w The wall to be added to @this.
         */
        void addWall(const int w, const int o);
        
        /**
         * Gets the room id.
         * 
         * @return @_id;
         */
        const int getRoomIdx() const;
        
        /**
         * Sets the room id.
         */
        void setIdx(const int id);
    
    private:
        
       std::vector<int> _wallsIdx; 
       std::vector<int> _wallsOr; 
       
       int _id;

};

#endif /* ROOM_H */

