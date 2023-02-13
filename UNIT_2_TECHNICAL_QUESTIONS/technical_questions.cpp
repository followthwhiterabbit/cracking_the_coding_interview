#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <algorithm>




/*

Print all positive integer solutions to the equation a^3 + b^3 = c^3 + d^3 where
a, b, c and d are integers between 1 and 1000. 

n = 1000
for a from 1 to n
    for b from 1 to n
        for c from 1 to n
            for d from 1 to n ------------------> O(N^4)
                if a^3 + b^3 = c^3 + d^3
                    print a, b, c, d
                    break // brek out of d's loop

This wont make a meaningful change to the runtime - our algorithm is still O(N^4) - but it's still
a good quick fix to make. 


We can get rid of last for loop with


for a from 1 to n
    for b from 1 to n
        for c from 1 to n
            d = pow(a^3 + b^3 + c^3, 1/3) will round to int  --------------------------------> O(N^3)
            if a^3 + b^3 == c^3 + d^3 && 0 < d && d <= n // validate that the value works
                print a, b, c, d


n = 1000
for c from 1 to n
    for d from 1 to n
        result = c^3 + d^3
        append(c, d) to list at value map[result]

for a from 1 to n
    for b from 1 to n
        result = a^3 + b^3
        list = map.get(result)





Optimize & Solve technique #2: DIY(Do It Yourself)

The first time you heard about how to find and element in a sorted array(before being taught binary search), 
you probably didn't jump to, we'll compare the target element to the midpoint and then recurse on the appropirate half. 


std::vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}


function binary_search(sorted vector, min, max, element)

mid = (min + max) / 2

if(vec[mid] == element)
    print "element found"
else if(vec[mid] < element)
   binary_search(sorted vector, mid+1, max, element)
else if (vec[mid] > element)
    binary_search(sorted_vector, min, mid - 1, element)



return element


*/ 


/*




void binary_search(std::vector<int> &arr, int min, int max, int element)
{

int mid = (min + max) / 2; 

if(arr.at(mid) == element)
    std::cout << "element found at " << mid << std::endl; 
else if(arr.at(mid) < element)
    binary_search(arr, mid + 1, max, element); 
else if(arr.at(mid > element))
    binary_search(arr, min, mid - 1, element);



}


*/

/*
Given a smaller string s and a bigger string b, design an algorithm to find all permutaions of the shorter string
within the larger one. Print the location of each permutation. 

S: abbc
b: cbabadcbbabbcbabaabccbabc





void find_permutations(string s, string b)

map S from char to individual int values 

using sliding window, iterate over b and for every 4 chars
    throw a hash map from individual chars to ints and check if keys are the same and values are also equal 
    if so 
        create another hash map from these substrings to integer frequencies
            only take the keys  


end 



*/


/*



void find_permutations(std::string s, std::string b)
{

    std::map<char, int> smap; 
    std::map<char, int> bmap;
    std::map<std::string, int> rmap; 
    std::string result_string; 

    for(int i = 0; i < s.size(); i++)
    {
        smap[s[i]]++; 
    }


    for(int i = 0; i < b.size() - 4; i++ )
        {
           for(int j = i; j < i + 4; j++)
                {
                    bmap[b[j]]++;
                    result_string += b[j]; /// ----- > O(N^2)
                }

            if(smap == bmap & result_string != s)
                rmap[result_string]++; 

                bmap.clear(); 
                result_string.clear(); 
        }

    for(auto el : rmap)
        std::cout << el.first << std::endl; 

}

*/ 


/*
Example: A ransom note can be formed by cutting words out of a magazine to form a new ------------>IMPLEMENT THIS 
sentence. How would you figure out if a ransom note (represented as a string) can be formed
from a given magazine (string)?



Example: Design an algorithm to print all permutations of a string. For simplicity, assume all characters are unique. 
Consider a test string abcdefg

Case "a" ---> {"a"}
Case "ab" ---> {"ab", "ba"}
Case "abc" ---> {"", "", ""} // we can insert c basically everywhere inside this string S ---> IMPORTANT, IMPLEMENT THIS 


Example: Numbers are randomly generated and stored into an (expanding) array. How would you keep track of the median?



                                    9
                                 /    \ 
                                8       6 
                             /   \    /   \   
                             7     4  5    2
                           /   \ 
                          0    3   1    




                                    9 
                                  /  \ 
                                5     4 
                               /  \  / \  
                             1    1  3  2  
                                            ----> 6 doesn't meet the condition for a max heap 


*/


/*
Question: Given two sorted arrays, find the nubmer of elements in common. The arrays are the same length and each has all distinct elements. 
Let's start with a good example.

A: 13 27 35 40 49 55 59
B: 17 35 39 40 55 58 60

// they are sorted already 

What we assume: The arrays are the same length and each has all distinct elements.  



O(N^2) SOLUTION 

for each element in A:
    for each element in B:
        if (element in A == element in B)
            count++; 



O(N solution)

for each element in A:
    map[element]++; 

for each element in B:
    map[element]++; 


these maps have different keys. 
for(auto el : mapA):
    {
        auto it = mapB.find(el.first);
        if(it != mapB.end())
            count++; 
    }







*/




/*

O(N^2)


int return_number_of_elements_in_commont(std::vector<int> &a, std::vector<int> &b)
{

int counter = 0; 

for(int i = 0; i < a.size(); i++)
{
    for(int j = 0; j < b.size(); j++)
    {
        if(a[i] == b[j])
            {
               counter++; 
               break; 
            }
    }
 
}

return counter; 

}

*/ 



/*



// We can also implement the same algorithm with O(N * logN)


Brute Force: O(N^2)
This algorithm will be O(n * logn)


// we assume that the elements are in sorted order




std::vector<int> A{13, 27, 35, 40, 49, 55, 59};
std::vector<int> B{17, 35, 39, 40, 55, 58, 60};






*/ 


/*

//THIS CHATGPT OUTPUT WORKED !!!

int common_elements(std::vector<int> a, std::vector<int> b) {
    int n = a.size();

    int m = b.size();

    int i = 0, j = 0, count = 0;

    while (i < n && j < m) {

        if (a[i] == b[j]) { // if ith and jth elements are equal we increase the count and move on 

            count++;
            i++;
            j++;

        } else if (a[i] < b[j]) {  // if a[i] is less than b[j] , i++

            i++;
        } else { // if a [i] is greather than b[j], we just increase j until condition is not satisfied 
            j++;
        }
    }
    return count;
}
*/ 
// chat gpt bug fix output

/*
// this chat gpt fix of my code rturns 4 instead of 3


int return_number_of_elements_in_common(std::vector<int> a, std::vector<int> b, int min, int max)
{
    int counter = 0;

    if (min > max)
        return 0;

    int mid = (min + max) / 2;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[mid])
        {
            counter++;
            break;
        }
        else if (a[i] < b[mid])
        {
            counter += return_number_of_elements_in_common(a, b, min, mid - 1);
        }
        else if (a[i] > b[mid])
        {
            counter += return_number_of_elements_in_common(a, b, mid + 1, max);
        }
    }

    return counter;
}

*/ 


/*

I TRIED THIS BUT IT DIDNT WORK AS INTENDED
int return_number_of_elements_in_commont(std::vector<int> a, std::vector<int> b, int min, int max, int element)
{
    int counter = 0; 

    int mid = (min + max) / 2; 

    // we will recursively  search for every element of a inside b 
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] > b[mid])
            {
                int val = return_number_of_elements_in_commont(a, b, mid + 1 , max, a[i]); 
            }
        else if(a[i] < b[mid])
            {
                int val = return_number_of_elements_in_commont(a, b, min, mid - 1, a[i]); 
            }
        else if(a[i] == b[mid])
            {
                counter++; 
            }

    }

   return counter; 
}


*/ 


/*

O(N) runtime

int return_number_of_elements_in_commont(std::vector<int> &a, std::vector<int> &b)
{

    std::map<int, int> mapa, mapb; 
    int counter = 0; 

    for(int el : a)
        mapa[el]++; 

    for(int el : b)
        mapb[el]++; 

    for(auto el : mapa)
        {
            auto it = mapb.find(el.first);
            if(it != mapb.end())
            counter++; 
        }
    return counter; 
}

*/ 



//there is also another way to find the total number of common elements 
//O(N) time 
/*
// WORKS 

int return_number_of_elements_in_common(std::vector<int> &a, std::vector<int> &b)
{
    std::map<int, int> mapb; 
    int counter = 0;

    for(auto el : b)
        mapb[el]++; 

    for(auto el : a)
    {
        auto it = mapb.find(el); // o(1)
        if(it != mapb.end()) 
            counter++; 
    }
    return counter; 
}

//This is another place where BCR is useful. It tells us that we're "done" in terms of optimizing the 
//big o time. We could potentially optimize the space complexity. So after optimizing the time complexity
//optimize the space complexity. 

*/ 


/*
// i am supposed to write an algorithm in O(n) time with linear search -----------> CHECK LATER

int return_number_of_elemets_in_linear_search(std::vector<int> &a, std::vector<int> &b)
{

    int counter = 0;

    for(int i = 0; i < a.size(); i++)
    {



    }


}
new changes
*/




int main()
{

std::vector<int> A{13, 27, 35, 40, 49, 55, 59};
std::vector<int> B{17, 35, 39, 40, 55, 58, 60};


// std::cout << return_number_of_elements_in_commont(A, B);

// std::cout << return_number_of_elements_in_common(A, B, 0, 6); // this shit returns 4 



// std::cout << common_elements(A, B);


// std::cout << return_number_of_elements_in_common(A, B) << std::endl; 


//    std::vector<int> v { 3, 1, 4, 1, 5, 9 };
 
    //std::make_heap(begin(v), end(v));

    //v.push_back(2); 
    //v.push_back(6);

    //auto heap_end = std::is_heap_until(v.begin(), v.end()); 


    //for(auto el : v)
        //std::cout << el << ' '; 


    //std::cout << std::endl; 

    
    //for(auto i = v.begin(); i != heap_end; ++i)
        //std::cout << *i << ' '; 

    











/*

std::allocator<int> a1; // default allocator for ints 
int* a = a1.allocate(1); // space for some int 
a1.construct(a, 1); 

std::cout << *a << std::endl; 
*/ 




/*


std::string s = "abbc";
std::string b = "cbabadcbbabbcbabaabccbabc"; 


find_permutations(s, b); 

*/ 

    /* 
    
     

    std::map<unsigned, std::pair<int, int>> mypair; 

    mypair.insert(std::make_pair(100, std::make_pair(10, 10))); 


    for (auto el : mypair)
        std::cout << el.first << ' ' << el.second.first << ' ' << el.second.second << std::endl; 

 
    */ 


/*


std::vector<int> my_vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; 

int max = my_vec.size() - 1; 
int min = 0; 

binary_search(my_vec, min, max, 9);  

*/ 



/*



   int n = 1000; 
   int result; 
   std::map<int, std::pair<int, int>> mypair; 



    for(int c = 0; c < 1000; c++)
        for(int d = 0; d < 1000; d++)
            {
                result = c^3 + d^3; 
                mypair.insert(std::make_pair(result, std::make_pair(c, d)));
            }

    for(int a = 0; a < 1000; a++)
        for(int b = 0; b < 1000; b++)
            {
                result = a^3 + b^3; 
                auto our_pair = mypair[result];
                if(a == our_pair.first || a == our_pair.second && b == our_pair.first || b == our_pair.second &&  a != 0 && b != 0 && our_pair.first > 0 && our_pair.second > 0 && a != b && our_pair.first != our_pair.second && a != our_pair.first && b != our_pair.second)
                    std::cout << a << ' ' << b << ' ' << our_pair.first << ' ' << our_pair.second << std::endl;  
            }


*/



}




