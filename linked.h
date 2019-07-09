
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
    ~Linkedlist();

    bool addNode(int,string);
    bool deleteNode(int);
    void printList(bool);
    void printList();   // calls the printList with bool value true
    int getCount();
    bool clear();

private:
    Node* head;
    int count;

    //  private helper function
    void addHead(Node** head,Node** temp,int* count);
    void addMiddle(Node** ptr,Node** temp,int* count);
    void addTail(Node** ptr,Node** temp,int* count);
    void deleteHead(Node** head,Node** ptr,int* count);
    void deleteMiddle(Node** ptr,int* count);
    void deleteTail(Node** ptr,int* count);


};

#endif //LINKED_H
