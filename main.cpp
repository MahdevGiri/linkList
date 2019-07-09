//
// Created by mahes on 6/27/2019.
//

#include "main.h"

int main()
{

    DataNode obj;
    Linkedlist list;
list.addNode(10,"ram");
list.addNode(15,"sam");
list.addNode(20,"tam");
list.getNode(2,&obj);

cout<<obj.id<<endl;
cout<<obj.data<<endl;


}