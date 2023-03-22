/*
Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore, in real life, 
we would likely start a new stack when the previous stack exceeds some threshold. Implement a data structure setOfStacks
that mimics this. SetOfStacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity. 
SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack(that is, pop() should return the same values as it would
if there were just a single stack)

FOLLOW UP
Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
*/

#include <iostream>
#include <stack>

#define NUM_STACK 50

class StackPlates
{
private:
    std::stack<int>* mystack;  
    int threshold; 
    int curStack;
public:
    StackPlates()
    {
        threshold = 10; 
        mystack = new std::stack<int>[NUM_STACK];
        curStack = 0; 
    }

    void push(int data)
    {
        if(mystack[curStack].size() >= threshold)
        {
           curStack++;  
        }
        mystack[curStack].push(data); 
    }

    void pop()
    {
        if(mystack[curStack].empty())
        {
            if(curStack == 0)
                {
                    return; 
                }
            curStack--;  
        }
        mystack[curStack].pop(); 
    }

    int top()
    {
        if(mystack[curStack].empty())
            {
                if(curStack == 0)
                    return INT32_MIN;
                
                curStack--; 
            }
            return mystack[curStack].top();
    }

    bool empty()
    {
        if(curStack == 0)
            return mystack[curStack].empty();
        else
            return false;
    }

    void popAt(int index)
    {
        if(mystack[index].empty())
            {
                std::cout << index << " stack is empty\n";
                return;
            }
        mystack[index].pop(); 
    }
};

int main()
{

StackPlates platesofstack;
for(int i = 0; i < 50; i++)
    platesofstack.push(i);


std::cout << "pop element from the third stack" << std::endl; 
platesofstack.popAt(2); 



std::cout << "popping all elements from the stack\n";
for(int i = 0; i <  50; i++)
    {
        std::cout << "popped element " << platesofstack.top() << std::endl;
        platesofstack.pop();
    }
/*
//SOME REMINDER ABOUT POINTERS 
int* ptr; 

ptr = new int[6];

int* arr = ptr; 


ptr[0] = 1; 
ptr[1] = 2; 
ptr[2] = 3; 
ptr[3] = 4; 
ptr[4] = 5; 
ptr[5] = 6; 

/*

*ptr = 1; 
*(ptr + 1) = 2; 
*(ptr + 2) = 3; 
*(ptr + 3) = 4; 
*(ptr + 4) = 5; 
*(ptr + 5) = 6; 
*/

/*

*ptr = 1; 

++ptr;
*ptr = 2;  // this only changes the first pointed element

++ptr; 
*ptr =  3;  // this only changes the first pointed element

++ptr; 
*ptr = 4;  // this only changes the first pointed element

++ptr; 
*ptr = 5; // this only changes the first pointed element

++ptr; 
*ptr = 6; // this only changes the first pointed element

*/ 

/*


for(int i = 0; i < 6; i++)
    std::cout << ptr[i] << " " << arr[i] << std::endl; 

*/ 

/*

for(int i = 0; i < 6; i++)
    std::cout << ptr[i] << " " << std::endl; 
*/ 



}
