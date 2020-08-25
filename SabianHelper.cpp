/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "SabianUser.h"

SabianUser getCurrentUser() {
    SabianUser user = SabianUser("Brian Sabana", 22, "Male");
    user.setID(101);
    return user;
}