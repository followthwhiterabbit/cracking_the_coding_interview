/*
Write an algorithm such that if an element in an M x N matrix is 0, its entire row and column are set to 0. 
*/


/*

1 2 3 4             1 2 0 4
5 6 0 8 --------->  0 0 0 0    // we need to check if one of the element is 0, for example here element (1, 2) is zero  
9 1 2 3             9 1 0 3  

then,  row 1 and column 2 will be all initialized to 0 



for every row:
    for every el:
        if(el == 0):
        { --> save the indices 
            std::fill(row.begin(), row.end(), 0) --> i can use std::fill here filling the row with 0's 
            // for column ?  

        }

                                ---------------> NOT A GOOD SOLUTION BUT FOR NOW, THAT'S THE BEST 
for(int i = 0; i < size; i++)
{
    for(int j = 0; j < size; j++)
    {
        if(i == saved.indice_first)
            {
                m[i][j] = 0; 
            }

        if(j == saved.indice_second)
            {
                m[i][j] = 0;
            }
    }


}

*/






/*
    WORKS BUT LOOKS PRETTY DIRTY 
*/

#include <iostream>
#include <vector> 
#include <algorithm>
#include <set>

void algo(std::vector<std::vector<int>> &m)
{
//std::set<int> rows; 
//std::set<int> cols; 
std::vector<int> cols; 
int col; 


for(int i = 0; i < m.size(); i++)
{
    for(int j = 0; j < m.size(); j++)
    {
        if(m[i][j] == 0)
        {
            cols.push_back(j); 
        }

    }
}


for(int i = 0; i < m.size(); i++)
{

 if(std::find(m[i].begin(), m[i].end(), 0) != m[i].end())
            {
                std::fill(m[i].begin(), m[i].end(), 0);     
            }
}



for(auto el : cols)
{
    for(int i = 0; i < m.size(); i++)
        m[i][el] = 0;


}

}



int main()
{

std::vector<std::vector<int>> vec{{1, 2, 3}, {4, 0, 9}, {7, 8, 9}, {0 , 1, 1}}; 

algo(vec); 

for(auto &el : vec)
{
    for(auto &el2 : el)
        {
            std::cout << el2 << ' '; 
        }
    std::cout << std::endl; 

}










}





