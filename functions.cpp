/***********************************************
Name: Mahesh Giri
Assignment: 03
Purpose: This program will create a fully functional doubly linked list.It will demonstrate complete testing
 and full functionality of the linked list.
************************************************/

#include "functions.h"

void make_test_cases(int *ids, char **data, int num_cases) {

    for (int i = 0; i < num_cases; i++) {
        ids[i] = rand() % MAX_ID  + MIN_ID;
        for (int j = 0; j < BUFFER_SIZE - 1; j++) {
            data[i][j] = 'a' + i;
        }
        data[i][BUFFER_SIZE - 1] = '\0';
    }
}

//for debug

void display_test_cases(int *ids, char **data, int num_cases) {
    for (int i = 0; i < num_cases; i++) {
        cout << ids[i] << ": " << data[i] << endl;
    }
}

