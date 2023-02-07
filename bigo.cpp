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




/*

std::string reverses_string_with_spaces(std::string str)
{
    int n = str.size(); 

    std::string result(n, '\0');



    for(int i = 0; i < n; i++)
        if(str[i] == ' ')
            result[i] = ' '; 


    // traverse input string from beginning
    // and put characters in result from end 
    int j = n - 1; 
    for(int i = 0; i < str.length(); i++)
        {
            // ignore spaces in input string
            if(str[i] != ' ')
                {
                    // ignore spaces in result
                    while(result[j] == ' ')
                        j--;

                    result[j] = str[i];
                    j--;  

                }

        }

return result; 

}
*/ 


/*


bool isPrime(int n)
{
    for(int x = 2; x * x <= n; x++)
    {
        if(n % x == 0)
            return false;
    }

return true; 

}



int factorial(int n)
{
    if(n < 0)
        return -1;
    else if (n == 0)
        return 0; 
    else
        return n * factorial(n - 1);


}
*/ 


/*
void permute(std::string& a, int l, int r)
{
    // base case
    if (l == r)
        std::cout << a << std::endl; 
    else{
        // permutations made
        for(int i = l; i <= r; i++)
            {
                // swapping done
                std::swap(a[l], a[i]);

                // recursion called 
                permute(a, l + 1, r);

                //backtrack
                std::swap(a[l], a[i]);

            }
    }
}
*/ 






void print_vectors(std::vector<int>&, std::vector<int>&); 
void print_another_vectors(std::vector<int>&, std::vector<int>&); 
void reverse_array(std::vector<int>&);



int main()
{

/*


std::string str = "ABC"; 

int n = str.size(); 

permute(str, 0, n - 1);

*/ 


/*

std::string my_name{"seyit kaan karaalioglu"};

std::string reversed_string = reverses_string_with_spaces(my_name);

std::cout << reversed_string << " "; 
*/

// std::cout << isPrime(5); 



/*


char name[5] = {"kaan"};

name[4] = 'r';

for(int i = 0; name[i] != '\0'; i++)
    std::cout << name[i] << std::endl; 
// int size = sizeof(name) / sizeof(name[0]);
*/ 




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



/*



std::vector<int> vec{1, 2, 3, 4, 5};
std::vector<int> vec2{6, 7, 8, 9, 10};

for(auto &el : vec)
    printf("%d ", el);

printf("\n");

for(auto &el : vec2)
    printf("%d ", el); 

printf("\n"); 

std::cout << "O(A + B) runtime" << std::endl;  

*/ 



/*
std::vector<int> vec{1, 2, 3, 4, 5};
std::vector<int> vec2{6, 7, 8, 9, 10};

for(int el : vec)
    for(int el2 : vec2)
        printf("%d-vec1 %d-vec2\n", el, el2); 

*/ 

/*
Log N runtimes 
search 9 within {1, 5, 8, 9, 11, 13, 15, 19, 21}
    compare 9 to 11 -> smaller
    search 9 within {1, 5, 8, 9}
    compare 9 to 8 -> bigger
        compare 9 to 9
            return 

we start off with an N-Element array to search. Then, after a single step, 
we're down to N/2 elements. One more step and we're down to N/4 elements.
We stop when we either find the value or we're down to just one element. 

N = 16 
N = 8  -> divide by 2
N = 4 -> divide by 2 
N = 2 -> divide by 2 
N = 1 -> divide by 2

2^4 = 16
log 2 of 16 is gonna reveal 4 

2^k = n  log 2 of N = k 

RECURSIVE RUNTIMES

int f(int n)
{
    if(n <= 1)
        {
            return 1; 
        }
    return f(n-1) + f(n-1); 

}



*/




/*



std::vector<int> vector1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
std::vector<int> vector2{2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; 


//print_vectors(vector1, vector2); // we needed to put the vector arguments as reference function parameters 
//print_another_vectors(vector1, vector2); 
reverse_array(vector1);

for( auto &el : vector1)
    std::cout << el << " "; 

*/ 


}

void print_vectors(std::vector<int> &v1, std::vector<int> &v2)
{

    for(int i = 0 ; i < v1.size(); i++)
       for(int j = i+1; j < v2.size(); j++)
            std::cout << v1[i] << " " << v2[j] << std::endl; 

}

void print_another_vectors(std::vector<int> &v1, std::vector<int> &v2)
{
    for(int i = 0; i < v1.size(); i++)
    {
        for(int j = 0; j < v2.size(); j++)
            {
              if(v1[i] < v2[j]) // the if-statement within j's for loop is o(1) time since it's just a sequence of constnt time statements. 
                std::cout << v1[i] << " " << v2[j] << std::endl;  
            } }

}

void reverse_array(std::vector<int> &arr)
{
    for(int i = 0; i < arr.size() / 2; i++)
    {
        int end = arr.size() - i - 1;
        int temp = arr[i]; 
        arr[i] = arr[end]; 
        arr[end] = temp; 
    }

}


