/*
Explain what the following code does: ((n & (n-1)) == 0).


let's say our value is sth like, abcde1100 then val - 1 will look like 
                                 abcde1011 // since we decrease by one we know that abcde should be the same, let's assume they are all 0's 
                               & ----------
                                 000001000 --> this is not 0

                                abcde0100 // let's say our value looks like this
                                abcde0011 // val - 1 looks like this 
                            &  ----------
                                000000000 // now assuming abcde all equals 0 and val - 1 looks like as 000000011, we see that we get 0's as result 

                            // now we see that val is the power of 2, 2 to the power of 2 in our example 

a & b == 0 means that values a and be has no common 1s like 
a ---> 00111010
b ---> 11000101 or 00000000 or 11000100 -- there are many possibilities 

*/

