/*
Assume you have a method isSubstring which checks if one word is a substring of another. 
Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call 
to isSubstring(e.g, "waterbottle" is a rotation of "erbottlewat")
                    "elttobretaw:
*/

/*

we have a string "waterbottle" and "erbottlewat" is the rotation of this string  because:

erbottle + wat  is the rotaion of wat + erbottle 
  /|\      /|\--------------------/|\      /|\
   |----------------------------------------| 
        s2                             s1

waterbottle + waterbottle == if we concatenate the original string, 
if the second string is the rotation of the first one, it is supposed to be inside of it, as in the case of, 

wat(erbottlewat)erbottle     == s2 is inside of s1s1 as you cna see in the left  
   -----------


we will have an algorithm that will take two strings, it will duplicate the first string and then 
look for the second string inside the first string, if found, it will return true, otherwise 
it will return false 


bool function algo(str1 ,str 2)
{

newstr = str1 + str1; // concatenating the first string 

if(str1.len() != str2.lend() || str1.len() == 0)
    return false;

if(newstr.find(str2) != std::string::npos)
{
    return true
}
else
    return false; 

}

*/


#include <iostream>

bool algo(std::string str1, std::string str2)
{

std::string newstr = str1 + str1; // concatenating the first string 

if(str1.length() != str2.length() || str1.length() == 0)
    return false;

if(newstr.find(str2) != std::string::npos)
    return true; 
else
    return false; 

}

int main()
{


std::string string1 = "waterbottle";
std::string string2 = "erbottlewat"; 

bool val = algo(string1, string2); 

std::cout << (val ? "str 2 is the rotation of str 1" : "str2 is not the rotation of str1");




}