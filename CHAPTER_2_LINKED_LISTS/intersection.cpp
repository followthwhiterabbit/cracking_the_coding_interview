/*
Given two (singly) linked lists, determine if the two lists intersect. Return the inter-
secting node. Note that the intersection is defined based on reference, not value. That is, if the kth
node of the first linked list is the exact same node(by refernce) as the jth node of the second 
linked list, then they are intersecting. 


// there are some multiple possibilities for this.



&l1-node1 -> &l1-node2 -> &l1-node3 -> &l1-node4
                |
                |
            &l2-node1
(these two linked lists, intersect in node2 in the first linked list and second node of the second linked list)





&l1-node1 -> &l1-node2 -> &l1-node3 -> &l1-node4 -> &l1-node5 
                             |
                             |
                         &l2-node1
(these two linked lists, intersect in node3 in the first linked list and second node of the second linked list)


*/
#include <iostream>

struct node
{
int data;
node* next; 
};




node* intersect(node* l1head, node* l2head)
{
node* temp; 

while(l2head != nullptr)
{
temp = l1head; 

while(temp != nullptr)
{

    if(temp == l2head)
        return temp; 

    temp = temp->next; 
    
}

l2head = l2head ->next;
}
return nullptr; 
}



int main()
{
node* l1node1 = new node(); 
node* l1node2 = new node(); 
node* l1node3 = new node(); 
node* l1node4 = new node(); 
node* l1node5 = new node(); 

node* l2node1 = new node(); 
node* l2node2 = new node(); 

l1node1->data = 1; 
l1node2->data = 2; 
l1node3->data = 3; 
l1node4->data = 4; 
l1node5->data = 5; 

l2node1->data = 1; 


l1node1->next = l1node2; 
l1node2->next = l1node3; 
l1node3->next = l1node4; 
l1node4->next = l1node5; 
l1node5->next = nullptr;

l2node1->next = l1node3; 

node* intersection_node = intersect(l1node1, l2node1); 

std::cout << "intersection data is: " << intersection_node->data << std::endl; 
std::cout << "intersection address is: " << intersection_node << std::endl; 

}






