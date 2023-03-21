/*
How would you design a stack which, in addtion to push and pop, has a function min
which returns the minimum element ? Push, pop and min should all operate in O(1) time.
*/

/*

------        
|  8  |
------
|  4 |
------
------
|  1  |
------
------
|  5  |
------
------
|  2   |
------
------
|  3  |
------
  s1(this is our stack) 

------        
|    |
------
|    |
------
------
|    |
------
------
| 1   |
------
------
| 2   |
------
------
| 3   |
------
  s2 (this is here to keep track of the min)


*/

#include <iostream>
#include <stack>
#include <vector>


class stackmin
{

private:
    std::stack<int> s1, s2;


public:
    void push(int val)
    {
        s1.push(val); 
        if(min() >= val)
            s2.push(val); 
    }

    int min()
    {
        if(s2.empty())
        { 
            return INT32_MAX;  
        }
        else
            return s2.top(); 
    }

    void pop()
    {
        if(s1.top() == min())
            s2.pop(); 
        s1.pop(); 
    }

    bool empty()
    {
        return s1.empty(); 
    }

    int top()
    {
        return s1.top(); 
    }
};


int main()
{

stackmin s; 
int top_of_the_stack;
std::vector<int> v{3, 7, 2, 5, 1, 4}; 

for(auto &el : v)
    {
        s.push(el); 
        std::cout << "pushed element is " << el << " the current min is: " << s.min() << std::endl;  
    }

for(int i = 0; i < v.size(); i++)
{
top_of_the_stack = s.top();
s.pop(); 
std::cout << "we popped out " << top_of_the_stack << " from the stack and the current min is" << s.min() << std::endl; 
}

}

















