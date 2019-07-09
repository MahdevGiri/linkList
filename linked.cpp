#include "linked.h"


void addHead(Node** head,Node** temp,int* count)  //add head
{
        (*temp)->forward=*head;
        (*head)->back=*temp;
        (*head) =*temp;
    *count =*count +1;
}

void addMiddle(Node** ptr,Node** temp,int* count)  // add middle
{
    (*temp)->forward=*ptr;
    (*temp)->back=(*ptr)->back;

    (*ptr)->back=*temp;
    (*temp)->back->forward=*temp;
    *count =*count +1;
}

void addTail(Node** ptr,Node** temp,int* count)   //add tail
{

    (*ptr)->forward=*temp;
    (*temp)->back=*ptr;
    *count =*count +1;
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
    }
    else        // if head is not null
    {

        Node *ptr = head;
        bool found = false;  // to break the loop if the case is found
        if (id < (ptr)->id )   // add head
        {
            addHead(&head, &temp, &count);
        }
        else if(id==ptr->id)   // if both have the same value
        {
            done =false;
        }
        else       // // to add in middle or tail
        {
            while (!found  && ptr->forward != nullptr && done)
            {

                ptr = ptr->forward;
                if(id ==(ptr)->id)  // if same element
                {
                    done =false;
                }
                else if (id < (ptr)->id)  // add middle
                {
                    found = true;
                    addMiddle(&ptr, &temp, &count);
                }
            }                   // end of while loop

            if (!found )         //add tail
            {
                addTail(&ptr, &temp, &count);
            }
        }

    }

    return done;

    }

void Linkedlist::printList() {
    printList(true);

}


    void Linkedlist::printList(bool result)
    {
    if(!result)
       {
        Node *ptr=head;
            cout<<"Printing the list back: "<<endl;
            while(ptr->forward!=nullptr)
            {
                ptr=ptr->forward;
            }
           for (int i = 0; i < count&& ptr->back != nullptr; i++) {
               cout << ptr->id << ": " << ptr->data << endl;
               ptr = ptr->back;
           }
           cout << ptr->id << ": " << ptr->data << endl; // printing head

       }
    else
        {
            Node *ptr = head;
            cout << "Printing the list: " << endl;
            for (int i = 0; i < count && ptr != nullptr; i++) {
                cout << ptr->id << ": " << ptr->data << endl;
                ptr = ptr->forward;
            }
            cout<<"The count is: "<<count<<endl;
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
        if(ptr->forward==nullptr && ptr->back==nullptr&&id==ptr->id) // only one node
        {
            cout<<"only one node case"<<endl;
            head =nullptr;
            free(ptr);
            count--;
        }
        else if(ptr->back==nullptr &&id==ptr->id&&ptr->forward!=nullptr) // deleting head when there is more than one node
        {
            cout<<"deleting head when there is more than one node"<<endl;
            head = head->forward;
            head->back=nullptr;
            free(ptr);
            count--;
        }
        else
        {
            bool found = false;
            while(!found && ptr->forward!=nullptr)
            {

                if(ptr->id==id)  //deleting middle
                {
                    cout<<"deleting middle "<<endl;
                    found=true;
                    ptr->back->forward=ptr->forward;
                    ptr->forward->back=ptr->back;
                    free(ptr);
                    count--;
                }
                if (!found)
                {
                    ptr = ptr->forward;
                }
            }

            if (!found &&ptr->id==id)         //deleting tail
            {
                cout<<"deleting tail"<<endl;
                ptr->back->forward=nullptr;
                free(ptr);
                count--;
            }
            if(!found &&ptr->id!=id)
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



