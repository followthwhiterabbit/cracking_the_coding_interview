/* 
 Given an image represented by a N x N matrix, where each pixel in the image is represented by an integer, write a method 
 to rotate the image by 90 degrees. Can you do this in place ? 

 */


/*

1 2 3       7 4 1       the element of the rows become the element of the columns of the rotated matrix 
4 5 6 --->  8 5 2        
7 8 9       9 6 3  


when we iterate the first row, we will put these elements to the last column of the result matrix one by one, 
first element (0, 0) will be in the (x, 2) where x is the index of the element in the corresponding row 

when we iterate the second row, we will put these elements to the ((N - 1) - 1)th column 

when we iterate the third row, we will put these elements to the (((N - 2)) - 1)th column

*/



#include <iostream>
#include <vector>
#include <array>
#include <algorithm>


// we will have a method here that will rotate this matrix by 90 degrees in the clock-wise direction 
// first i will program it with a copy then with a reference 
std::vector<std::vector<int>>  rotate_matrix(std::vector<std::vector<int>> m) 
{

size_t s = m.size(); 

std::vector<std::vector<int>> result_matrix(3, std::vector<int>(3, 0)); 

for(int i = 0; i < s; i++) // i will become 2 
{
    for(int j = 0; j < s; j++) // j will become 2 
    {
        result_matrix[j][s - 1 - i] = m[i][j];  

    }

}
return result_matrix; 
}


/*
to reverse the matrix in place, i can take the transpose of the matrix 

a b c           a  d  g                                                                                                 g   d   a 
d e f --------> b  e  h -------->  as you can see, the diagonal elements stayed in place, what I want matrix to be is : h   e   b 
g h j           c  f  j                                                                                                 j   f   c 
                                and i actually want the first column in the last column and the last column in the first column,
                                i can achieve the same result by reversing every row since the middle column will be intact 

*/
void return_in_place(std::vector<std::vector<int>> &m) // take the value by reference 
{

// first i need to make the matrix a transpose one 
   // since diagonal elements will be in their place, i will swap the ones upper and lower part of the diagonal line  
    for(int i = 0; i < m.size(); i++)
    {
        for(int j = i; j < m.size(); j++)
            {
                std::swap(m[i][j], m[j][i]); 
            }
    }

   // and now, i need to reverse each row  
    for(int i = 0; i < m.size(); i++)
    {
        reverse(m[i].begin(), m[i].end());  // in algorithm library 

    }

}




int main()
{

std::vector<std::vector<int>> matrix_to_be_given{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; 

std::vector<std::vector<int>> res_matrix = rotate_matrix(matrix_to_be_given); 

return_in_place(matrix_to_be_given); 

for(auto row : matrix_to_be_given)
{
    for(auto el :  row)
        std::cout << el << ' '; 
std::cout << std::endl; 

}


std::cout << "**********************" << std::endl; 

for(auto &row : res_matrix)
{
    for(auto  &col : row)
        std::cout << col << ' '; 
std::cout << std::endl; 
}

}














