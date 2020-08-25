/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SabianUser.h
 * Author: katekiguru
 *
 * Created on August 24, 2020, 9:49 PM
 */

#ifndef SABIANUSER_H
#define SABIANUSER_H

#include <string>
#include "SabianConfig.h"

class SabianUser {
public:
    SabianUser();
    static SabianUser null();
    SabianUser(const SabianUser& orig);
    virtual ~SabianUser();

    SabianUser(SABIAN_STRING name, SABIAN_INT age, SABIAN_STRING gender) {
        this->name = name;
        this->age = age;
        this->gender = gender;
    }

    SABIAN_INT getAge() const {
        return age;
    }

    SABIAN_STRING getGender() const {
        return gender;
    }

    SABIAN_STRING getName() const {
        return name;
    }

    SABIAN_LONG getID() const {
        return ID;
    }

    void setID(SABIAN_LONG ID) {
        this->ID = ID;
    }

    void setAge(SABIAN_INT age) {
        this->age = age;
    }

    void setGender(SABIAN_STRING gender) {
        this->gender = gender;
    }

    void setName(SABIAN_STRING name) {
        this->name = name;
    }

    bool operator==(const SabianUser &user) const {
        return this->ID == user.ID;
    }

private:
    SABIAN_STRING name;
    SABIAN_INT age;
    SABIAN_STRING gender;
    SABIAN_LONG ID;
};

#endif /* SABIANUSER_H */

