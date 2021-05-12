/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SabianUser.h
 * Author: bryosabian
 *
 * Created on August 24, 2020, 9:49 PM
 */

#ifndef SABIANUSER_H
#define SABIANUSER_H


#include<iostream>
#include "SabianConfig.h"

class SabianUser {
public:
    SabianUser();
    SabianUser(const SabianUser& orig);
    virtual ~SabianUser();

    SabianUser(SABIAN_STRING name, SABIAN_INT age, SABIAN_STRING gender);

    SABIAN_INT getAge() const;

    SABIAN_STRING getGender() const;

    SABIAN_STRING getName() const;

    SABIAN_LONG getID() const;

    SABIAN_INT getHeight() const;


    void setID(SABIAN_LONG ID);

    void setAge(SABIAN_INT age);

    void setGender(SABIAN_STRING gender);

    void setName(SABIAN_STRING name);

    void setHeight(SABIAN_INT height);


    bool operator==(const SabianUser &user1) const;

    bool operator<(const SabianUser &user) const;

    bool operator<=(const SabianUser &user) const;

    bool operator>(const SabianUser &user) const;

    bool operator>=(const SabianUser &user) const;

    std::ostream& operator << (std::ostream& os);
    




private:
    SABIAN_STRING name;
    SABIAN_INT age;
    SABIAN_STRING gender;
    SABIAN_LONG ID;
    SABIAN_INT height;
};

#endif /* SABIANUSER_H */

