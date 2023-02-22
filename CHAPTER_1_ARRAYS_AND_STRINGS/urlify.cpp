/* 
Write a method to replace all spaces in a string with '%20'. You may 
assume that the string has sufficient space at the end to hold the 
additional characters and that you're given the true lentgth of the string 


Input: "Mr John Smith", 13
Output: "Mr%20John%20Smith%20"

*/


#include <iostream>
#include <vector>

/*
first solution 
to solve this problem we can create an emty string and after dividing each words one by one, 
concatenate them with %20 and then returning new string 

 */


std::string urlify(std::string input_str)   // without taking the size 
{

std::string new_str; 
std::string word;

// std::vector<std::string> words; 

for(int i = 0; i < input_str.length(); i++)
{
if(input_str[i] != ' ') ///////////////------------> O(N)
{
    word += input_str[i];
    if(i == input_str.length() - 1)
        new_str += word;  
}
else 
{
    new_str += word + "%20"; 
    word.clear();
}

}

return new_str; 
}


// second solution  
void urlify_the_second(std::string &input_str) // take the string by reference, so without copy, i will come back here 
{


}


int main()
{
std::string input =  "Mr John Smith";

//std::cout << urlify(input) << std::endl; 
urlify_the_second(input); 
std::cout << input << std::endl; 


}