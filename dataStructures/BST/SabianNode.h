/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SabianNode.h
 * Author: katekiguru
 *
 * Created on May 6, 2021, 7:02 PM
 */

#ifndef SABIANNODE_H
#define SABIANNODE_H

template <class T>
struct SabianNode {
    T data;
    SabianNode *left, *right;
};

#endif /* SABIANNODE_H */

