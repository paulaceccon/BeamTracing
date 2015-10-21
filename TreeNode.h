/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TreeNode.h
 * Author: paulaceccon
 *
 * Created on October 21, 2015, 4:12 PM
 */

#ifndef TREENODE_H
#define TREENODE_H

#include "Wall.h"
#include "Room.h"

class TreeNode 
{
    public:
        
        /// Constructors ///
        
        /**
         * Default constructor.
         * 
         * Instantiates the points of a line as zero.
         */
        TreeNode();
        
        /**
         * Instantiates a room with specifics walls.
         * 
         * @param w A set of walls that defines a room.
         */
        TreeNode(Room fromRoom, Room toRoom, Wall trhoughWall);
        
        /**
         * Copy constructor.
         */
        TreeNode(const TreeNode& n);
        
        /**
         * Destructor.
         */
        virtual ~TreeNode();
    
    private:
        
        TreeNode * _left;
        TreeNode * _rigth;
        
        Room _fromRoom;
        Room _toRoom;
        
        Wall _trhoughWall;
};

#endif /* TREENODE_H */

