
#ifndef HASHASSIGNMENT_DATA_H
#define HASHASSIGNMENT_DATA_H


#include <string>
using std::string;

//#define BUFFER_SIZE 16  //////////////////////////////////

struct Node {
    int id;
    string data;
    Node* forward;
    Node* back;
};
#endif //HASHASSIGNMENT_DATA_H
