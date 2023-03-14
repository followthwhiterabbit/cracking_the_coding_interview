/*
Implement an algorithm to delete a node in the middle
    (any node but the first and the last node, not necessarily the exact middle) of a singly linked list, given 
    only access to that node. 


EXAMPLE: a -> b -> c -> d -> e -> f 
result:  a -> b -> d -> e -> f

*/

/*
I can edit the previous code to be able to solve this problem. 

what we need to add to the previous code is to take the middle element of the linked list. (by counting the number of nodes ) and then halving
number of nodes / 2 ---> and then remove this node while connecting the previous node with the prev->next->next. 


*/

#include <iostream>

struct node
{
    int data; 
    node* next; 

}; 


// let's create a function to insert an element to the list :) 
void insertElement(struct node* head, int val)
{

node* new_node = new node(); 

new_node->data = val; 

while(head->next != nullptr)
{
    head = head->next; 
}
head->next = new_node; 

new_node->next = nullptr; 

}


void printLinkedList(node* head)
{

    while(head->next != nullptr)
    {
        std::cout << head->next->data << "-> "; 
        head = head->next; 

    }

}


void del_mid_node(node* head)
{

int len = 0, midnum; 
node* temp = head->next; 
node* prev = head; 
node* cur = head->next;

while(temp != nullptr)
{
    temp = temp->next; 
    len++; 

}

midnum = len / 2; 

for(int i = 1; i < midnum; i++)
{
    prev = cur; 
    cur = cur->next; 
}

prev->next = cur->next; 
delete(cur); 



}


int main()
{

node* head = new node(); 


insertElement(head, 1); 
insertElement(head, 2); 
insertElement(head, 3); 
insertElement(head, 4); 
insertElement(head, 5); 
insertElement(head, 6); 

printLinkedList(head); 

del_mid_node(head); 
std::cout << std::endl; 

printLinkedList(head); 


}























