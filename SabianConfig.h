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

#include <iostream>
#include <string>

extern "C" {
#endif

    typedef int SABIAN_INT;
    typedef std::string SABIAN_STRING;
    typedef long SABIAN_LONG;
    extern void printLn(SABIAN_STRING text);
    
#ifdef __cplusplus
}
#endif

#endif /* SABIANCONFIG_H */

