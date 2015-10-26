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


Tree::Tree(const Tree& orig) 
{
}


Tree::~Tree() 
{
}


void Tree::printTree(TreeNode root)
{
    if (root.getChildren().size() == 0)
    {
        printf( "Nil\n" );
        return;
    }
    std::cout << "In room " << root.getInsideRoom() << " to room " << root.getToRoom() << " through wall " << root.getThroughWall() << std::endl;
    std::vector<TreeNode> c = root.getChildren();
    for (unsigned int i = 0; i < c.size(); i++)
        printTree(c[i]);
}

