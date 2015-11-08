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
#include "Core.h"

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
         * @param p The position of the source inside the room.
         */
        Source(const Room& r, const core::Pointf& p);
        
        /**
         * Copy constructor.
         */
        Source(const Source& s);
        
        /**
         * Destructor.
         */
        virtual ~Source();
        
        
        
        /// Methods ///
        
        /**
         * Gets in which room the source is located.
         * 
         * @return @_insideRoom. 
         */
        const Room& getInsideRoom() const;
        
        /**
         * Gets the coordinates of the source.
         * 
         * @return _position; 
         */
        const core::Pointf& getPosition() const;
        
    private:
        
        Room _insideRoom;
        
        core::Pointf _position;
};

#endif /* SOURCE_H */

