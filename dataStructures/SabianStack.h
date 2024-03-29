/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SabianStack.h
 * Author: bryosabian
 *
 * Created on May 11, 2021, 8:17 PM
 */

#ifndef SABIANSTACK_H
#define SABIANSTACK_H

#include "../SabianConfig.h"
#include "../SabianException.h"
#include <iostream>
#include "../SabianDynamicArray.h"

template <class T>
class SabianStack : protected SabianDynamicArray<T> {
private:

    static const int INITIAL_SIZE = 2;
    int topIndex;
    int capacity;
    bool alwaysPopItemsFromMemory = true;

    /**
     * Resizes the collection to new size
     */
    void resize() {

        //Don't resize if stack is empty
        if (isEmpty()) {
            return;
        }


        //Get the original size
        int originalSize = this->getSize();

        //Don't resize if we haven't reached the maximum
        if (originalSize < INITIAL_SIZE) {
            return;
        }

        //Initialize the new size
        int newSize = ++capacity;

        //Resize the array
        SabianDynamicArray<T>::resize(originalSize, newSize);
    }

public:

    /**
     * Initializes the stack
     */
    SabianStack() {
        topIndex = -1;
        capacity = INITIAL_SIZE;
        this->collection = new T[capacity];
    }

    /**
     * Free everything up
     */
    virtual ~SabianStack() {
        delete this->collection;
    }

    /**
     * Pushes a new item to the stack
     * @param value
     */
    void push(T value) {

        //Resize the stack if need be to accommodate the new element(s)
        this->resize();

        //Don't add if stack is full
        if (isFull())
            throw SabianException("Trying to push to an already full stack");

        //Add new item while replacing the top element
        this->collection[++topIndex] = value;
    }

    /**
     * Removes an item from the top and returns the removed item
     * @return T
     */
    T pop() {

        //Don't remove from empty stack
        if (isEmpty()) {
            throw SabianException("Trying to access an empty stack");
        }
        //Return the item to be popped
        T value = this->collection[topIndex];

        //Delete it from memory as well if need be
        if (alwaysPopItemsFromMemory) {
            int size = getSize();
            SabianDynamicArray<T>::unset(topIndex, size);
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
            throw SabianException("Trying to access an empty stack");
        }
        return this->collection[topIndex];
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
                std::cout << this->collection[i] << std::endl;
            }
        }
    }



};


#endif /* SABIANSTACK_H */

