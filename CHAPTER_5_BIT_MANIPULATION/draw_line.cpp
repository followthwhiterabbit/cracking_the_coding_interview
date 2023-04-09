/*
A monochrome screen is stored as a single array of bytes, allowing eight consecutive pixels to be stored in one byte. 
The scren has width w, where w is divisible by 8(that is, no byte will be split across rows).The height of the screen, of course, 
can be derived from length of the array and the width. Implement a function that draws a horizontal line from (x1, y) to (x2, y).

the method signature should look something like: 
drawline(byte[] screen, int width, int x1, int x2, int y) 






*/
#include <iostream>
#include "stddef.h"




void drawline(byte screen[], int width, int x1, int x2, int y) {
    int startByte = y * (width / 8) + x1 / 8;
    int endByte = y * (width / 8) + x2 / 8;
    byte startMask = (byte) (0xFF >> (x1 % 8));
    byte endMask = (byte) ~(0xFF >> (x2 % 8 + 1));

    if (startByte == endByte) {
        screen[startByte] |= (startMask & endMask);
    } else {
        screen[startByte] |= startMask;
        screen[endByte] |= endMask;
        for (int i = startByte + 1; i < endByte; i++) {
            screen[i] = (byte) 0xFF;
        }
    }
}



int main()
{



}

