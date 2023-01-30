#include <limits.h>
#include <vector>
#include <iostream>
/*
O(big O) - describes upper bound on the time. An algorithm that prints all the values in an array could be described as O(N), but it could also be described as 
O(N^2), O(N^3), or O(2^N)(or many other big 0 times). The algorithm is at least as fast as each of these; therefore they are upper bounds on the runtime. This is 
similar to a less-than-or-equal-to relationship. If Bob is X years old(I'll assume no one lives past age 130), then you could say X <= 130. It would also correct to 
say that X <= 1000 or x <= 1000000. Likewise, a simple algorithm to print the values in an array is O(N) as well as O(N^3) or any runtime bigger than O(N). 

Big Omega(): In academia, Omega is the equivalent concept but for lower bound. Printing the values in an array is omega(N) as well as omega(log N) and Omega(1). A
After all you know that it won't be faster than those runtimes. 

Big theta(): in academia, Theta means both O and omega. That is, an algorithm is theta(N) if it is both O(N) and Omega(N). Theta gives a tight bound on runtime. 


DROP THE CONSTANTS 
It is very possible for O(N) to run faster than O(1) for specific inputs. Big O just describes the rate of increase. 
For this reason, we drop the constants in runtime. An alforithm that one might have described as O(2N) is actually O(N).


DROP THE NON DOMINANT TERMS 
We should drop the non-dominant terms
O(N^2 + N) == O(N^2)
O(N + logN) == O(N)
O(5*2^N + 1000N^1000) == O(2^N) because 2^(something) is more dominant than N^(something)



*/




/*

we have 4 calls for every n values, so time complexity is O(N)

sum(4)         4 + sum(3)
 -> sum(3)     3 + sum(2)
   -> sum(2)   2 + sum(1)
     -> sum(1)   1 + sum(0)
       -> sum(0) returns 0 



*/
int sum(int n)                                           
{                                                         
    if(n <= 0)                                            
        return 0;                                         
    
    return n + sum(n-1); 

}




int pairSum(int a, int b)
{
    return a + b; 
}


int pariSumSequence(int n)
{
    int sum = 0; 
    for(int i = 0; i < n; i++)
    {
        sum += pairSum(i, i+1);  // this will be called O(n) times. But these calls are not on the call stack, so in this case, we only have O(1) space. 
    }
    
    return sum; 
}





int main()
{


/*

std::vector<int> myarr{1, 2, 3, 4, 5}; 

int min = INT_MAX;
int max = INT_MIN; 

std::cout << min << " " << max << std::endl; 

//for(auto &el : myarr) // O(N) run-time 
    //{
        //if (el < min)
            //min = el;
        //if (el > max)
            //max = el; 
    //}


for(auto el : myarr)
    if(el < min)
        min = el; 

for(auto el : myarr)
    if(el > max)
        max = el; 





std::cout << min << std::endl; 
std::cout << max << std::endl; 
*/ 


 

}

