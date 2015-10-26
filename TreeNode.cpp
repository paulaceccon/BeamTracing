/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TreeNode.cpp
 * Author: paulaceccon
 * 
 * Created on October 21, 2015, 4:12 PM
 */

#include "TreeNode.h"
#include "Tree.h"

TreeNode::TreeNode() 
{
}


TreeNode::TreeNode(const int fromRoom, const int toRoom, const int trhoughWall, const core::Pointf& ns, 
        const core::Pointf& p1, const core::Pointf& p2)
{
    _fromRoom = fromRoom;
    _toRoom = toRoom;
    
    _trhoughWall = trhoughWall;
    
    _sourcePosition = ns;
    
    _p1 = p1;
    _p2 = p2;
}

TreeNode::TreeNode(const TreeNode& n) 
{
    _fromRoom = n._fromRoom;
    _toRoom = n._toRoom;
    
    _trhoughWall = n._trhoughWall;
    
    _children = n._children;
    
    _sourcePosition = n._sourcePosition;
    
    _p1 = n._p1;
    _p2 = n._p2;
}


TreeNode::~TreeNode() 
{
}


void TreeNode::addChild(TreeNode& child)
{
    _children.push_back(child);
}


const std::vector<TreeNode>& TreeNode::getChildren() const
{
    return _children;
}


TreeNode& TreeNode::getChild(int i)
{
    return _children[i];
}


const int TreeNode::getInsideRoom() const
{
    return _fromRoom;
}


const int TreeNode::getToRoom() const 
{
    return _toRoom;
}


const int TreeNode::getThroughWall() const
{
    return _trhoughWall;
}


const core::Pointf& TreeNode::getSourcePosition() const
{
    return _sourcePosition;
}


const core::Pointf& TreeNode::getPoint(int i) const
{
    if (i == 1)
        return _p1;
    return _p2;
}

