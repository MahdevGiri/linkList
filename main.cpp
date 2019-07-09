//
// Created by mahes on 6/27/2019.
//

#include "main.h"

int main()
{
    Linkedlist list;
   bool opt = list.deleteNode(10);
   // list.printList(opt);
    bool option=list.addNode(10,"hari");
    list.printList(option);
    bool option2=list.addNode(50,"ram");
    list.printList(option2);
    bool option3=list.addNode(500,"r");
    list.printList(option3);
    bool option4 = list.deleteNode(10);
    list.printList(true);
   cout<<"the count is-> " <<list.getCount()<<endl;

}