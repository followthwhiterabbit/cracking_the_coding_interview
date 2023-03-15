/*
You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that
the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as linked list. 
You are not allowed to "cheat" and just convert the linked list to an integer. 

EXAMPLE:
Input: (7 -> 1 -> 6) + (5 -> 9 -> 2), That is, 617 + 295 = 912
Output: 2 -> 1 -> 9. That is 912. 

Suppose the digits are stored in forward order. Repeat the problem.

Input: (7 -> 1 -> 6) + (5 -> 9 -> 2), That is, 617 + 295 = 912
Output: 9 -> 1 -> 2. That is 912. 

I didn't notice the fact that I am not allowed to convert it to an integer. :) 
I'll come back to this problem later on. 


*/
#include <iostream>
#include <vector>

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


// we will have a function that will take two linked lists' head and we will return a new linked list out of their digits sum.
// Input: (7 -> 1 -> 6) + (5 -> 9 -> 2), That is, 617 + 295 = 912

node* sum_lists(node* llist, node* rlist)
{
int sum = 0, factor = 1; 
// std::vector<int> forwardorder;  
node* newList = new node(); 

while(llist != nullptr)
{
sum += llist->data * factor; 
factor *= 10; 
llist = llist->next; 
}
factor = 1;

while(rlist != nullptr)
{
    sum += rlist->data * factor;
    factor *= 10; 
    rlist = rlist->next; 
}

std::cout << sum << std::endl; 

while(sum > 0)
{
    int pushdata = sum % 10; 
    insertElement(newList, pushdata); 
    // forwardorder.push_back(pushdata); 
    sum /= 10; 
}

return newList; 
}


int main()
{

node* firstlist = new node(); 
node* secondlist = new node();

insertElement(firstlist, 7); 
insertElement(firstlist, 1); 
insertElement(firstlist, 6);
insertElement(firstlist, 1);


insertElement(secondlist, 5);
insertElement(secondlist, 9);
insertElement(secondlist, 2);
insertElement(secondlist, 1); 


node* newlist = sum_lists(firstlist->next, secondlist->next); 

printLinkedList(newlist); 


}