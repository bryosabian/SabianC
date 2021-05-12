/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "SabianUser.h"
#include "SabianConfig.h"

SabianUser::SabianUser() {
 std::cout << "Initializing user " << std::endl;
}

SabianUser::SabianUser(const SabianUser& orig) {
    this->setID(orig.ID);
    this->setName(orig.name);
    this->setGender(orig.gender);
    this->setHeight(orig.height);
}

SabianUser::~SabianUser() {
    std::cout << "Deinitializing user " << std::endl;
}

SabianUser::SabianUser(SABIAN_STRING name, SABIAN_INT age, SABIAN_STRING gender) {
    this->name = name;
    this->age = age;
    this->gender = gender;
}

SABIAN_INT SabianUser::getAge() const {
    return this->age;
}

SABIAN_STRING SabianUser::getGender() const {
    return this->gender;
}

SABIAN_LONG SabianUser::getID() const {
    return this->ID;
}

SABIAN_STRING SabianUser::getName() const {
    return this->name;
}

SABIAN_INT SabianUser::getHeight() const {
    return this->height;
}

void SabianUser::setAge(SABIAN_INT age) {
    this->age = age;
}

void SabianUser::setGender(SABIAN_STRING gender) {
    this->gender = gender;
}

void SabianUser::setID(SABIAN_LONG ID) {
    this->ID = ID;
}

void SabianUser::setName(SABIAN_STRING name) {
    this->name = name;
}

void SabianUser::setHeight(SABIAN_INT height) {
    this->height = height;
}

bool SabianUser::operator==(const SabianUser& user) const {
    return this->ID == user.ID;
}

bool SabianUser::operator<(const SabianUser& user) const {
    return this->age < user.age;
}

bool SabianUser::operator<=(const SabianUser& user) const {
    return this->age <= user.age;
}

bool SabianUser::operator>(const SabianUser& user) const {
    return this->age > user.age;
}

bool SabianUser::operator>=(const SabianUser& user) const {
    return this->age >= user.age;
}

std::ostream& SabianUser::operator<<(std::ostream& os) {
    os << "User " << this->getName() << " Age " << this->getAge() << " Height " << this->getHeight();
    return os;
}
