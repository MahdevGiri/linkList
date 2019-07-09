
#ifndef DATA_H
#define DATA_H


#include <string>
using std::string;

//#define BUFFER_SIZE 16  //////////////////////////////////

struct Node {
    int id;
    string data;
    Node* forward;
    Node* back;
};
#endif //DATA_H
