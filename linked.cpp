#include "linked.h"

Linkedlist::Linkedlist() {
    head = nullptr;
    count =0;
}

Linkedlist::~Linkedlist() {
    cout<<"Destructor is called..."<<endl;
    clear();

}

bool Linkedlist::clear() {
    bool success = true;
    if(count==0)
    {
        success = false;
    }
    else
    {
        Node *ptr = head;
        while(ptr->forward!=nullptr)
        {
            ptr=ptr->forward;
        }
        while(ptr->back!=nullptr)
        {

            deleteTail(&ptr,&count);
            ptr=ptr->back;
        }
        deleteHead(&head,&ptr,&count);
    }
    return success;
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

    Node *ptr=head;
    if(!result &&ptr!=nullptr)
       {
        cout<<"Printing the list back: "<<endl;
            while(ptr->forward!=nullptr)
            {
                ptr=ptr->forward;
            }
           for (int i = 0; i < count ; i++) {
               cout << ptr->id << ": " << ptr->data << endl;
               ptr = ptr->back;
           }
           cout<<"The count is: "<<count<<endl;
       }
    else
        {
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
        if(ptr->back==nullptr &&id==ptr->id && (ptr->forward==nullptr||ptr->forward!=nullptr)) // deleting head when there is more than one node
        {
            deleteHead(&head,&ptr,&count);  // call deleteHead
        }
        else
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
    while(ptr->forward!=nullptr&&!found)
    {
        if(ptr->id==id)
        {
            cout<<"found it not in tail though"<<endl;
            found=true;
            newNode->id=ptr->id;
            newNode->data=ptr->data;
        }
        if (!found)
        {
            ptr = ptr->forward;
        }
    }
    if(ptr->id==id && !found)  // found in tail
    {
        cout<<"found it (in tail)"<<endl;
        found=true;
        newNode->id=ptr->id;
        newNode->data=ptr->data;
    }
    else if(!found)
    {
        cout<<"Not found"<<endl;
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
        cout << "only one node case" << endl;
        *head = nullptr;
        free(*ptr);
        *count = *count - 1;
    } else    //more than one node
    {
        cout << "deleting head when there is more than one node" << endl;
        *head = (*head)->forward;
        (*head)->back = nullptr;
        free(*ptr);
        *count = *count - 1;
    }
}

void Linkedlist::deleteMiddle(Node** ptr,int* count)  //delete middle
{
    cout<<"deleting middle "<<endl;

    (*ptr)->back->forward=(*ptr)->forward;
    (*ptr)->forward->back=(*ptr)->back;
    free(*ptr);
    *count=*count-1;

}

void Linkedlist::deleteTail(Node** ptr,int* count)  //delete tail
{
    cout<<"deleting tail "<<endl;
    (*ptr)->back->forward=nullptr;
    free(*ptr);
    *count=*count-1;

}


void Linkedlist::addHead(Node** head,Node** temp,int* count)  //add head
{
    (*temp)->forward=*head;
    (*head)->back=*temp;
    (*head) =*temp;
    *count =*count +1;
}

void Linkedlist::addMiddle(Node** ptr,Node** temp,int* count)  // add middle
{
    (*temp)->forward=*ptr;
    (*temp)->back=(*ptr)->back;

    (*ptr)->back=*temp;
    (*temp)->back->forward=*temp;
    *count =*count +1;
}

void Linkedlist:: addTail(Node** ptr,Node** temp,int* count)   //add tail
{

    (*ptr)->forward=*temp;
    (*temp)->back=*ptr;
    *count =*count +1;
}






