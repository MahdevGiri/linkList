/***********************************************
Name: Mahesh Giri
Assignment: 03
Purpose: This program will create a fully functional doubly linked list.It will demonstrate complete testing
 and full functionality of the linked list.
************************************************/

#include "main.h"

int main() {
    DataNode obj;  // instance of struct DataNode
    Linkedlist list;  // instance of Linkedlist
    int tempId;
    int max, min;
    int maxIndex, minIndex, middleIndex;

    //this program uses rand, this is the seed (do it only once!)
    srand(time(NULL));

    // making number of test cases from
    // TEST_CASE_OFFSET to TEST_CASE_BASE + TEST_CASE_OFFSET (5 - 25)

    int num_tests = rand() % (TEST_CASE_BASE - TEST_CASE_OFFSET + 1) + TEST_CASE_OFFSET;//rand()%((MAX_ID - MIN_ID) + 1) + MIN_ID;


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
	

	 /*
     *  testing methods on empty list
     */
    cout << "\nTesting deleteNode() on empty list" << endl;
    cout << "==============================================" << endl;
    tempId = rand()%((MAX_ID - MIN_ID) + 1) + MIN_ID;
    cout << "deleting " << tempId << "... ";
    list.deleteNode(tempId) ? cout << "deleted" << endl : cout << "failed" << endl;
    cout << endl;
	
	cout << "Testing getNode() on empty list" << endl;
    cout << "==============================================" << endl;
    if (list.getNode(tempId, &obj)) {
        cout << "retrieved: " << endl;
        cout << "ID is: " << obj.id << endl;
        cout << "DATA is: " << obj.data << endl;
    } else {
        cout << "not retrieved:" << endl;
        cout << "ID is: " << obj.id << endl;
        cout << "DATA is: " << obj.data << endl;
    }
    cout << endl;
	
	cout << "Testing getCount() on empty list" << endl;
    cout << "==============================================" << endl;
    cout << "Count is: " << list.getCount() << endl;
    cout<<endl;
	
	cout<<"testing the printList() on empty list"<<endl;
    cout << "==============================================" << endl;
	cout << "printing the empty list by default" << endl;
    list.printList();
    cout<<endl;

    cout << "printing the empty list forward" << endl;
    list.printList(true);
    cout<<endl;

	cout << "printing the empty list in  backward" << endl;
    list.printList(false);
	cout<<endl;

    cout<<"clearing the empty list "<<endl;
    cout << "clearing list" << "... ";
    list.clear() ? cout << "cleared" << endl : cout << "failed" << endl;
    cout << endl;

	cout<<" END of testing methods on empty list"<<endl;
	cout<<"********************************************************************************"<<endl<<endl;

    //adding all the test cases to the list
    cout << "Tessting adding all test cases to linkedlist" << endl;
    for (int i = 0; i < num_tests; i++) {
        if (list.addNode(ids[i], data[i])) {
            cout << i + 1 << ") " << ids[i] << ": " << data[i] << " added to list." << endl;
        } else {
            cout << "error: something went wrong" << endl;
        }
    }
    cout << "Testing adding all test cases done" << endl << endl;


   ;

   //get the min, max and middle value, and their index
    max = -1;
    min = 99999;
    for (int i = 0; i < num_tests; i++) {
        if (ids[i] > max) {
            max = ids[i];
            maxIndex=i;
        }
        else if (ids[i] < min) {
            min = ids[i];
            minIndex = i;
        }
        else
        {
            middleIndex =i;
        }
    }



    cout << "Testing getCount() of the list" << endl;
    cout << "==============================================" << endl;
    cout << "Count is: " << list.getCount() << endl;
    cout<<endl;

    cout<<"testing the printList() of the list"<<endl;
    cout << "==============================================" << endl;
    cout << "printing the  list by default" << endl;
    list.printList();
    cout<<endl;

    cout << "printing the list forward" << endl;
    list.printList(true);
    cout<<endl;

    cout << "printing the list in  backward" << endl;
    list.printList(false);
    cout<<endl;

    cout << "Testing getNode() on the list(get first node)" << endl;
    cout << "==============================================" << endl;
    if (list.getNode(ids[minIndex], &obj)) {
        cout << "retrieved: " << endl;
        cout << "ID is: " << obj.id << endl;
        cout << "DATA is: " << obj.data << endl;
    } else {
        cout << "not retrieved:" << endl;
        cout << "ID is: " << obj.id << endl;
        cout << "DATA is: " << obj.data << endl;
    }
    cout << endl;

    cout << "Testing getNode() non-existing node(id passed is): " <<num_tests<< endl;
    cout << "==============================================" << endl;
    if (list.getNode(num_tests, &obj)) {
        cout << "retrieved: " << endl;
        cout << "ID is: " << obj.id << endl;
        cout << "DATA is: " << obj.data << endl;
    } else {
        cout << "not retrieved:" << endl;
        cout << "ID is: " << obj.id << endl;
        cout << "DATA is: " << obj.data << endl;
    }
    cout << endl;

    // try to add existing id
    cout << "try to add existing id: " << ids[minIndex]<<endl;
    cout << "==============================================" << endl;
    if (list.addNode(ids[minIndex], data[minIndex])) {
        cout << ids[minIndex] << " added to list." << endl;
    } else {
        cout << "Error: the id is already in the list." << endl;
    }
    cout<<endl;

    // try to delete the node for all cases
    cout << "trying to delete the first node with id: " << ids[minIndex] << endl;
    cout << "==============================================" << endl;
    if (list.deleteNode(ids[minIndex])) {
        cout << ids[minIndex] << " deleted from list." << endl;
    } else {
        cout << "error: could not delete from the list" << endl;
    }
    cout<<endl;

    cout << "Testing getCount() of the list after deleting first node" << endl;
    cout << "==============================================" << endl;
    cout << "Count is: " << list.getCount() << endl;
    cout<<endl;

    cout<<"testing the printList() of the list after deleting first node"<<endl;
    cout << "==============================================" << endl;
    cout << "printing the  list by default" << endl;
    list.printList();
    cout<<endl;

    cout << "printing the list in  backward after deleting first node" << endl;
    list.printList(false);
    cout<<endl;

    cout << "trying to delete the last node with id: " << ids[maxIndex] << endl;
    cout << "==============================================" << endl;
    if (list.deleteNode(ids[maxIndex])) {
        cout << ids[maxIndex] << " deleted from list." << endl;
    } else {
        cout << "error: could not delete from the list" << endl;
    }
    cout<<endl;



    cout<<"testing the printList() of the list after deleting last node"<<endl;
    cout << "==============================================" << endl;
    cout << "printing the  list forward" << endl;
    list.printList();
    cout<<endl;

    cout << "printing the list in  backward after deleting last node" << endl;
    list.printList(false);
    cout<<endl;

    cout << "Testing getCount() of the list after deleting last node" << endl;
    cout << "==============================================" << endl;
    cout << "Count is: " << list.getCount() << endl;
    cout<<endl;


    cout << "trying to delete the middle node with id: " << ids[middleIndex] << endl;
    cout << "==============================================" << endl;
    if (list.deleteNode(ids[middleIndex])) {
        cout << ids[middleIndex] << " deleted from list." << endl;
    } else {
        cout << "error: could not delete from the list" << endl;
    }
    cout << endl;

    cout<<"testing the printList() of the list after deleting last node"<<endl;
    cout << "==============================================" << endl;
    cout << "printing the  list forward" << endl;
    list.printList();
    cout<<endl;

    cout << "printing the list in  backward after deleting last node" << endl;
    list.printList(false);
    cout<<endl;

    cout << "Testing getCount() of the list after deleting last node" << endl;
    cout << "==============================================" << endl;
    cout << "Count is: " << list.getCount() << endl;
    cout<<endl;


    cout << "trying to delete the  non-existing node (id passed is): " <<num_tests<< endl;
    cout << "==============================================" << endl;
    if (list.deleteNode(num_tests)) {              //num_tests is between 5 to 30
        cout << ids[maxIndex] << " deleted from list." << endl;
    } else {
        cout << "error: could not delete from the list" << endl;
    }

    cout<<endl;


    cout << "Testing getCount() of the list" << endl;
    cout << "==============================================" << endl;
    cout << "Count is: " << list.getCount() << endl;
    cout<<endl;

    cout<<"testing the printList() of the list"<<endl;
    cout << "==============================================" << endl;
    cout << "printing the  list by default" << endl;
    list.printList();
    cout<<endl;

    cout<<"clearing the list when more than one node "<<endl;
    cout << "clearing list" << "... ";
    list.clear() ? cout << "cleared" << endl : cout << "failed" << endl;
    cout << endl<<endl;

    cout << "Testing getCount() of the list after the clearList method" << endl;
    cout << "==============================================" << endl;
    cout << "Count is: " << list.getCount() << endl;
    cout<<endl;

    cout << "try to add just one id" << endl;
    cout << "==============================================" << endl;
    if (list.addNode(ids[minIndex], data[minIndex])) {
        cout << ids[minIndex] << " added to list." << endl;
    } else {
        cout << "Error: the id is already in the list." << endl;
    }
    cout<<endl;

    cout << "Testing getCount() of the list after adding only one element" << endl;
    cout << "==============================================" << endl;
    cout << "Count is: " << list.getCount() << endl;
    cout<<endl;

    cout<<"clearing the list when there is only one node "<<endl;
    cout << "clearing list" << "... ";
    list.clear() ? cout << "cleared" << endl : cout << "failed" << endl;
    cout << endl<<endl;

   
    cout << "Testing getCount() of the list after the clearList method" << endl;
    cout << "==============================================" << endl;
    cout << "Count is: " << list.getCount() << endl;
    cout<<endl;
	
}