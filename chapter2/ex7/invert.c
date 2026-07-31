// Write a function invert(x,p,n) that returns x with the n bits that begin at
// position p inverted(i.e 1 changed into 0 and vice versa), leaving all others unchanged

// This one was much easier but I'm sure I'll regret not writing my notes down

#include <stdio.h>

unsigned int invert(unsigned int x, unsigned int p, unsigned int n);

int main(){
    unsigned int x = 18; //0001 0010
    unsigned int p = 6;
    unsigned int n = 3;

    //expecting 0010 1010
    unsigned int result = invert(x,p,n);

    printf("Input: %b\n", x);
    printf("Output: %b\n", result);

    return 0;
}

unsigned int invert(unsigned int x, unsigned int p, unsigned int n){

    // Answer is slightly different if you consider the rightmost bit to be bit 0 or bit 1.
    // This assumes it is bit 0 bc thats what K&R assumes
    return x ^ (~(~0 << n) << (p + 1 - n));

}
