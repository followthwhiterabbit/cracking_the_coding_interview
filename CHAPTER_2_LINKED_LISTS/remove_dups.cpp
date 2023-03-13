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
*/

void removeDuplicate(node* head)
{
std::set<int> values; 

int curr = head->next->data; 
int prev= head->data; 

values.insert(prev); 

while(head != nullptr)
{ 
    node* lastnode; 
    if(values.find(curr) == values.end())
    {
        values.insert(curr); 
        head = head->next; 
        curr = head->next->data; 
        prev = head->data; 
    } else // here we need to delete the duplicate
    {
    
    if(head->next != nullptr)        
    {
        node* temp = head->next; 
        head->next = head->next->next; 
        lastnode = head; 
        delete temp;
        head = head->next;

    }
    else if(head->next == nullptr)
    {
        delete head;
        lastnode->next = nullptr;
    }


    }
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



