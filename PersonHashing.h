#include "Person.h"
#include <string>
#include <list>
using namespace std;

/**
* Title : Balanced Search Trees and Hashing
* Author : Aldo Tali
* ID: 21500097
* Section : 02
* Assignment : 4
* Description : This is a header file for the PersonHashing class.
*/

class PersonHashing {
    private :
        int SIZE;
        list<Person> table[11];
        int computeHash(Person newP);
    public :
        PersonHashing();
        void insertPerson(Person newP);
        void printTable();
        Person* getPerson(string name);
};