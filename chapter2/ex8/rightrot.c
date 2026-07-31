// Write a function rightrot(x,n) that returns the value of the integer x
// rotated to the right by n bit positions.

// Side note: to "rotate", means that the bits shifted off of one end will
// be wrapped around to the other side (had to google it)

// Had to get help with this one again. I understood how to get the bit mask
// and how to get the bits in that position and that I needed to move those
// bits to the beginning, but I didn't know how to figure out the length of
// the bit value, which is what the video showed me. So I did 1 of the 3 bit
// exercises on my own ;__;

#include <stdio.h>

unsigned int rightrot(unsigned int x, int n);
int unsignedLength();

int main(){
    unsigned int x = 15;
    int n = 2;
    printf("%u\n", rightrot(x,n));
}

unsigned int rightrot(unsigned int x, int n){
    int length = unsignedLength();
    n = n % length;

    unsigned int rightNBits = x & ~(~0 << n);
    x = x >> n;

    x = x | (rightNBits << (length - n));
    return x;
}

int unsignedLength(){
    unsigned int x = (unsigned) ~0;
    int length = 0;

    while(x != 0){
        x = x>>1;
        length++;
    }

    return length;
}
