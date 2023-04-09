/*
Write a function to determine the number of bits you would need to flip to convert
integer A to integer B.

EXAMPLE
Input  29(or : 11101), 15(or: 01111)

basically count the ones in XOR 

11101
01111
xor
10010 -- 

output  = 2 


*/
#include <iostream>



bool getBit(int num, int i)
{

    return ((num & (1 << i)) != 0); 

}





int numOfBitsToSwap(int a, int b)
{

int val = a ^ b; 

int count = 0;

for(int i = 0; i < 32; i++)
{
    if(getBit(val, i) == true)
        count++; 
}
    return count; 

}


int main()
{
int a = 29, b = 15; 

std::cout << numOfBitsToSwap(a, b) << std::endl; 




}