/*
You have an integer and you can flip exactly one bit from a 0 to 1.
Write code to find the length of the longest sequence of 1s you could create. 


first we need to analyze our bit positions to insert our "1" to the most suitable place. 

EXAMPLE
1775 ----> 11011101111 

we can have a vector storing longest 1 sequences and check which side has the most 1's. 
for example for above, this vector would look like
std::vector<int> one_counts{2, 3, 4}, as you can see, 3 and 4 are greater than 2 and 3 so we will insert our one between these values.  


*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

bool getBit(int num, int i)
{
    return ((num & (1 << i)) != 0);
}


int setBit(int &num, int bit_to_be_set)
{
std::vector<int> vec_of_ones;

int one_count = 0; 

num |= (1 << bit_to_be_set);

for(int i = 0;  i < 32; i++)
{

if(getBit(num, i) == true)
    one_count++;
else 
    {

    if(one_count >= 1)
    {
        vec_of_ones.push_back(one_count); 
        one_count = 0; 
    }
    }

}   

int max = vec_of_ones[0]; 
for(int i = 1; i < vec_of_ones.size(); i++)
{
    if(vec_of_ones[i] > max)
        max = vec_of_ones[i]; 

}
return max; 


}
 

int flip_bit_to_win(int num)
{
int one_count; 
std::map<int, int> mapping_loc; 

for(int i = 0;  i < 32; i++)
{

if(getBit(num, i) == true)
    one_count++;
else 
    {

    if(one_count >= 1)
    {
        mapping_loc.insert(std::pair<int, int>(one_count, i)); 
        one_count = 0; 
    }
    }

}


std::map<int, int>::iterator biggest = std::max_element(mapping_loc.begin(), mapping_loc.end(), [](const std::pair<int, int>&a, const std::pair<int, int>&b)
{
    return a.second > b.second; 
}
); 

 int returned_count = setBit(num, biggest->second);


return returned_count; 



}


int main()
{

std::cout << flip_bit_to_win(1775) << std::endl; 


}
