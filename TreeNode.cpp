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


TreeNode::TreeNode(Room fromRoom, Room toRoom, Wall trhoughWall)
{
    _fromRoom = fromRoom;
    _toRoom = toRoom;
    
    _trhoughWall = trhoughWall;
    
    _left = 0;
    _rigth = 0;
}

TreeNode::TreeNode(const TreeNode& n) 
{
    _fromRoom = n._fromRoom;
    _toRoom = n._toRoom;
    
    _trhoughWall = n._trhoughWall;
    
    _left = n._left;
    _rigth = n._rigth;
}


TreeNode::~TreeNode() 
{
}

