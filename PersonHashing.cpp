#include "PersonHashing.h"
#include <string>
#include <list>
#include <iterator>
using namespace std;

/**
* Title : Balanced Search Trees and Hashing
* Author : Aldo Tali
* ID: 21500097
* Section : 02
* Assignment : 4
* Description : This is a cpp file for the implementation of PersonHashing class.
*/

PersonHashing :: PersonHashing(){
  SIZE = 11;
}

void PersonHashing :: insertPerson(Person a){
    int index = computeHash(a);
    table[index].push_front(a);
}

int PersonHashing :: computeHash(Person a){
    string name = a.getName();
    int sum = 0;
    for (int i = 0; i< name.size()-1; i++){
        sum+= name[i];
    }
    //cout<<"The sum is: "<<sum<<endl;
    return sum%SIZE;
}


void PersonHashing :: printTable(){
  for (int i = 0; i < 11; i++){
    list<Person> :: iterator iter = table[i].begin();
    cout<<"In the " <<i<<" bucket we have : "<<endl;
    while (iter != table[i].end()) {
      cout << '\t' << (*iter).getName() << '\n';
      iter++;
    }
  }
}

Person* PersonHashing :: getPerson(string name){
  unsigned size = name.size();
  string temp = name;
  name.resize (size+1);
  Person p =Person(name);
  int index = computeHash(p);
  bool compare;

  list<Person> :: iterator iter = table[index].begin();
  while (iter != table[index].end()){
    compare = true;
    temp = (*iter).getName();
    for (int i = 0; i<name.size()-1; i++){
      if (name[i] != temp[i]){
        compare = false;
        break;
      }
    }
    if (compare){
      return &(*iter);
    }
    iter++;
  }
  return NULL;
}