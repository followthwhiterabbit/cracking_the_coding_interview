#include <iostream>
#include <map>
#include <set>

/*
Given two strings, write a method to decide if one is a permutation of the other
  */


// the easiest way to do would be with maps 

bool check_permutation(std::string &a, std::string &b)
{
std::map<char, int> my_map; 
std::map<char, int> my_map2;

for(auto &el : a)
    my_map[el]++; // map the char to the number of occurences 

for(auto &el : b) // --------> O(n)
    my_map2[el]++;

if(my_map2 == my_map)
    return true; 

return false; 
}


bool check_permutation_another(std::string &a, std::string &b)
{

std::map<char, int > new_map; 
std::map<char, int > b_map; 

for(auto &el : a)
{
    new_map[el]++;
}

for(auto &el : b)
    b_map[el]++; 
                                                // too much for loops, it may be more clear     


for(auto &el : b)
{
    if(new_map.find(el) == new_map.end() || (new_map.find(el)->second != b_map[el]) || (b_map.size() != new_map.size()))
        return false;
}

return true; 

}


/*



bool using_sets(std::string &a, std::string &b) // -------> had a problem with sets 
{
std::set<char>  set_a; 


for(auto el : a)
    set_a.insert(el); 



for(auto &el : b)
{
    if((set_a.find(el) == set_a.end()))
        return false;

}


return true; 


}

*/ 




int main()
{

std::string str_first = "aabcd";
std::string str_second = "acdbb";


// std::cout << check_permutation(str_first , str_second) << std::endl; 
// std::cout << check_permutation_another(str_first, str_second) << std::endl; 
// std::cout << using_sets(str_first, str_second) << std::endl; 

}