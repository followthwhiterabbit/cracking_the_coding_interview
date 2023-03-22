/*
Implement a MyQueue class which implements a queue using two stacks.
*/

#include <iostream>
#include <stack>


/*
We have a MyQueue class  which will have enqueue and dequeue methods. 
*/


class myQueue
{
std::stack<int> s1, s2; 

public:

void enqueue(int data)
{

while(!s1.empty())
{
    s2.push(s1.top()); 
    s1.pop();
}

s1.push(data); 

while(!s2.empty())
{
    s1.push(s2.top()); 
    s2.pop(); 
}

}

int dequeue()
{
if(s1.empty())  
    {
        std::cout << "queue is empty.\n";
        exit(0);
    }

    int val = s1.top(); 
    s1.pop(); 
    return val;
}

}; 








int main()
{
myQueue queue; 
for(int i = 1; i < 6; i++)
    queue.enqueue(i);  

for(int i = 0; i < 5; i++)
    std::cout << queue.dequeue() << std::endl; 

    /*
    // QUICK RECAP 


    std::queue<int> myqueue; 
    int myInt; 

    std::cout << "enter some integers (enter 0 to end):\n";

    do
    {
       std::cin >> myInt;
        myqueue.push(myInt); 
    } while (myInt);
    
    std::cout << "myqueue contains: "; 
    while(!myqueue.empty())
        {
           std::cout << ' ' << myqueue.front(); 
           myqueue.pop();  
        }

    std::cout << std::endl; 
    */

}




