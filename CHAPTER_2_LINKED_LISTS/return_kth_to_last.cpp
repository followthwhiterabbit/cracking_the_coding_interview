/*
implement an algorithm to find the kth to last element of a singly linked list. 



*/

/*

1 -> 2 -> 3 -> 4 -> 5 -> 6 -> nullptr

let's assume, we have a linked list like the one above. 
- to be able to get the kth last element, first we need to cound the nodes until we hit the nulltpr 

for example let's say we want the fourth last element, 
we need to move from the head, (node value) - 4 times  

for(int i = 0; i < (node val)- K; i++)
    {
        head = head->next; 
    }
    std::cout << head->val << "is the kth last element of our linked list"


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


void kth_to_last(node* head, int k)
{

int len = 0; 
node* temp = head->next; 

while(temp != nullptr)
{
    temp = temp->next; 
    len++; 

}

temp = head->next; 
for(int i = 0; i < len - k; i++)
    temp = temp->next; 

std::cout << std::endl; 
std::cout << temp->data << std::endl; 



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

kth_to_last(head, 4); 


}

