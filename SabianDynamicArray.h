/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SabianDynamicArray.h
 * Author: bryosabian <https://github.com/bryosabian>
 *
 * Created on May 13, 2021, 7:47 PM
 */

#ifndef SABIANDYNAMICARRAY_H
#define SABIANDYNAMICARRAY_H

template <class T>
class SabianDynamicArray {
protected:

    /**
     * The array
     */
    T* collection;

    /**
     * Resize the class
     */
    void resize(int oldSize, int newSize) {

        //Initialize the new collection that will be copied to and have enough space for our new element
        T* copyCollection = new T[newSize];

        //Copy the previous collection content to the new content
        memcpy(copyCollection, this->collection, oldSize * sizeof (T));

        //Clear the old collection from memory
        delete this->collection;

        //Assign the old collection to the new one
        this->collection = copyCollection;
    }

    /**
     * Removes the element in the index from the collection
     * @param index
     */
    void unset(int index, int size) {
        for (int j = index; j < size; j++)
            this->collection[j] = this->collection[j + 1];
    }

};

#endif /* SABIANDYNAMICARRAY_H */

