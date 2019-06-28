#include "linked.h"

Linkedlist::Linkedlist() {
    head = nullptr;
    count =0;
}

bool Linkedlist::addNode(int id, string data) {

    //newItem = new Item;
   // newItem->day = i;
    //newItem->dayname = days[i];
   // newItem->next = NULL;

    //attached it
   // *head = newItem;
   // head = &newItem->next;

    Node * temp = new Node();
    temp->id =id;
    temp->data =data;
    temp->back = nullptr;
    temp->forward = nullptr;
    if(head==nullptr)
    {
        head = temp;
    }

    head->back =temp;
    temp->forward = head;
    head = temp;

    count++;
    return true;
}

void Linkedlist::printList(bool result) {

    Node *ptr = head;
    cout<<"Printing the list: "<<endl;
    //cout<<count<<endl;
    //cout<<ptr->id<<endl;
    //cout<<ptr->data<<endl;
    for(int i =0;i<count &&ptr!=nullptr;i++)
    {
        cout<<ptr->id<<": "<<ptr->data<<endl;
        ptr = ptr->forward;
    }

}
