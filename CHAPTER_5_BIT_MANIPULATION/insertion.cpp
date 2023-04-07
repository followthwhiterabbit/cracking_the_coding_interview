/*
You are given two 32-bit numbers, N and M, and two bit positions, i and j. 
Write a method to insert M into N such that M starts at bit j and ends at bit i. 
You can assume that the bits j through i have enough space to fit all of M. That is, 
if M = 10011, you can assume that there are at least 5 bits between j and i. You would not for example, 
have j = 3 and i = 2, because M could not fully fit between bit 3 and bit 2. 

EXAMPLE 
Input: N = 10000000000, M = 10011, i = 2, j = 6

Output: N = 10001001100
 N = 10000000000
~N = 01111111111

// clear the bits in N and then or them basically 

*/
#include <iostream>
#include <math.h>

void clearBit(int &num, int i, int j)
{
    for(int a = i; a <= j; a++)
    {
        num &= ~(1 << a); 

    }
}

int insertInside(int num, int val, int i, int j)
{
int diff = j - i + 1;

val = static_cast<unsigned int>(val); 

if(val > (std::pow(2, diff) - 1)) 
    {
        std::cout << "the value cannot be inserted."; 
        return 0; 
    }
else
    {
       val <<= (i + 1);
       val >>= (i - 1); 

    }

    return val | num; 

}

/*
    x000 00xx 

    0ppp  pp00




*/



int main()
{
int num = 255; // 1111 1111 
               
               // 1000 0011
               // 0111 1000 
               // 1111 1011 --> 1 + 2 + 8 + 16 + 32 + 64 + 128 = 
int val = 30; 

int i = 2, j = 6; 


clearBit(num, i, j); 

std::cout << insertInside(num, val, i, j); 







}




