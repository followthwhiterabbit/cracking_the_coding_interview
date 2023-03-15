/*
Implement a function to check if a linked list is a palindrome

To be able to solve this problem, we need to have basically the first element of the node and the element of the last node. 
then the element of the next node and the data of the node before the last node and so on, as you can see below. 

-----------          -----------            -----------             -----------                ----------- 
|data|next| -------> |data|next| ---------> |data|next| ----------->|data|next|  ------------> |data|next| 
-----------          -----------            -----------             -----------                -----------
  node 1                node 2                 node 3                  node 4                      node 5 

to check if the linked list is a palindrome, we need to be able to take the data of the node1 and node5 and compare them and then
move to node 2 and compare node 2 with node 4 and then move to node 3 and compare it with itself along the way. 

we could have a stack and push every element to the stack one after the other. 
then iterate through the linked list and compare the current element with the top of the stack. 
after we compare it with the top of the stack we can pop this element from the stack and move to the next element of the lnked list. 



*/

#include <iostream>
#include <stack>

struct node{
int data; 
node* next; 
};


// we will have a function called isPalindrome for instance:
bool isPalindrome(node* head)
{
node* temp = head; 
std::stack<int> values; 

// we will push every element to the stack one after the other

while(temp != nullptr)
{
    values.push(temp->data); 
    temp = temp->next; 
} 

// now we need to iterate the list from the head and compare the lement with the top of the stack since it's the last element inserted to the stack 
while(head != nullptr)
{

int top = values.top(); // last pushed element of the stack 
values.pop(); // pop the last element for the next iteration
if(head->data != top)
    return false;

head = head->next; 

}
return true; 

}


int main()
{
node* new_list = new node(); 
node* second_node = new node(); 
node* third_node = new node(); 
node* fourth_node = new node(); 
node* fifth_node = new node(); 

// i am assuming, our linked list is like 1->2->3->2->1

new_list->data = 1;
new_list->next = second_node; 

second_node->data = 2; 
second_node->next = third_node; 

third_node->data = 3; 
third_node->next = fourth_node; 

fourth_node->data = 2; 
fourth_node->next = fifth_node;

fifth_node->data = 1; 
fifth_node->next = nullptr; 


std::cout << isPalindrome(new_list) << std::endl; 


}






