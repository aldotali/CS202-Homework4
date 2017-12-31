#include <iostream>
#include <string>
#include <list>
#include "Person.h"
using namespace std;

/**
* Title : Balanced Search Trees and Hashing
* Author : Aldo Tali
* ID: 21500097
* Section : 02
* Assignment : 4
* Description : This is a cpp file for  the implementation of the person class.
*/

Person :: Person(string a){
  setName(a);
}

Person :: Person(){
}

void Person :: setName(string a){
    name = a;
}
string Person :: getName(){
    return name;
}

list<Person> Person :: getFriendList(){
    return friends;
}

void  Person :: addFriend(Person pr){
    friends.push_front(pr);
}

void  Person :: removeFriend(Person pr){
    list<Person> a = this->getFriendList();
    list<Person> :: iterator iter = a.begin();
    list<Person> newL;
   // cout<<endl;
   string name;
    while (iter != a.end()) {
      name = (*iter).getName();
      if (name == pr.getName()){
      } else {
          newL.push_front(*iter);
      }
      friends.pop_front();
      iter++; 
    }
    Person temp;
    while (!newL.empty())
    {
        temp = newL.front();
        addFriend(temp);
        newL.pop_front();
    }
}

bool Person :: operator==( Person other ) {
    if  (this->getName() == other.getName()) {
        return true;
    }
}

void Person :: printFriends(){
    list<Person> a = this->getFriendList();

    list<Person> :: iterator iter = a.begin();
    int count = 0;
   // cout<<endl;
    while (iter != a.end()) {
      name = (*iter).getName();
    
      for (int i = 0; i < count; i++ ){
        cout<<'\t';
      }
      count++;
      cout<< name;
      iter++;
    }
    cout<<'\n';
}