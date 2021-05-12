/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SabianException.h
 * Author: bryosabian
 *
 * Created on May 12, 2021, 8:09 PM
 */

#ifndef SABIANEXCEPTION_H
#define SABIANEXCEPTION_H

#include "SabianConfig.h"

class SabianException : public std::exception {
public:
    SABIAN_STRING message;
    int code;

    SabianException(SABIAN_STRING message, int code) :
    message(message), code(code) {
    }

    SabianException(SABIAN_STRING message) :
    message(message) {
    }

    virtual const char* what() const noexcept override {
        return this->message.c_str();
    }

    int getCode() const {
        return code;
    }

    SABIAN_STRING getMessage() const {
        return message;
    }

};

#endif /* SABIANEXCEPTION_H */

