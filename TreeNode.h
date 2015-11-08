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
        TreeNode(const int fromRoom, const int trhoughWall, 
            const core::Pointf& ns, const core::Pointf& p1, const core::Pointf& p2);
        
        /**
         * Destructor.
         */
        virtual ~TreeNode();
        
        /**
         * Add a new child to @this node.
         * 
         * @param child The child to be added.
         */
        void addChild(TreeNode* child);
        
        /**
         * Gets the children of @this node.
         * 
         * @return @children.
         */
        const std::vector<TreeNode*>& getChildren() const;
        
        /**
         * Gets the i-th child of the tree.
         * 
         * @param  Index of the child to be returned.
         * @return The i-th child of the tree.
         */
        TreeNode* getChild(int i);
        
        /**
         * Gets the last added child of the tree.
         * 
         * @return @_children.back()
         */
        TreeNode* getLastAddedChild();
        
        /**
         * Gets the index of the room in which the node is inside.
         * 
         * @return @_currentRoom.
         */
        const int getInsideRoom() const;
        
        /**
         * Gets the index of the last traversed wall.
         * 
         * @return @_wall.
         */
        const int getThroughWall() const;
        
        /**
         * Gets the current (abstract) source position.
         * 
         * @return @_sourcePosition.
         */
        const core::Pointf& getSourcePosition() const;
        
        /**
         * Gets the i (in 1, 2) point that defines the beam.
         * 
         * @param i The index of the point to be returned.
         * @return  @_p1 or @_p2, based on i.
         */
        const core::Pointf& getPoint(int i) const;
        
        /**
         * Sets the i (in 1, 2) point that defines the beam.
         * 
         * @param i The index of the point to be set.
         * @param p A reference to a point.
         */
        void setPoint(int i, const core::Pointf& p);
        
    private:
        
        // Memory alignment
        int _currentRoom; // 4 bytes
        
        int _wall;
        
        core::Pointf _sourcePosition; // 4 bytes
        
        core::Pointf _p1, _p2;
        
        std::vector<TreeNode*> _children; // 8 bytes
};

#endif /* TREENODE_H */

