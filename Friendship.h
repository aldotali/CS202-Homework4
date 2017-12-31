
#include "PersonHashing.h"
#include <string>
#include <list>
using namespace std;

/**
* Title : Balanced Search Trees and Hashing
* Author : Aldo Tali
* ID: 21500097
* Section : 02
* Assignment : 4
* Description : This is a header file for the Friendship class.
*/

class Friendship{
    private:
        string friendshipName;
        Person* friendAtoB;
        Person* friendBtoA;
    public:
        Friendship();
        Friendship(string name);
        Friendship(string name, Person* f1, Person* f2);
        Friendship(Person* f1, Person* f2);
        Friendship(string f1, string f2);
        
        string getFriendShipName();
        void setFrienshipName(string name);
        void setFriend12(Person* f1);
        void setFriend21(Person* f2);
        string getFrienshipName();
        Person* getFriend12();
        Person* getFriend21();
        bool isNull();
};