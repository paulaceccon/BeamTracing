/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Source.h
 * Author: paulaceccon
 *
 * Created on October 21, 2015, 3:48 PM
 */

#ifndef SOURCE_H
#define SOURCE_H

#include "Room.h"

class Source 
{
    public:
        
        /// Constructors ///
        
        /**
         * Default constructor.
         * 
         * Instantiates the points of a line as zero.
         */
        Source();
        
        /**
         * Instantiates a source inside a specific room.
         * 
         * @param r A room in which the source is located.
         */
        Source(const Room r);
        
        /**
         * Copy constructor.
         */
        Source(const Source& s);
        
        /**
         * Destructor.
         */
        virtual ~Source();
        
        
        
        /// Methods ///
        
        Room getInsideRoom();
        
    private:
        
        Room _insideRoom;

};

#endif /* SOURCE_H */

