/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "SabianUser.h"

SabianUser::SabianUser() {
}

SabianUser::SabianUser(const SabianUser& orig) {
}

SabianUser::~SabianUser() {
}

SabianUser SabianUser::null() {
    SabianUser user = SabianUser();
    user.setID(-1);
    return user;
}