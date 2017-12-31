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
* Description : This is a header file for the person class.
*/


class Person {
    private:
        string name;
        list<Person>    friends;
    public:
        Person(string name);
        Person();
        void setName(string name);
        string getName();
        list<Person> getFriendList();
        void addFriend(Person fr);
        void removeFriend(Person pr);
        void printFriends();
        bool operator==( Person other );
};