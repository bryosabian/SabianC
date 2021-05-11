/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SabianStack.h
 * Author: katekiguru
 *
 * Created on May 11, 2021, 8:17 PM
 */

#ifndef SABIANSTACK_H
#define SABIANSTACK_H

#include "../../SabianConfig.h"
#include <iostream>

template <class T>
class SabianStack {
private:

    static const int INITIAL_SIZE = 10;
    T* collection;
    int topIndex;
    int capacity;
    bool alwaysPopItemsFromMemory = false;

    /**
    Returns real size of the collection
     */
    int getRealSize() {
        int arrSize = sizeof (collection) / sizeof (collection[0]);
        return arrSize;
    }

public:

    /**
     * Initializes the stack
     */
    SabianStack(int initialSize) {
        topIndex = -1;
        capacity = initialSize;
        collection = new T[capacity];
    }

    /**
     * Pushes a new item to the stack
     * @param value
     */
    void push(T value) {

        //Don't add if stack is full
        if (isFull())
            throw "Trying to push to an already full stack";

        //Add new item while increasing the top index
        collection[++topIndex] = value;
    }

    /**
     * Removes an item from the top and returns the removed item
     * @return 
     */
    T pop() {
        
        //Don't remove from empty stack
        if (isEmpty()) {
            throw "Trying to access an empty stack";
        }
        //Return the item to be popped
        T value = collection[topIndex];

        //Delete it from memory as well if need be
        if (alwaysPopItemsFromMemory) {
            for (int j = topIndex; j < getRealSize(); j++)
                collection[j] = collection[j + 1];
        }

        //Reduce the top index by one
        topIndex--;

        //Return the popped item
        return value;
    }

    /**
     * Gets the first item in the stack
     * @return 
     */
    T peek() {
        if (isEmpty()) {
            throw "Trying to access an empty stack";
        }
        return collection[topIndex];
    }

    /**
     * Checks whether the stack is empty
     * @return 
     */
    bool isEmpty() {
        return topIndex == -1;
    }

    /**
     * Whether the stack is full
     * @return 
     */
    bool isFull() {
        return getSize() == this->capacity;
    }

    /**
     * Returns the size of the stack
     * @return 
     */
    int getSize() {
        return topIndex + 1;
    }

    /**
     * Prints the stack elements
     */
    void print() {
        if (isEmpty()) {
            std::cout << "No element found" << std::endl;
        } else {
            for (int i = topIndex; i >= 0; i--) {
                std::cout << collection[i] << std::endl;
            }
        }
    }

};


#endif /* SABIANSTACK_H */

