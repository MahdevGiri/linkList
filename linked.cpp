#include "linked.h"


void addHead(Node** head,Node** temp,int* count)  //add head
{
        (*temp)->forward=*head;
        (*head)->back=*temp;
        (*head) =*temp;
    *count =*count +1;
    cout<<"addAtBeginning function is called"<<endl;
    cout<<"count "<<*count<<endl;

}

void addMiddle(Node** ptr,Node** temp,int* count)
{
    (*temp)->forward=*ptr;
    (*temp)->back=(*ptr)->back;

    (*ptr)->back=*temp;
    (*temp)->back->forward=*temp;
    *count =*count +1;
    cout<<"Middle function is called"<<endl;
    cout<<"count "<<*count<<endl;
}

void addTail(Node** ptr,Node** temp,int* count)   //add tail
{

    (*ptr)->forward=*temp;
    (*temp)->back=*ptr;
    *count =*count +1;
    cout<<"tail function is called"<<endl;
    cout<<"count "<<*count<<endl;



}

Linkedlist::Linkedlist() {
    head = nullptr;
    count =0;
}

bool Linkedlist::addNode(int id, string data) {

   bool done = true;   // to find out if the method is successful
    Node *temp = new Node();
    temp->id = id;
    temp->data = data;
    temp->forward = nullptr;
    temp->back = nullptr;

    if (head == nullptr)  //add head
    {

        head = temp;
        count = count + 1;
        cout << "head function is called" << endl;
        cout << "count: " << count << endl;

    }
    else        // if head is not null
    {

        Node *ptr = head;
        bool found = false;
        if (id < (ptr)->id )   // add head
        {
            addHead(&head, &temp, &count);
        }
        else if(id==ptr->id)   // if both have the same value
        {
            done =false;
        }

        else {  //add in middle
            while (found != true && ptr->forward != nullptr &&done!=false) {
                if (found == false && done==true) {
                    ptr = ptr->forward;
                }
                if(id ==(ptr)->id)  // if same element
                {
                    found =true;
                    done =false;
                }
                else if (id < (ptr)->id) {
                    found = true;
                    addMiddle(&ptr, &temp, &count);
                }
            }

            if (found != true )         //add tail
            {
                addTail(&ptr, &temp, &count);
            }
        }

        }

    return done;

    }



    void Linkedlist::printList(bool result)
    {

        Node *ptr = head;
        cout << "Printing the list: " << endl;
        for (int i = 0; i < count && ptr != nullptr; i++) {
            cout << ptr->id << ": " << ptr->data << endl;
            ptr = ptr->forward;
        }

    }

