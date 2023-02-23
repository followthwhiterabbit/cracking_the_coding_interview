/*
There are three types of edits that can be performed on strings: inserting a character, 
removing a character or replacing a character. Given two strings, write a function to check 
if they are one edit or zero edit away. 


EXAMPLE:
pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bake -> false // this have two edits  
*/

#include <iostream>
#include <map>

/* 
    let's first solve this question using maps 
 */

bool is_one_away(std::string &a, std::string &b)
{
int number_of_missing = 0; 
std::map<char, int> my_map; 


for(auto &el : a)
    my_map[el]++;  


for(auto &el : b)
    {
        if(my_map.find(el) == my_map.end())
            number_of_missing++; 
    }

if(number_of_missing > 1)
    return false; 



return true; 

}


int main()
{

std::string str_1 = "pale";
std::string str_2 = "pale"; 


std::cout << is_one_away(str_1, str_2) << std::endl; 

}




