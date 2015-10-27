/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.cpp
 * Author: paulaceccon
 * 
 * Created on October 25, 2015, 3:38 PM
 */

#include "Tree.h"

#include <iostream>
#include <vector>

Tree::Tree() 
{
}


Tree::Tree(const Tree& o) 
{
    root = o.root;
}


Tree::~Tree() 
{
}


void Tree::printTree(TreeNode root)
{
    std::cout << "In room " << root.getInsideRoom() << " through wall " << root.getThroughWall() << " with source at " << root.getSourcePosition().x << " "<< root.getSourcePosition().y 
            << " and p1: " << root.getPoint(1).x << " " << root.getPoint(1).y << " | p1: " << root.getPoint(2).x << " " << root.getPoint(2).y <<std::endl;
    std::vector<TreeNode> c = root.getChildren();
    for (unsigned int i = 0; i < c.size(); i++)
    {
        printTree(c[i]);
        std::cout << " << " << std::endl;
    }
    
}

