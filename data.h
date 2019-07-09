/***********************************************
Name: Mahesh Giri
Assignment: 03
Purpose: This program will create a fully functional doubly linked list.It will demonstrate complete testing
 and full functionality of the linked list.
************************************************/

#ifndef DATA_H
#define DATA_H

#include <string>
using std::string;

#define BUFFER_SIZE 11

struct Node {
    int id;
    string data;
    Node* forward;
    Node* back;
};

struct DataNode {
    int id;
    string data;
};
#endif //DATA_H
