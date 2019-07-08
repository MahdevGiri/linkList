//
// Created by mahes on 6/27/2019.
//

#include "main.h"

int main()
{
    Linkedlist list;
    bool opt = list.deleteNode(10);
    list.printList(opt);
    bool option=list.addNode(10,"hari");
    list.printList(option);

}