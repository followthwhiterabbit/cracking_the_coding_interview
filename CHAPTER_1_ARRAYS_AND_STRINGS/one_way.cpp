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


/*

// this is wrong 

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

*/ 

bool isOneAway(std::string s1, std::string s2)
{
    std::string a, b; 
    a = s1.length() >= s2.length() ? s1 : s2; // a holds the greatest value 
    b = s1.length() < s2.length() ? s1 : s2; // b holds the lower value  


    int len1, len2; 
    len1 = a.length(); // bigger value
    len2 = b.length();  

    if(abs(len1 -  len2) > 1) // if the changes are more than one, it's supposed to return false
        return false;

    bool flag = false; 


    for(int i =0, j=0; i < len1 && j < len2;) // bares, pale 
    {
        if(a[i] != b[j])
            {
                if(flag)
                    return false;
                flag = true; 
                if(len1 == len2)
                    i++, j++; 
                else
                    i++; 
            }
        else
            i++, j++; 
    }

return true;

}




int main()
{

std::string str_1 = "pbale";
std::string str_2 = "bale"; 


//std::cout << is_one_away(str_1, str_2) << std::endl; 
std::cout << isOneAway(str_1, str_2) << std::endl; 
}




