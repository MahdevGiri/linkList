
#ifndef LINKED_H
#define LINKED_H
#include <iostream>
#include "data.h"
using namespace std;
//#define STACK_SIZE 10  ////////////////////////////////////////
//#define INITIAL_POSITION -1 ////////////////////////////
//#define ONE 1               ////////////////////////////////

class Linkedlist {
public:
    Linkedlist();
    ~Linkedlist(){};

    bool addNode(int,string);
    bool deleteNode(int);
    void printList(bool);
    void printList();   // calls the printList with bool value true
    int getCount();

private:
    Node* head;
    int count;


};

#endif //LINKED_H
