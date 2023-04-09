/*
Given a positive integer, print the next smallest and the next largest number that 
have the same number of 1 bits in their binary representation. 

// 00010001 -->  17

// next smallest one is achieved when the fifth bit is placed on the fourth bit and the first bit stays the same 
// next smallest --> 9 
// next largest one is achieved when the first bit is placed on the second bit 
// next largest -->  18


// so basically to find the next largest one we need to check from the right side of the bits and find the first 0 bit and replace it with 1
// to find the next smallest bit, we need to check from the left side, if we found the first "1", we need to change its place to the right side 


// I'll solve this problem later on, i need to think about the implementation 





*/