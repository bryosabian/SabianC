/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: katekiguru
 *
 * Created on August 24, 2020, 8:24 PM
 */

#include "dataStructures/BST/SabianBST.h"


#include "SabianConfig.h"

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

/*
 * The main file
 */
int main(int argc, char** argv) {
    bst();
    return 0;
}

