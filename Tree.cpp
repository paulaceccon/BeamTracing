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
#include "Environment.h"

#include <iostream>
#include <iomanip>
#include <vector>

Tree::Tree() 
{
    _root = NULL;
}


Tree::~Tree() 
{
}


void Tree::printTree(TreeNode* root, int depth)
{
    std::cout << std::setw(depth * 3) << " " << "|-- v"<< root->getInsideRoom() << " " << root->getThroughWall() << " s: " << root->getSourcePosition().x << ","<< root->getSourcePosition().y 
            << " p1: " << root->getPoint(1).x << "," << root->getPoint(1).y << " p2: " << root->getPoint(2).x << "," << root->getPoint(2).y << std::endl;
    std::vector<TreeNode*> c = root->getChildren();
    for (unsigned int i = 0; i < c.size(); i++)
    {
        printTree(c[i], depth+1);
    }
}



void Tree::getNumberOfLeaves(TreeNode* root, int& leaves)
{
    if (root->getChildren().size() == 0)
        leaves++;
    
    std::vector<TreeNode*> c = root->getChildren();
    for (unsigned int i = 0; i < c.size(); i++)
    {
        getNumberOfLeaves(c[i], leaves);
    }
}


void Tree::getDepth(TreeNode* root, int& maxDepth, int currentDepth)
{
    if (root->getChildren().size() == 0)
    {
        if (currentDepth > maxDepth)
            maxDepth = currentDepth;
    }
    
    std::vector<TreeNode*> c = root->getChildren();
    for (unsigned int i = 0; i < c.size(); i++)
    {
        getDepth(c[i], maxDepth, ++currentDepth);
    }
}



