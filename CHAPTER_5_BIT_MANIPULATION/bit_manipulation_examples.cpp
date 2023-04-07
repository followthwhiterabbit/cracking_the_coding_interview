/*




*/
#include <iostream>




int repeatedArithmeticShift(int x, int count)
{
    for(int i = 0; i < count; i++)
    {
        x >>= 1; // arithmetic shift // this fills the leftmost most significant part of the number with 1s 

    }
    return x; 
}

int repeatedLogicalShift(int x, int count)
{
   // to implement a logical shift in c++, first, we need to cast the value x to an unsigned int value
   // because by default, it's gonna fill the most significant part with 1s if it is signed 

    unsigned int ux = static_cast<unsigned int>(x); 

    for(int i = 0; i < count; i++)
    {
        ux >>= 1; 
    }

return ux; 
}

bool getBit(int num, int i)
{
    return ((num & (1 << i)) != 0); 
}

bool setBit(int num, int i)
{
    return num | (1 << i); 
}

// we have the num such as 01010101 ==  1 + 4 + 16 + 64 ==  85
// and we want to clar the 5th bit lets say
// we will and this with   11101111   == 85 - 16 = 69 == what we expect  
// so we need to shift 5 bits and then reverse it and and it with num 


int clearBit(int num, int i)
{

int masking =  ~(1 << i); 

return num & masking; 


}


// for example if we have 00010000 == 16
//                        00001111 == now we take ~ = 11110000 // we will clear the last 4 bits with this 

int clearBitsMsbThrough0(int num, int i)
{
    int masking = ~((1 << i) - 1);
    return num & masking; 
}

// if you and it with the upper part like in
int clearBitsMsbThroughI(int num, int i )
{
    int masking = ((1  << i) - 1); 

    return num & masking; 

}


int updateBit(int num, int i, bool bit)
{
    int mask = 1 << i; 
    if(bit)
    {
        num |= mask;  
    }
    else
    {
        num &= ~mask; 
    }
    return num; 
}




int main()
{
int val = -93242, count = 40; 


std::cout << repeatedArithmeticShift(val, count) << std::endl; 
std::cout << repeatedLogicalShift(val, count) << std::endl; 


int val2 = 32, bitnum = 8; 
int val3 = 0; 

for(int i = 7; i >= 0; i--)
{
    std::cout << getBit(val2, i); 

}
std::cout << std::endl; 

for(int i = 7; i >= 0; i--)
{
    std::cout << setBit(0, i); 

}
std::cout << std::endl; 


std::cout << clearBit(85, 4) << std::endl; 

std::cout << clearBitsMsbThrough0(85, 4) << std::endl; 

std::cout << clearBitsMsbThroughI(85, 4) << std::endl; 


}




