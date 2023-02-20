#include <iostream>
#include <map>

/*
Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures ? 
  */


bool is_unique(std::string my_str)
{
std::map<char, int> my_map;  //  this map is supposed to map the chars of the strings to the number of counts, we expect the number count of chars to be 1

for(auto &el : my_str) // I don't check for the spaces 
{
    if(el == ' ')
        continue;
    else
        my_map[el]++; 
}

                                    // Time Complexity O(N) 
for(auto el : my_map)
{
    if(el.second  > 1)
        return false;  
}

return true; 
}


bool  is_unique_brute_force(std::string my_str) // we can check if a string has multiple chars in it with simple brute forcing
{
    for(int i = 0; i < my_str.size(); i++)
    {
       for(int j = i + 1; j < my_str.size(); j++)
            {                                   // --------> O(N^2)
              if(my_str[i] == my_str[j])
                return false;  
            }
}
    return true; 
}


// we can also use an array of boolean values to check if we have reached true boolean array value before, if so, we can 
// return false 

const int max_char = 128;  

bool is_unique_using_char_arr(std::string my_str) // I don't know what is wrong with this, because it didn't work, update - works now 
{
    if(my_str.size() > 128)
        return false; // if the size is greater than the maximum size of our char values, one of the characters must be repeated 

    bool char_to_int_arr[max_char] = {0}; // first we put 0's to all of the array elements 
    
    for(int i = 0; i < my_str.size(); i++)
    {
        if(char_to_int_arr[int(my_str[i])] == true) // if that place is filled with true beforehand, we return false since the array already has that element
            return false;

        char_to_int_arr[int(my_str[i])] = true;  // we iterate our string and fill our char_to_int_arr with boolean value of 1 if the value is unique
    }    

return true; 
}

// let me think another way to solve this problem without data structes such as map or set 
// maybe using bits, i'll come back here again

int main()
{

std::string example_string = "skaan";

// std::cout << is_unique(example_string) << std::endl; 

// std::cout << is_unique_brute_force(example_string) << std::endl; 


std::cout << is_unique_using_char_arr(example_string) << std::endl;




}