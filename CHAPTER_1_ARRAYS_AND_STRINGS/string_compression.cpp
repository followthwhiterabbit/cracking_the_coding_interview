/* 
Implement a method to perform basic string compression using the counts of repeated characters. 
For example, the string aabcccccaa would become a2b1c5a3. 

Input : aabcccccaaa
Output: a2b1c5a3


if(output.len() > input.len())
    return input
else
    return output


 */
#include <iostream>


std::string string_compression(std::string &my_str)
{
    int count_value = 1; 
    std::string res = "";

    for(int i = 0; i <= my_str.size() - 1; i++)
    {

        if(my_str[i] == my_str[i+1])
            count_value++;
        else if(my_str[i] != my_str[i+1])
            {
                    res += my_str[i] + std::to_string(count_value); 
                    count_value = 1;

            }
     }

    if(res.length() > my_str.length())
        return my_str; 
    else
        return res; 


}







int main()
{
    //std::multimap<char, int> multi_map; 
    //std::string my_str = "aabcccccaaa"; 
     std::string my_str = "kkkaaabbbcccdddkkk"; 

    std::cout << string_compression(my_str) << std::endl; 
   


}

