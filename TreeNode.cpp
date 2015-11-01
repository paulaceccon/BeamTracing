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


TreeNode::TreeNode(const int currentRoom, const int wall, const core::Pointf& ns, 
        const core::Pointf& p1, const core::Pointf& p2)
{
    _currentRoom = currentRoom;
    
    _wall = wall;
    
    _sourcePosition = ns;
    
    _p1 = p1;
    _p2 = p2;
}

TreeNode::TreeNode(const TreeNode& n) 
{
    _currentRoom = n._currentRoom;
    
    _wall = n._wall;
    
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


TreeNode& TreeNode::getLastAddedChild()
{
    return _children.back();
}


const int TreeNode::getInsideRoom() const
{
    return _currentRoom;
}


const int TreeNode::getToRoom() const 
{
    return _currentRoom;
}


const int TreeNode::getThroughWall() const
{
    return _wall;
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


void TreeNode::setPoint(int i, const core::Pointf& p)
{
    if (i == 1)
        _p1 = p;
    else
        _p2 = p;
}

