//
// Created by mahes on 6/27/2019.
//

#include "main.h"

int main()
{
    Linkedlist list;
   bool opt = list.deleteNode(10);
   list.printList(false);
    bool option=list.addNode(10,"hari");
    list.printList(false);
   // bool option5 = list.deleteNode(10);
    //list.printList(option5);
    bool option2=list.addNode(50,"ram");
    list.printList(false);
    bool option3=list.addNode(500,"r");
    list.printList(false);
    bool option4 = list.deleteNode(500);
    list.printList(false);
    bool option7 = list.deleteNode(10);
    list.printList(false);
    bool option8 = list.deleteNode(50);
    list.printList(false);



}