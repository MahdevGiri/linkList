/***********************************************
Name: Mahesh Giri
Assignment: 03
Purpose: This program will create a fully functional doubly linked list.It will demonstrate complete testing
 and full functionality of the linked list.
************************************************/

#include "linked.h"

Linkedlist::Linkedlist() {
    head = nullptr;
    count =0;
}

//calls the clear function and resets the head=null and count =0
Linkedlist::~Linkedlist() {
    clear();

}

bool Linkedlist::clear() {
    bool success = true; // to track if it is success
    if(head==nullptr)
    {
        success = false;  // if empty list
    }
    else
    {
        Node *ptr = head;
        while(ptr->forward!=nullptr) // traverse through whole list until it gets the last node
        {
            ptr=ptr->forward;
        }
        while(ptr->back!=nullptr) // when it is the last node, it calls deleteTail until only one head is left
        {

            deleteTail(&ptr,&count);
            ptr=ptr->back;
        }
        deleteHead(&head,&ptr,&count);  /// it deletes the only one head left
    }
    return success;
}


bool Linkedlist::addNode(int id, string data) {

   bool done = true;   // to find out if the method is successful
    Node *temp = new Node(); // new node is created and filled with id and data
    temp->id = id;
    temp->data = data;
    temp->forward = nullptr;
    temp->back = nullptr;

    if (head == nullptr)  //add head or first node
    {
        head = temp;
        count++;
    }
    else        // if there is at least one node
    {

        Node *ptr = head;
        bool found = false;   // bool found is used to check if the condition is meet
        if (id < (ptr)->id )   // add head at the beginning
        {
            addHead(&head, &temp, &count);
        }
        else if(id==ptr->id)
        {
            done =false; // if the id is not unique, it will not execute the code that comes after
        }
        else        // to add in middle or tail
        {
            while (!found  && ptr->forward != nullptr && done)
            {

                ptr = ptr->forward;
                if(id ==(ptr)->id)  // if same element
                {
                    done =false;  // will break out of the while loop and indicate the unsuccess
                }
                else if (id < (ptr)->id)  // add middle
                {
                    found = true;
                    addMiddle(&ptr, &temp, &count);
                }
            }                   // end of while loop

            if (!found && id !=(ptr)->id)         //add tail when out of the while loop
            {
                addTail(&ptr, &temp, &count);
            }
            else if (!found && id ==(ptr)->id)  // if same element as that of tail
            {
               done=false;   //indicate the unsuccess
            }
        }

    }

    return done;

    }

void Linkedlist::printList() {
    printList(true);  // calls the printList function with default value true

}


    void Linkedlist::printList(bool result)
    {

    Node *ptr=head;
    if(!result &&ptr!=nullptr)  // if bool value is false and list is not empty
       {
            while(ptr->forward!=nullptr)
            {
                ptr=ptr->forward;
            }
           for (int i = 0; i < count ; i++) {
               cout << ptr->id << ": " << ptr->data << endl;
               ptr = ptr->back;
           }
       }
    else
        {
            for (int i = 0; i < count && ptr != nullptr; i++) {
                cout << ptr->id << ": " << ptr->data << endl;
                ptr = ptr->forward;
            }
        }
    }

bool Linkedlist::deleteNode(int id) {
    bool done =true;
    if(head==nullptr)
    {
        done = false;   // empty list
    }
    else
    {
        Node *ptr = head;
        if(ptr->back==nullptr &&id==ptr->id && (ptr->forward==nullptr||ptr->forward!=nullptr)) // deleting head when there is one or more than one node
        {
            deleteHead(&head,&ptr,&count);  // call deleteHead
        }
        else //if node to be deleted is not the first node
        {
            bool found = false;
            while(!found && ptr->forward!=nullptr)
            {

                if(ptr->id==id)  //deleting middle
                {
                    found=true;
                    deleteMiddle(&ptr,&count);
                }
                if (!found)
                {
                    ptr = ptr->forward;
                }
            }

            if (!found &&ptr->id==id)         //deleting tail
            {
                deleteTail(&ptr,&count);
            }
            else if(!found &&ptr->id!=id)
            {
                done =false;  // not found in any node
            }
        }

    }

    return done;
}

int Linkedlist::getCount() {
    return count;
}

bool Linkedlist::getNode(int id,DataNode* newNode) {
    bool found=false;
    Node* ptr = head;
    while(ptr->forward!=nullptr&&!found) //traverse until it finds the match or reach the tail
    {
        if(ptr->id==id)
        {
            found=true;
            newNode->id=ptr->id;
            newNode->data=ptr->data;
        }
        if (!found)
        {
            ptr = ptr->forward;
        }
    }
    if(ptr->id==id && !found)  // id matched with tail
    {
        found=true;
        newNode->id=ptr->id;
        newNode->data=ptr->data;
    }
    else if(!found)  // not matched with any node(not found in tail too)
    {
        newNode->id =-1;
        newNode->data=" ";
    }
    return found;
}




////////////////////////////////////////////////////////////////////////
//PRIVATE HELPER FUNCTION
///////////////////////////////////////////////////////////////////////

void Linkedlist:: deleteHead(Node** head,Node** ptr,int* count)  //delete head
{
    if ((*ptr)->forward == nullptr)  // only one node
    {
        *head = nullptr;
        free(*ptr);
        (*count)--;
    } else    //more than one node
    {
        *head = (*head)->forward;
        (*head)->back = nullptr;
        free(*ptr);
        (*count)--;
    }
}

void Linkedlist::deleteMiddle(Node** ptr,int* count)  //delete middle
{

    (*ptr)->back->forward=(*ptr)->forward;
    (*ptr)->forward->back=(*ptr)->back;
    free(*ptr);
    (*count)--;

}

void Linkedlist::deleteTail(Node** ptr,int* count)  //delete tail
{
    (*ptr)->back->forward=nullptr;
    free(*ptr);
     (*count)--;

}


void Linkedlist::addHead(Node** head,Node** temp,int* count)  //add head
{
    (*temp)->forward=*head;
    (*head)->back=*temp;
    (*head) =*temp;
    (*count)++;
}

void Linkedlist::addMiddle(Node** ptr,Node** temp,int* count)  // add middle
{
    (*temp)->forward=*ptr;
    (*temp)->back=(*ptr)->back;

    (*ptr)->back=*temp;
    (*temp)->back->forward=*temp;
    (*count)++;
}

void Linkedlist:: addTail(Node** ptr,Node** temp,int* count)   //add tail
{

    (*ptr)->forward=*temp;
    (*temp)->back=*ptr;
    (*count)++;
}






