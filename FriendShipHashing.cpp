#include "FriendShipHashing.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

/**
* Title : Balanced Search Trees and Hashing
* Author : Aldo Tali
* ID: 21500097
* Section : 02
* Assignment : 4
* Description : This is a cpp file for  the implementation of the FriendshipHashing class.
*/


FriendShipHashing :: FriendShipHashing() {
    for (int i = 0; i < 71; i++){
        table[i] = Friendship();
    }
    SIZE = 71;
}

int FriendShipHashing :: computeHash(Friendship newF){
    int probeCount = 0;
    int sum = 0;
    int origIndex,index;
    string name = newF.getFriendShipName();
    for (int i = 0; i< name.size(); i++){
        sum+= name[i];
    }

    //index is sum of charachters modulus the table size , if that is not free recompute hash
    origIndex = sum%SIZE;
    index = origIndex;

    while (!table[index].isNull()){
        probeCount++;
        index = (origIndex + (probeCount*probeCount))%SIZE;
        if (index == origIndex){
            return -1;
        }
    }    
    return index;
}

void FriendShipHashing :: insertFriendShip(Friendship f){
    int index = this->computeHash(f);
 
    if (index >= 0){
        table[index] = f;
    } else {
        cout<<"Not inserted friendship: "<<f.getFriendShipName()<<endl;
    }
}

void FriendShipHashing :: printTable(){
    Person* temp;
  for (int i = 0; i < SIZE; i++){
      if (table[i].getFriendShipName() != ""){
        cout<<"In the " <<i<<" bucket we have : "<<endl;
        cout<<"Friendship : "<<table[i].getFriendShipName()<<endl;
        cout<<"Friends 1 : ";
        temp = table[i].getFriend12();
        if (temp != NULL) {
            temp->printFriends();
        }
        cout<<"Friends 2 : ";
        temp = table[i].getFriend21();
        if (temp != NULL) {
            temp->printFriends();
        }
      }
    }
}

Friendship* FriendShipHashing:: getFriendship(string name){
    int probeCount = 0;
    int sum = 0;
    int origIndex,index;
    
    //get the sum of the asci characters
    for (int i = 0; i< name.size(); i++){
        sum+= name[i];
    }

    //index is sum of charachters modulus the table size , if that is not free recompute hash
    origIndex = sum%SIZE;
    index = origIndex;

    while (true){
        if (table[index].getFriendShipName() == name ){
            break;
        }
        probeCount++;
        index = (origIndex + (probeCount*probeCount))%SIZE;
        if (index == origIndex){
            return NULL;
        }
    }    
    return &table[index];
}
