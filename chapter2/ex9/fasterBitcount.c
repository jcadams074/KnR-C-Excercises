// In a two's compliment number system, x &= (x-1) deletes the rightmost 1-bit in
// x. Explain why. Use this observation to write a faster version of bitcount.

// Explanation:
/*
    Binary addition and subtraction works by flipping from 0 to 1 a single bit at a time
    moving from right to left, or left to right, respectively. For example if I have the number
    5 in binary form (0101) and I want to add 1 (0001) to it to make it 6, I will work from the right
    and move  left:
        The rightmost bit is 1, so we can't add to that section. Therefore we will flip that bit to
        0 and the adjacent bit to 1. This gives us 0110, which is 6. To make it 7, we would add 1 and
        get 0111. 8 would be 1000, 9 - 1001, etc.
    Subtraction works the opposite direction: 9 is 1001, but subtract one (flip that right bit to 0) to get
    1000, which is 8. Subtract another 1 and now we have 0111, which is 7. Another illustration:
        Why does 0111 become 1000 when we add 1, and why does 1000 become 0111 when we subtract 1? For addition
        it's simply because the value has nowhere else to go than to the next position. Flipping any single existing
        1-bit in 0111 to 0 will set us back to a number LOWER Than what we started with. Likewise when we subtract
        from 1000, we can't just set the lone 1-bit to 0 because that would give us a value of 0. We've moved back
        to the lower postition, but to the highest amount of which that position is capable of, so we need to set the
        three remaining bits to 1. This is the same concept between the ones, tens, hundreds, etc. place in a base-10
        number system.

    So, in x &= (x-1) the x-1 operation will always remove the rightmost existing bit because of the principle outlined above and will leave
    a mask of the result, which is then copied over to x. The & operation will only keep a bit if both x and the result of x-1 have that bit
    as 1. The place where the rightmost 1-bit is in x is a 0 in the mask and thus will not be kept. So if x is 6 and its bits are 0101, subtract 1
    to get 0100, take the & of that and x and we're left with x = 0100, thus removing the rightmost bit.

    I suck so bad at explaining things I hope this is good. Like I understand it but I can't articulate it. I just want
    to say that "it's like that way because of how it is".

*/

#include <stdio.h>

int bitcount(unsigned int x);

int main(){
    unsigned int x = 874392;
    int result;

    result = bitcount(x);
    printf("%d\n", (result));
    return 0;
}

int bitcount(unsigned int x){
    int b;

    while(x != 0){
        x &= x-1;
        b++;
    }

    return b;
}
