/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: bryosabian
 *
 * Created on August 24, 2020, 8:24 PM
 */

#include "dataStructures/BST/SabianBST.h"
#include "dataStructures/SabianStack.h"
#include "SabianConfig.h"
#include "SabianUser.h"
#include "SabianException.h"
#include "dataStructures/SabianQueue.h"

using namespace std;

void bst() {
    SabianBST<int> tree = SabianBST<int>();
    tree.insert(100);
    tree.insert(200);
    tree.insert(900);
    tree.insert(600);
    tree.insert(500);
    tree.insert(400);
    tree.insert(800);
    tree.insert(1000);

    int x, y, z;

    bool proceedWithInteraction = false;
    SABIAN_STRING selected;
    cout << "Do you want to carry out operations> Y or N" << endl;
    cin >> selected;

    proceedWithInteraction = selected == "Y";


    if (proceedWithInteraction) {

        cout << "Enter 3 numbers to include in the tree" << endl;

        cin >> x >> y >> z;

        tree.insert(x);
        tree.insert(y);
        tree.insert(z);

        SABIAN_STRING type;

        cout << "Enter Traversal Type to use to list items in the tree (preOrder,postOrder,inOrder)" << endl;

        cin >> type;

        tree.traverse(type);

        int searchValue;

        cout << "Enter Search Value" << endl;

        cin >> searchValue;

        bool exists = tree.search(searchValue);
        if (exists) {
            cout << "The value " << to_string(searchValue) << " exists in the tree " << endl;
        } else {
            cout << "The value " << to_string(searchValue) << " does not exist in the tree " << endl;
        }
    }

    /**
     * Print the tree
     */
    cout << "Before invert " << endl;
    tree.print();

    /**
     * Invert the tree
     */
    tree.invert();
    cout << "After invert" << endl;
    tree.print();
}

void stack() {
    SabianStack<int> stack = SabianStack<int>();
    try {
        stack.push(100);
        stack.push(200);
        stack.push(900);
        stack.push(1200);
        stack.push(500);
        stack.print();

        cout << "The peak before pop is " << stack.peek() << endl;
        cout << "Size of collection is " << stack.getSize() << endl;

        cout << "Popping " << stack.pop() << " from the stack " << endl;

        stack.print();
        cout << "The peak after pop is " << stack.peek() << endl;

        cout << "Size of collection is " << stack.getSize() << endl;
    } catch (SabianException e) {
        cout << "Stack Exception " << e.getMessage() << endl;
    } catch (const char* e) {
        cout << "Exception " << e << endl;
    }
}

void queue() {
    SabianQueue<int> queue = SabianQueue<int>();
    try {
        queue.enqueue(100);
        queue.enqueue(200);
        queue.enqueue(300);
        queue.print();
        cout << "Total size " << queue.getSize() << endl;
        cout << "Peek " << queue.peek() << endl;


        cout << "Trying to dequeue " << queue.dequeue() << endl;

        cout << "After dequeue " << endl;
        queue.print();
        cout << "Total size " << queue.getSize() << endl;
        cout << "Peek " << queue.peek() << endl;


    } catch (SabianException e) {
        cout << "Queue Exception " << e.getMessage() << endl;
    } catch (const char * e) {
        cout << "Exception " << e << endl;
    }
}

/*
 * The main file
 */
int main(int argc, char** argv) {
    SABIAN_STRING type;
    cout << "Enter Data Structure : (bst,stack,queue)" << endl;
    cin >> type;
    if (type == "stack") {
        stack();
    } else if (type == "queue") {
        queue();
    } else if (type == "bst") {
        bst();
    } else {
        cout << "No value selected";
    }
    return 0; //Frees up all constructors when set to return(0) and not exit(0)

}

