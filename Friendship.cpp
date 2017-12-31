#include "Friendship.h"
#include <string>
#include <list>
using namespace std;

/**
* Title : Balanced Search Trees and Hashing
* Author : Aldo Tali
* ID: 21500097
* Section : 02
* Assignment : 4
* Description : This is a cpp file for the implementation of  Friendship class.
*/

Friendship :: Friendship(){
    setFriend12(NULL);
    setFriend21(NULL);
}

Friendship :: Friendship(string name){
    setFrienshipName(name);
    setFriend12(NULL);
    setFriend21(NULL);
}

Friendship :: Friendship(string name, Person* f1, Person* f2){
    setFrienshipName(name);
    setFriend12(f1);
    setFriend21(f2);
}

Friendship :: Friendship(Person* f1, Person* f2){
    string name = (*f1).getName() + (*f2).getName();
    setFrienshipName(name);
    setFriend12(f1);
    setFriend21(f2);
}

string Friendship :: getFriendShipName(){
    return friendshipName;
}

void Friendship :: setFrienshipName(string name){
    friendshipName = name;
}

void Friendship :: setFriend12(Person* f1){
    friendAtoB = f1;
}

void Friendship :: setFriend21(Person* f2){
    friendBtoA = f2;
}
        
Person* Friendship :: getFriend12(){
    return friendAtoB;
}

Person* Friendship :: getFriend21(){
    return friendBtoA;
}

bool Friendship :: isNull(){
    return friendAtoB == NULL || friendBtoA == NULL;
}
