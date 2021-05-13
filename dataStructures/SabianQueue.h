/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SabianQueue.h
 * Author: bryosabian <https://github.com/bryosabian>
 *
 * Created on May 13, 2021, 7:35 PM
 */

#ifndef SABIANQUEUE_H
#define SABIANQUEUE_H

#include <string.h>

#include "../SabianConfig.h"
#include "../SabianException.h"
#include "../SabianDynamicArray.h"
#include <iostream>

template <class T>
class SabianQueue : protected SabianDynamicArray<T> {
private:
    static const int INITIAL_SIZE = 2;
    int start;
    int end;
    int capacity;
    bool alwaysPopItemsFromMemory = true;

    /**
     * Resize the class
     */
    void resize() {

        //Don't resize if stack is empty
        if (isEmpty()) {
            return;
        }
        int originalSize = getSize();

        //Don't resize if we haven't reached the maximum
        if (originalSize < INITIAL_SIZE) {
            return;
        }

        //Change the new capacity by one
        int newSize = ++capacity;

        //Resize our collection
        SabianDynamicArray<T>::resize(originalSize, newSize);
    }


public:

    SabianQueue() {
        this->start = 0;
        this->end = -1;
        this->capacity = INITIAL_SIZE;
        this->collection = new T[INITIAL_SIZE];
    }

    ~SabianQueue() {
        delete this->collection;
    }

    /**
     * Adds new item to the end of the queue
     */
    void enqueue(T item) {

        this->resize();

        if (isFull()) {
            throw SabianException("Trying to add an element to an already full queue");
        }

        // Add to the rear of the queue while increasing the index
        this->collection[++end] = item;

    }

    /**
     * Removes the first element from the queue and returns it
     * @return 
     */
    T dequeue() {

        if (isEmpty()) {
            throw SabianException("Trying to remove an element to an empty queue");
        }

        T removedValue = this->collection[start];

        //Delete it from memory as well if need be
        if (alwaysPopItemsFromMemory) {
            int size = getSize();
            SabianDynamicArray<T>::unset(start, size);
        } else {
            //Increase the front index by one for future reference. Only do this if there's no change in the memory
            start++;
        }

        //Reduce the end by one
        end--;

        //Returns the removed value
        return removedValue;

    }

    /**
     * Accesses the first element in the queue
     * @return 
     */
    T peek() {
        if (isEmpty()) {
            throw SabianException("Trying to access an empty queue");
        }
        return this->collection[start];
    }

    /**
     * Whether the queue is empty
     * @return 
     */
    bool isEmpty() {
        return end == -1;
    }

    /**
     * Whether the queue is full
     * @return 
     */
    bool isFull() {
        return getSize() == capacity;
    }

    /**
     * Gets the size of the queue
     * @return 
     */
    int getSize() {
        return end + 1;
    }

    /**
     * Prints the queued elements
     */
    void print() {
        if (isEmpty()) {
            std::cout << "No element found" << std::endl;
        } else {
            for (int i = start; i < getSize(); i++) {
                std::cout << this->collection[i] << std::endl;
            }
        }
    }

};

#endif /* SABIANQUEUE_H */

