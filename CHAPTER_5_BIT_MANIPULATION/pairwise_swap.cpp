/*
 * Write a program to swap odd and even bits in an integer with as few instructions as possible.(e.g
 * (bit 0 and bit 1 are swapped,bit 2 and bit 3 are swapped.
 *
 * 
 * 
 * 
 * let's say we have a value like 0x000 000A which is 0000 0000 0000 0000 0000 0000 0000 1010 --> 4 bytes 

 * since we will swap odd bits with the even bits, first we need to mask them with 0xAA to take only the odd bits which have 1 or 0 

    then we will shift them to the right 

 * 

// we expect 10 to return 5, 5 to return 10 
  
 * 
 * 
 * 
 */ 
#include <iostream>


int swapEvenOddBits(int val)
{

    return (((val & 0xAAAAAAAA) >> 1) | (val & 0x55555555) << 1);  
     
}
 




int main()
{

std::cout << swapEvenOddBits(10) << std::endl; 



}



