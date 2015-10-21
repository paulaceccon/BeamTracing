/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Receiver.h
 * Author: paulaceccon
 *
 * Created on October 21, 2015, 3:56 PM
 */

#ifndef RECEIVER_H
#define RECEIVER_H

#include "Room.h"

class Receiver 
{    
     public:
        
        /// Constructors ///
        
        /**
         * Default constructor.
         * 
         * Instantiates the points of a line as zero.
         */
        Receiver();
        
        /**
         * Instantiates a source inside a specific room.
         * 
         * @param r A room in which the source is located.
         */
        Receiver(const Room r);
        
        /**
         * Copy constructor.
         */
        Receiver(const Receiver& s);
        
        /**
         * Destructor.
         */
        virtual ~Receiver();
        
        
        
        /// Methods ///
        
        Room getInsideRoom();
        
    private:
        
        Room _insideRoom;
};

#endif /* RECEIVER_H */

