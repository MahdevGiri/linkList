//
// Created by mahes on 6/27/2019.
//

#include "main.h"

int main(int argc, char** argv) {
    DataNode obj;  // instance of struct DataNode
    Linkedlist list;  // instance of Linkedlist

    //this program uses rand, this is the seed (do it only once!)
    srand(time(NULL));

    // making number of test cases from
    // TEST_CASE_OFFSET to TEST_CASE_BASE + TEST_CASE_OFFSET (5 - 25)

    int num_tests = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;


    //making test case parallel arrays to hold test data
    int ids[num_tests];
    char *data[num_tests];
    for (int i = 0; i < num_tests; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    //filling arrays with test case data
    cout << "Making " << num_tests << " test cases..." << endl;
    make_test_cases(ids, data, num_tests);
    cout << "Test cases done" << endl << endl;

    //adding all the test cases to the list
    cout << "Tessting adding all test cases to linkedlist" << endl;
    for (int i = 0; i < num_tests; i++) {
        if (list.addNode(ids[i], data[i])) {
            cout << "\t" << i + 1 << ") " << ids[i] << ": " << data[i] << " added to list." << endl;
        } else {
            cout << "\terror: something went wrong" << endl;
        }
    }
    cout << "Testing adding all test cases done" << endl << endl;


    //get max and min id
    int max, min, middle;
    max = -1;
    min = 99999;
    for (int i = 0; i < num_tests; i++) {
        if (ids[i] > max) {
            max = ids[i];
        }
        if (ids[i] < min) {
            min = ids[i];
        } else {
            middle = ids[i];
        }

    }
    cout << "max" << max << endl;
    cout << "min" << min << endl;
    cout << "middle" << middle << endl;

    //printing the list in both order and getting the count

    cout << "printing the list in ascending order" << endl;
    list.printList();
    cout << "priting in decending  order" << endl;
    list.printList(false);
    cout << "Getting the count" << endl;
    cout << list.getCount() << endl;

    //deleting all the test cases to the list
    cout << "Testing deleting all test cases to linkedlist" << endl;

    cout << "trying to delete the first node with id: " << min << endl;
    if (list.deleteNode(min)) {
        cout << min << " deleted from list." << endl;
    } else {
        cout << "\terror: something went wrong" << endl;
    }

    cout << "trying to delete the last node with id: " << max << endl;
    if (list.deleteNode(max)) {
        cout << max << " deleted from list." << endl;
    } else {
        cout << "\terror: something went wrong" << endl;
    }

    cout << "trying to delete the middle node with id: " << middle << endl;
    if (list.deleteNode(middle)) {
        cout << middle << " deleted from list." << endl;
    } else {
        cout << "\terror: something went wrong" << endl;
    }

    cout << "trying to delete the same node with id: " << middle<< endl;
    if (list.deleteNode(middle)) {
        cout << middle << " deleted from list." << endl;
    } else {
        cout << "\terror: something went wrong" << endl;
    }

    //deleting all the test cases to the list
    cout << "Tessting deleting all test cases to linkedlist" << endl;
    for (int i = 0; i < num_tests; i++) {
        cout<<"trying to delete the node with id: "<<ids[i]<<endl;
        if (list.deleteNode(ids[i])) {
            cout << "\t" << i + 1 << ") " << ids[i] << ": " << data[i] << " deleted to list." << endl;
        }
        else {
            cout << "\terror: something went wrong" << endl;
        }
    }
    cout << "Testing deleting all test cases done" << endl << endl;
}