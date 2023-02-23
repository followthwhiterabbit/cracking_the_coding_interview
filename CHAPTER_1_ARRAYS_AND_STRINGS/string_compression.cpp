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
#include <map>


int main()
{
    //std::multimap<char, int> multi_map; 
    std::string my_str = "aabcccccaaa"; 
    std::string res = "";
    std::map<char, int> my_map;


    for(auto &el : my_str)
        my_str[el]++;


    int count_value = 1; 


    for(int i = 0; i < my_str.size() - 1; i++)
    {

        if(my_str[i] == my_str[i+1])
            count_value++;
        else if(my_str[i] != my_str[i+1])
            {
                    res += my_str[i] + std::to_string(count_value); 
                    count_value = 1;
            }
     }


    std::cout << res << std::endl; 


}

