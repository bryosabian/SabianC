/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SabianConfig.h
 * Author: katekiguru
 *
 * Created on August 24, 2020, 8:56 PM
 */

#ifndef SABIANCONFIG_H
#define SABIANCONFIG_H

#ifdef __cplusplus

#include <string>

extern "C" {
#endif

#ifndef NULL
#define NULL 0
#endif

    /**
     The integer
     */
    typedef int SABIAN_INT;

    /**
     The string type*/
    typedef std::string SABIAN_STRING;

    /**
     The Long type*/
    typedef long SABIAN_LONG;

    /**
     * Prints a new string
     * @param text
     */
    extern void printLn(SABIAN_STRING text);



#ifdef __cplusplus
}
#endif

#endif /* SABIANCONFIG_H */

