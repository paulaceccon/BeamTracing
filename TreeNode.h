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
#include "Source.h"
#include "Line.h"

#include <vector>

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
        TreeNode(const int fromRoom, const int toRoom, const int trhoughWall, 
            const core::Pointf& ns, const core::Pointf& p1, const core::Pointf& p2);
        
        /**
         * Copy constructor.
         */
        TreeNode(const TreeNode& n);
        
        /**
         * Destructor.
         */
        virtual ~TreeNode();
        
        /**
         * Add a new child to @this node.
         * 
         * @param child The child to be added.
         */
        void addChild(TreeNode& child);
        
        /**
         * Gets the children of @this node.
         * 
         * @return @children.
         */
        const std::vector<TreeNode>& getChildren() const;
        
        TreeNode& getChild(int i);
        
        const int getInsideRoom() const;
        
        const int getToRoom() const;
        
        const int getThroughWall() const;
        
        const core::Pointf& getSourcePosition() const;
        
        const core::Pointf& getPoint(int i) const;
    
    private:
        
        std::vector<TreeNode> _children;
        
        int _fromRoom;
        int _toRoom;
        
        int _trhoughWall;
        
        core::Pointf _sourcePosition;
        
        core::Pointf _p1, _p2;
};

#endif /* TREENODE_H */

