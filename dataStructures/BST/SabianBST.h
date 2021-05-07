/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SabianBST.h
 * Author: katekiguru
 *
 * Created on May 6, 2021, 7:04 PM
 */

#ifndef SABIANBST_H
#define SABIANBST_H

#include "SabianNode.h"
#include "../../SabianConfig.h"
#include <iostream>

template <class T>

class SabianBST {
public:

    /**
     * Initalizes the tree
     */
    SabianBST() {
        this->rootNode = NULL;
    }

    /**
     * Inserts a new item to the tree
     * @param value
     */
    void insert(T value) {
        /*
         * Start with the root node
         */
        if (this->rootNode != NULL) {
            this->insert(this->rootNode, value);
        } else {
            /*
             Assign the root node to a new value
             */
            this->rootNode = new SabianNode<T>();
            this->rootNode->data = value;

            /*
              Always assign empty node to the next node for future reference
             */
            this->rootNode->left = NULL;

            /*
              Always assign empty node to the next node for future reference
             */
            this->rootNode->right = NULL;
        }
    }

    /**
     * Searches an item in the list
     * @param item
     * @return 
     */
    bool search(T item) {
        return this->search(this->rootNode, item);
    }

    /**
     * Traverses through the tree
     * @param type
     */
    void traverse(SABIAN_STRING type) {
        if (this->rootNode != NULL) {
            this->traverse(this->rootNode, type);
        }
    }

private:
    SabianNode<T> * rootNode;

    /**
     * Inserts a new node and item to the tree
     * @param node
     * @param item
     */
    void insert(SabianNode<T>* node, T item) {
        /*
         * Start with the left tree
         */
        if (item < node->data) {

            /*
             * Check if left node is taken then proceed with next node insertion
             */
            if (node->left != NULL) {
                this->insert(node->left, item);
            } else {
                /*
                 Create a new node and assign it to the new value if the node position is free
                 */
                node->left = new SabianNode<T>();
                node->left->data = item;

                /*
                 Always assign empty node to the next node for future reference
                 */
                node->left->right = NULL;

                /*
                 Always assign empty node to the next node for future reference
                 */
                node->left->left = NULL;
            }
        }/*
     * Proceed with the right node
     */
        else if (item >= node->data) {

            /*
             * Check if right node is taken then proceed with next node insertion
             */
            if (node->right != NULL) {
                this->insert(node->right, item);
            } else {
                /*
                Create a new node and assing it to the new value if the node position is free
                 */
                node->right = new SabianNode<T>();
                node->right->data = item;

                /*
                 Always assign empty node to the next node for future reference
                 */
                node->right->right = NULL;

                /*
                 Always assign empty node to the next node for future reference
                 */
                node->right->left = NULL;
            }
        }
    }

    /**
     * Searches in the BST
     * @param root
     * @param item
     * @return 
     */
    bool search(SabianNode<T> * root, T item) {
        /*
         * If the node is non existent, return false
         */
        if (root == NULL) {
            return false;
        }

        /*
         * If the root node has the data, return true
         */
        if (root->data == item) {
            return true;
        }

        bool exists = false;


        if (item < root->data) {
            /*
             * Search on the left side if data is less than the item
             */
            exists = search(root->left, item);

        } else if (item >= root->data) {
            /*
             * Search on the right side if data is greater than the item
             */
            exists = search(root->right, item);

        }

        return exists;
    }

    /**
     * Traverses through the tree
     * @param root
     * @param type
     */
    void traverse(SabianNode<T> * root, SABIAN_STRING type) {
        if (type == "preOrder") {
            this->preOrderTraverse(root);
        } else if (type == "postOrder") {
            this->postOrderTraverse(root);
        } else if (type == "inOrder") {
            this->inOrderTraverse(root);
        } else {
            std::cout << "No traversal method found for " << type;
        }
    }

    /**
     * Pre order traverser
     * @param root
     */
    void preOrderTraverse(SabianNode<T> * root) {
        if (root != NULL) {
            std::cout << root->data << std::endl;
            this->preOrderTraverse(root->left);
            this->preOrderTraverse(root->right);
        }
    }

    /**
     * Post order traverser
     * @param root
     */
    void postOrderTraverse(SabianNode<T> * root) {
        if (root != NULL) {
            this->postOrderTraverse(root->left);
            this->postOrderTraverse(root->right);
            std::cout << root->data << std::endl;
        }
    }

    /**
     * In order traverser
     * @param root
     */
    void inOrderTraverse(SabianNode<T> * root) {
        if (root != NULL) {
            this->inOrderTraverse(root->left);
            std::cout << root->data << std::endl;
            this->inOrderTraverse(root->right);
        }
    }

};

#endif /* SABIANBST_H */

