// Write a function setbits(x,p,n,y) that returns x with the n bits
// that begin at position p set to the rightmost n bits of y, leaving
// the other bits unchanged.

// First time really doing bit stuff, this was hard and I had to watch a YouTube video

#include <stdio.h>

unsigned int setbits(unsigned x, unsigned int p, unsigned int n, unsigned y);

int main(){

    unsigned int x = 240;
    unsigned int y = 15;
    unsigned int p = 6;
    unsigned int n = 3;
    unsigned int result = setbits(x,p,n,y);

    printf("%d\n", result);
    return 0;
}


 unsigned int setbits(unsigned x,unsigned int p,unsigned int n, unsigned y){
    // Gives last n bits from y
    // "~0" is all 1s, then shifted over n (ex. n = 3) gives us ...11111000. And we need the shifted
    // bits to be 1s so we "~" again to flip everything and get ...00000111.
    // Doing "y &" gives us 1s in the positions that they exist for the shifted bits and nothing else.
    // So we copy the n rightmost bits.
    int lastNBits = y & ~(~0 << n);

    // Move bits into position
    // We shift the copied bits over to the position we need them to be in for x and we derive that
    // shift by taking the desired position and subtracting how many bits we are concerned with
    int setBits = lastNBits << (p - n);

    // Clear bits in x starting at postition p
    // We are trying to get to a situation where there is basically an empty chunk in the middle of the
    // x bits where we will put our copied bits from y -> 1111000000111111. We do the same shift that we
    // did earlier on y to get our group of 0s in the last n positions and then we negate that to turn
    // our last n bits into 1s. Then we shift over to the correct position. At this state we are in the
    // opposite of what we want, so we negate one more time to get our empty bit chunk where we need it.
    int cleared = ~(~(~0 << n) << (p - n));

    // "x &" with cleared will give us x's bits with the chunk missing
    x = x & cleared;

    // Adds in the 1s from y (where the chunk is)
    return x | setBits;
}
