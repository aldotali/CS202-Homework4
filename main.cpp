#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
//#include "PersonHashing.h"
#include "FriendShipHashing.h"
using namespace std;
void executeP(string pname,  PersonHashing &tab);
void executeF(string pname ,  FriendShipHashing &tab, PersonHashing &tabP);
void executeU(string line, FriendShipHashing &tab);
void executeL(string name, PersonHashing tabP);
void executeQ(string pname ,  FriendShipHashing tab);

int main (){
    string line;
    string command;
    string pname;

    Person temp;
    PersonHashing tester = PersonHashing();
    FriendShipHashing friends = FriendShipHashing();

    ifstream inputF ("input.txt");
    if (!inputF.is_open()) {
        cout<<"Could not open the file. We are terribly sorry."<<endl;
    } else {
        while ( getline (inputF,line) )
        {  
            command = line.substr(0,1);
            if (command == "P" || command == "p"){
                pname = line.substr(2);
                executeP(pname,tester);
            } else if (command == "F" || command == "f"){
                pname = line.substr(2);
                
                executeF(pname, friends,tester);
            } else if (command == "U" || command == "u"){
                pname = line.substr(2);
                
                executeU(pname, friends);
            } else if (command == "L" || command == "l") {
                pname = line.substr(2);
                
                executeL(pname, tester);
            } else if (command == "Q" || command == "q") {
                pname = line.substr(2);
                
                executeQ(pname, friends);
            } else if (command == "X" || command == "x") {
               inputF.close();
               //friends.printTable();
               return 0;
            }else {

            }
        }
        tester.printTable();
        cout<<endl<<endl;
        friends.printTable();
        inputF.close();
    }
  return 0;
}

void executeP(string pname,  PersonHashing &tab){
    Person temp;
    temp = Person(pname);
    tab.insertPerson(temp);
}

void executeF(string pname ,  FriendShipHashing &tab, PersonHashing &tabP){
    string p1 ,p2,newname,a;
    istringstream iss(pname);
    iss>>p1;
    iss>>p2;
    if (p1 != p2){
        a = p2; newname = p1;
        newname =newname.append(a);
        Friendship *alreadyIn = tab.getFriendship(newname);
        if (alreadyIn == NULL) {
            Person *first = tabP.getPerson(p1);
            Person *second = tabP.getPerson(p2);
            if (first != NULL && second != NULL) {
                first->addFriend(*second);
                second->addFriend(*first);
                Friendship fr = Friendship(newname,first,second);
                string name = fr.getFriendShipName();
                tab.insertFriendShip(fr);
            }
        }
    }
}

void executeU(string line, FriendShipHashing &tab){
    string p1 ,p2,a,fname;
    istringstream iss(line);
    iss>>p1;
    iss>>p2;

    if (p1!=p2){
        fname = p1; a = p2;
        fname = fname.append(a);
        Friendship *f = tab.getFriendship(fname);
        fname = p2; a = p1;
        fname = fname.append(a);
        Friendship *g = tab.getFriendship(fname);
        if (f != NULL || g!=NULL){
            if (g!=NULL) {
                if (f != NULL){
                    delete f;
                }
                f = NULL;
            	f = g;
            }
            Person *pe1 = f->getFriend12();
            Person *pe2 = f->getFriend21();
            pe1->removeFriend(*pe2);
            pe2->removeFriend(*pe1);
            *f = Friendship();
        } 
    }
}

void executeL(string name, PersonHashing tabP){
    string p1;
    istringstream iss(name);
    iss>>p1;

    Person* l = tabP.getPerson(p1);
    l->printFriends();
}

void executeQ(string pname ,  FriendShipHashing tab){
    string p1 ,p2;
    istringstream iss(pname);
    iss>>p1;
    iss>>p2;

    string fname = p1;
    fname = fname.append(p2);
    string gname = p2;
    gname = gname.append(p1);

    Friendship *f = tab.getFriendship(fname);
    Friendship *g = tab.getFriendship(gname);

    if (f != NULL || g != NULL){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
 
}