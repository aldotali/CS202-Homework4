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
* Description : This is a header file for the FriendShipHashing class.
*/

class FriendShipHashing {
    private :
        Friendship table[71];
        int SIZE;
        int computeHash(Friendship newF);
    public :
        FriendShipHashing();
        void insertFriendShip(Friendship f);
        Friendship * getFriendship(string fname);
        //void insertPeople(string P1, string P2);
        void printTable();
};