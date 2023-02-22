/* 
Given a string, write a function to check if it's a permutation of a palindrome. A palindrome 
is a word or phrase that is the same forwards and backwards. A permutaion is a rearrangement of letters. 
The palindrome does not need to be limited to just dictionary words. You can ignore casing and none-letter
characters


Input: Tact Coa
Output: True (permutations: "taco cat", "atco cta", etc.)


 */



/* 
to solve this problem, first we need to understand what it means to be the permuation of a palindrome. 
If the string is a permutation of a palindrome, it has to be transfored into palindrome itself. 
To check if it's transferrable to a palindrome, we need to clarify the general concept of a palindrome. 

name = "talat" , the letters appearing on the left and right side of this string is repeated even times 
the letter appearing in the middle of the string has to be there one time or doesn't have to be there at all, 
in which case our string would look like this
name "taat" which is a palindrome, 

so the number of symettric elements has to be name.length() / 2, and if the string's length is even, name.length() / 2's element must be repeated only
one time, if that element is not over there, our characters only map to even countings. 


pseudocode:

    for each element in name
        -> map[el] (map them to number of occurences )
        if(name.size() % 2 == 1) // map.size to be specific 
            our map's elements should have size / 2 elements mapping to even numbers and one element should map to one 
        if(name.size() % 2 == 0)
            our map's elements should have size / 2 elements mapping to even numbers and that's all  


 */



#include <iostream>
#include <map>

bool is_it_palindrome_permutation(std::string &my_str)
{
std::map<char, int> my_map; 
int count_evens = 0; 
int count_odds = 0; 

for(auto el : my_str)
{
    if(el != ' ')
         my_map[tolower(el)]++; 

}

for(auto each : my_map)
{
    if(each.second % 2 == 0)
        count_evens++; 
    else 
        count_odds++; 
}


if((count_evens % 2 == 0) ||  (count_evens == my_map.size() - 1))
    return true; 



return false; 
}





int main()
{

std::string deneme_stringi = "Tac Coat"; 

std::cout << is_it_palindrome_permutation(deneme_stringi) << std::endl; 


}


