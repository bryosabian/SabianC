/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SabianNode.h
 * Author: bryosabian
 *
 * Created on May 6, 2021, 7:02 PM
 */

#ifndef SABIANNODE_H
#define SABIANNODE_H

#include "../../SabianConfig.h"

template <class T>
struct SabianNode {
    T data;
    SabianNode *left, *right;

    ~SabianNode() {
        
        if (this->left != NULL)
            delete this->left;

        if (this->right != NULL)
            delete this->right;
    }
};

#endif /* SABIANNODE_H */

