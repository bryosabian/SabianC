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

#include <cstdlib>
#include <iostream>
#include "SabianConfig.h"
#include <string>
#include "SabianUser.h"
#include "SabianHelper.h"


using namespace std;

/**
 * Print sizes
 */
void printSizes() {
    cout << "Size of char : " << sizeof (char) << endl;
    cout << "Size of int : " << sizeof (int) << endl;
    cout << "Size of short int : " << sizeof (short int) << endl;
    cout << "Size of long int : " << sizeof (long int) << endl;
    cout << "Size of float : " << sizeof (float) << endl;
    cout << "Size of double : " << sizeof (double) << endl;
    cout << "Size of wchar_t : " << sizeof (wchar_t) << endl;
}

/**
 * Classes
 */
void classes() {
    SabianUser user = SabianUser("Brian", 22, "male");
    printLn("The user is " + user.getName());
}

void interClasses() {
    SabianUser currentUser = getCurrentUser();
    if (currentUser == SabianUser::null()) {
        printLn("Current user not set");
    } else {
        printLn("The current user is " + currentUser.getName());
    }
}

SABIAN_INT addNumbers(SABIAN_INT x, SABIAN_INT y) {
    return x + y;
}

/*
 * The main file
 */
int main(int argc, char** argv) {
    printLn("Hello World");
    printSizes();
    classes();
    interClasses();
    int num = addNumbers(1, 3);
    printLn("Custom add " + to_string(num) + "");
    return 0;
}

