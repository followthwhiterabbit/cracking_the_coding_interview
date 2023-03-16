/*
Given a linked list which might contain a loop, implement an algorithm that returns the node at the 
beginning of the loop(if one exists);

EXAMPLE: a -> b -> c -> d -> e -> c
Output: c 

we will traverse the linked list and check if the next node has been seen before, 
if so, we will return it basically. 

we can solve it with set of node* 


*/

#include <iostream>
#include <set>

struct node // i changed my struct a bit, when it's initialized it will set the next pointer to null automatically 
{
char data; 
node* next; 
node(char dt)
    : data{dt}, next{nullptr} {}
}; 




node* loop_detection(node* head)
{
std::set<node*> nodes;  // i have a set of node* type, which holds the addresses of the nodes

while(head != nullptr)
{

    if(nodes.find(head) == nodes.end())
        {
            nodes.insert(head); 
        }
    else
        {
            return head; 
        } 

    head = head->next; 
    
}

return nullptr;

}





int main()
{

node* node1 = new node('A');
node* node2 = new node('B'); 
node* node3 = new node('C'); 
node* node4 = new node('D'); 
node* node5 = new node('E'); 

node1->next = node2; 
node2->next = node3;
node3->next = node4; 
node4->next = node5; 
node5->next = node3; 



node* returned_node = loop_detection(node1); 

std::cout << returned_node->data << std::endl; 












}




