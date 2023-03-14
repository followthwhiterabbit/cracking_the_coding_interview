/*


3 - > 5 - > 8 -> 5 -> 10 -> 2 -> 1  (partition = 5)

i would solve this problem with creating a new node and returning it 




*/

#include <iostream>


struct node
{
int data; 
node* next; 
}; 

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





void connectLists(node* newlistless, node* newlistgreater) // connects the lesser list and the greatest list 
{

node* headofless = newlistless; 

while(headofless->next != nullptr)
{
    headofless = headofless->next; 
}

headofless->next = newlistgreater; 


}



node* partition(node* head, int x)
{
node* newListLess = new node(); 
node* newListGreatest = new node(); 

while(head != nullptr)
{
int curdata = head->data; 

if(curdata < x)
{
    insertElement(newListLess, curdata); 
}
if(curdata >= x)
{
    insertElement(newListGreatest, curdata); 
}

head = head->next; 

}


connectLists(newListLess, newListGreatest); 




return newListLess; 

}




int main()
{
node* head = new node(); 

insertElement(head, 3); 
insertElement(head, 5); 
insertElement(head, 8); 
insertElement(head, 5); 
insertElement(head, 10); 
insertElement(head, 2); 
insertElement(head, 1); 

node* returnedlist = partition(head, 5); 

printLinkedList(returnedlist); 


}









