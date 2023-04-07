/*
Given a real number between 0 and 1(e.g 0.72) that is passed in as a double, print 
the binary representation. If the number cannot be represented accurately in binary with at most 32 characters, print "ERROR"

*/

#include <iostream>


void printBinRepresentation(float &num)
{

    unsigned int bits = *reinterpret_cast<unsigned int*>(&num); 

    for(int i = 31; i >= 0; i--)
    {
        std::cout << ((bits >> i) & 1); 
    }
   std::cout << std::endl;  

}


int main()
{
    float num = 0.25; 

    printBinRepresentation(num); 




}


