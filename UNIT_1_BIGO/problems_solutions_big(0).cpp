/*
The following code computes the product of a and b. What is its runtime ? 
int product(int a, int b)
{
int sum = 0; 
for(int i = 0; i < b; i++)   ---->    O(b) run-time
    sum += a; 

return sum 
}

int power(int a,  int b)
{
if(b < 0)
    return 0; 
else if(b == 0)             ------>   O(b) run-time as well, this recursive code iterates through b calls, since it subtracts one at each level
    return 1; 
else
    return a * power(a, b - 1); 
}


The following code computes a % b. What is its runtime ? 
int mod(int a, int b)
{
    if(b < 0)
        return -1;
    int div = a / b;         -------> O(1) constant amount of work
    return a - div * b; 
}

*/


#include <iostream>



/*



// The following code performs integer division. What is its runtime(assume a and b are both positive)?
int div(int a, int b)
{
    int count = 0; 
    int sum = b; 
    while(sum <= a)  ------------------------>  O(a/b). the variable count will eventually equal a/b. The while loop iterates count times.
    {                              ----------> Therefore, it iterates a/b times.
        sum += b;
        count++;
    }
return count;
}

*/ 


/*


int sqrt_root(int n)
{
    return sqrt_helper(n, 1, n); 
}

int sqrt_helper(int n, int min, int max)
{
    if(max < min)
        return -1; // no square root

    int guess = (min + max) / 2;

    if(guess * guess == n)
    {
        return guess;               ------------------------> O(log n) This algorithm is essentially doing a binary search to find the square root. Therefore
                                                              the runtime is O(log n)
    }
    else if(guess * guess < n) // too low
    {
        return sqrt_helper(n, guess + 1, max);
    }
    else // too high
    {
        return sqrt_helper(n, min, guess - 1);
    }

}
*/



/*
int calculate_square(int n)
{
    for(int guess = 1; guess * guess <= n; guess++)
        {
            if(guess * guess == n) ---------------------> this function runs O(sqrt(n)) in time.
                return guess;
        }
    return -1; 
}

*/

/*
If a binary search tree is not balanced, how long might it take (worst case) to find an element in it?

You are looking for a specific value in a binary tree, but the tree is not a binary search tree. What is the time complexity of this? 

*/


/*

int sumdigits(int n)
{
    int sum = 0; 
    while(n > 0) //-------------> O(log n). The runtime will be the number of digits in the number. A number with can have a value
    {                            //up to 10^d, then d = logn. Therefore, the runtime is O(log n).
        sum += n % 10;
        n /= 10; 
    }

return sum; 
    
}

*/ 

#include <vector>
#include <map>
#include <set>
// Example: Given an array of disctinct integer values, count the number of pairs of integers that have 
// difference k. For example, given the array{1, 7, 5, 9, 2, 12, 3} and the difference k = 2, there are four pairs with difference k = 2


/*


int find_num_of_pairs_with_dif_k(std::vector<int>& arr)
{
    int count = 0;
    for(int i = 0; i < arr.size() - 1; i++)
    {
        for(int j = i + 1; j < arr.size(); j++) /---------------------> O(N^2/2)
            {
                if(abs(arr.at(i) - arr.at(j)) == 2)
                    count++;
            }

    }

return count; 

}
*/ 



/*

int num_of_pairs_with_set(std::vector<int> arr)
{
    std::set<int> s; 
    int count = 0; 

    for(int x : arr)
        s.insert(x); 

    
    for(auto el : s)
        if(s.find(el + 2) != s.end())
            count++; 

return count;

}

*/ 



/*

////////USING MAP 
int num_of_pairs_with_hash(std::vector<int> arr)
{
    std::map<int, int> s; 
    int count = 0;
    for(int x : arr)
    {
        s.insert({x, 0});  
    }
                                            //----------------> O(N)

    for(auto el : s)
        if(s.find(el.first + 2) != s.end())
            count++;


return count;
}

*/ 



int main()
{



std::vector<int> vec{1, 7, 5, 9, 2, 12, 3};

//int val = find_num_of_pairs_with_dif_k(vec);

//std::cout << val << std::endl; 

// int res = num_of_pairs_with_hash(vec); 


/*

int res = num_of_pairs_with_set(vec); 

std::cout << res << std::endl; 
*/ 

//int sum_of_the_digits = sumdigits(171); 
//std::cout << sum_of_the_digits << std::endl; 




//int val = calculate_square(17);
//std::cout << val << std::endl; 



/*

int res = sqrt_root(50);

printf("the result is %d\n", res);
*/ 







}