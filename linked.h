
#ifndef HASHASSIGNMENT_LINKED_H
#define HASHASSIGNMENT_LINKED_H
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
    void printList(bool);

private:
    Node* head;
    int count;


};

#endif //HASHASSIGNMENT_LINKED_H
