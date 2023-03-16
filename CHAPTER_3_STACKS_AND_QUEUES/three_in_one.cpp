/*
Describe how you could use a single array to implement three stacks.
*/

/*
we can use an array of n elements and divide the array into three pieces and insert the elements to the corresponding 
stack regions of the array but we could have a problem with the container size since array is a static storage element. 

We can solve this problem with creating an array to hold the values of the inserted elements, an array called top to keep
track of the index of the top elements.


*/

#include <iostream>

class stacks
{
int* vals; // vals will point to the first element of the array to insert the items
int* top; // stores indexes of next items
int* next; // the indexes of the next items 

int size_arr; 
int size_stack;

int free; // the variable to keep track of the free location inside the vals array 

public:
    stacks(int k, int n); // constructor 
    void push(int el, int sn); 
    int pop(int sn); 
    bool isfull(){return (free == -1);}
    bool isEmpty(int sn){return (top[sn] == -1);}
};


stacks::stacks(int k1, int n1)
{
size_stack = k1; 
size_arr = n1; 

vals = new int[size_arr]; 
top = new int[size_stack]; 
next = new int[size_arr]; 

for(int i = 0; i < size_stack; i++)
    top[i] = -1; 

free = 0; 
for(int i = 0; i < size_arr-1; i++) 
    next[i] = i + 1; 
next[size_arr-1] = -1;  

}

void stacks::push(int el, int sn)
{
if(isfull())
    return;
int i = free; // first of all, since free is constructed as 0, i will start from 0

free = next[i]; // this element holds the value one more than the value of i, for example when we insert to the i = 1,
                // free space becomes next[1] which is 2 


next[i] =  top[sn];
top[sn] = i; 

vals[i] = el;

}



int stacks::pop(int sn)
{
    if(isEmpty(sn))
        return INT32_MAX;

// find index of top item in stack number sn 
int i = top[sn];

top[sn] = next[i]; 

next[i] = free; 

free = i; 

return vals[i]; 

}



int main()
{
int k = 3, n = 15; 

stacks st(3, 15); 

st.push(2, 2); 
st.push(7, 2);
st.push(5,  1);

std::cout << "pop from second stack" << st.pop(2) << std::endl; 
std::cout << "pop from second stack" << st.pop(2) << std::endl; 

std::cout << "pop from the first stack" << st.pop(1) << std::endl;


}




