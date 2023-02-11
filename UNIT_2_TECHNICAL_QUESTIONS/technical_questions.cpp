#include <iostream>
#include <map>
#include <vector>

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




int main()
{

    /* 
    
     

    std::map<unsigned, std::pair<int, int>> mypair; 

    mypair.insert(std::make_pair(100, std::make_pair(10, 10))); 


    for (auto el : mypair)
        std::cout << el.first << ' ' << el.second.first << ' ' << el.second.second << std::endl; 


    */ 

std::vector<int> my_vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; 

int max = my_vec.size() - 1; 
int min = 0; 

binary_search(my_vec, min, max, 9);  





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




