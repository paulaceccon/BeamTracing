/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.h
 * Author: paulaceccon
 *
 * Created on October 25, 2015, 3:38 PM
 */

#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"

class Tree 
{
    public:
        Tree();

        Tree(const Tree& o);

        virtual ~Tree();

        TreeNode root;
        
        void printTree(TreeNode root, int depth);

    private:
    
    

};

#endif /* TREE_H */

