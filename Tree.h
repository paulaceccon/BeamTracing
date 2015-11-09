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
        
        /// Constructors ///
        
        /**
         * Default constructor.
         * 
         * Instantiates the points of a line as zero.
         */
        Tree();

        /**
         * Destructor.
         */
        virtual ~Tree();

        /**
         * Prints the tree.
         * 
         * @param root  A pointer to the tree root.
         * @param depth The depth currently being printed.
         */
        void printTree(TreeNode* root, int depth);
        
        /**
         * Gets the number of leaves (paths).
         * 
         * @param root   A pointer to the tree root.
         * @param leaves A reference to the number of leaves to be written.
         */
        void getNumberOfLeaves(TreeNode* root, int& leaves);
        
        /**
         * Gets the maximum depth of a tree.
         * 
         * @param root  A pointer to the tree root.
         * @param depth A reference to the depth bo be written.
         */
        void getDepth(TreeNode* root, int& maxDepth, int currentDepth);
        
        TreeNode* _root;

    private:
    
};

#endif /* TREE_H */

