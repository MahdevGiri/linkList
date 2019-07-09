/***********************************************
Name: Mahesh Giri
Assignment: 03
Purpose: This program will create a fully functional doubly linked list.It will demonstrate complete testing
 and full functionality of the linked list.
************************************************/

#ifndef LINKED_H
#define LINKED_H
#include <iostream>
#include "data.h"  //to get struct Node
using namespace std;

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
    bool getNode(int,DataNode*);

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
