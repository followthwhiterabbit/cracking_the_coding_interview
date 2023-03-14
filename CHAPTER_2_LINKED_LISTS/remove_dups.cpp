/*
Write code to remove duplicates from an unsorted linked list. 

FOLLOW UP 
How would you solve this problem if a temporary buffer is not allowed ? 

*/

#include <iostream>
#include <vector>
#include <set>

/*
Since it's the first quesion, I would like to solve this problem without creating insertion method and 
simply create different nodes and link them manually then send the head address to the remove duplicate function. 




*/


struct node
{

int data; 

node* next; 

}; 


void printList(node* head)
{

    while(head != nullptr)
    {
        std::cout << head->data << " "; 
        head = head->next; 
    }
}

/*
only removes duplicate elements next to each other, i am supposed to remove every duplicate element  

1 -> 2 -> 3 -> 2 -> 3 -> 1 

first, we will have a variable of node type pointer called head which points to the first element 
and a previous node element called prev which is initialized to point to nothing first 

while curr is not nullptr:
    if(our curr nodes data is inside the set): 
        prev->next will be equal to curr->next;
        and then we will remove the current node
    else(our curr node is not inside the set):
        we insert the curr->data inside the set
        and prev becomes our current node
        and our current node after whether curr->data is inside the set or not:
            curr = prev->next;






*/

void removeDuplicate(node* head)
{
std::set<int> values; 

node* curr = head; 
node* prev = nullptr; 

while(curr != nullptr)
{
    if(values.find(curr->data) != values.end())
    {
        prev->next = curr->next; 
        delete(curr); 
    }
    else
    {
        values.insert(curr->data); 
        prev = curr; 
    }
    curr = prev->next; 
}



}


int main()
{

node* head = nullptr; 
node* second  = nullptr; 
node* third = nullptr; 
node* fourth = nullptr;
node* fifth = nullptr; 
node* sixth = nullptr; 

head = new node(); 
second = new node(); 
third = new node(); 
fourth = new node(); 
fifth = new node(); 
sixth = new node(); 

head->data = 1;
head->next = second; 

second->data = 2; 
second->next = third; 

third->data = 3; 
third->next = fourth;

fourth->data = 2; 
fourth->next = fifth;  

fifth->data = 3; 
fifth->next = sixth; 

sixth->data = 1; 
sixth->next = nullptr;


printList(head); 

removeDuplicate(head); 

std::cout << std::endl; 

printList(head); 

}



