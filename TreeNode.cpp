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

TreeNode::TreeNode() 
{
}


TreeNode::TreeNode(int fromRoom, int toRoom, int trhoughWall, core::Pointf reflectedSource)
{
    _fromRoom = fromRoom;
    _toRoom = toRoom;
    
    _trhoughWall = trhoughWall;
    
    _source = reflectedSource;
}

TreeNode::TreeNode(const TreeNode& n) 
{
    _fromRoom = n._fromRoom;
    _toRoom = n._toRoom;
    
    _trhoughWall = n._trhoughWall;
    
    _children = n._children;
    
    _source = n._source;
}


TreeNode::~TreeNode() 
{
}


void TreeNode::addChild(TreeNode& child)
{
    _children.push_back(child);
}


const std::vector<TreeNode> TreeNode::getChildren() const
{
    return _children;
}


const int TreeNode::getInsideRoom() const
{
    return _fromRoom;
}


const core::Pointf& TreeNode::getSourcePosition() const
{
    return _source;
}

