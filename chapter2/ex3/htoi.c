// Exercise 2-3 on page 48
// Converts a string of hexadecimal digits (including optional 0x or 0X) into its equivalent integer value
// Allowable digits are 0 - 9, a - f, and A - F

#include <stdio.h>
#include <math.h>

long htoi(char[]);
int getNumericValueFromChar(char s);

int main(){

    char s[] = "0x884db1e";
    printf("Hexidecimal value %s\n",s);

    long decimalVal = htoi(s);
    if(!decimalVal == '\0')
        printf("Output Decimal Value: %ld\n", decimalVal);

    return 0;
}

long htoi(char s[]){

    long decimalVal = 0;
    int i = (s[1] == 'x' || s[1] == 'X') ? 2 : 0;
    int length = i;

    for(length; s[length] != '\0';)
        length++;

    if(length > 18 || (length == 18 && (s[2] - '0') > 7)){
        printf("Invalid hexadecimal input: Number too large to be signed. Execution aborted\n");
        return '\0';
    }

    for (i; i < length; i++){
        double power = length - (i+1);
        int numericValue = getNumericValueFromChar(s[i]);

        if(numericValue < 0){
            printf("Invalid hexadecimal input: Non-hexidecimal character '%c' encountered. Execution aborted\n", s[i]);
            return '\0';
        }

        decimalVal += (numericValue * pow(16,power));
    }
    return decimalVal;
}

int getNumericValueFromChar(char s){
    int returnVal = -1;

    // All numeric characters have a decimal representation of 30 - 39, thus subtracting the character '0' (which is 30) will give
    // us a decimal value between 0 and 9 if the original character was in fact a number in character representation:
    int decimalVal = s - '0';

    if(decimalVal >= 0 && decimalVal <= 9){
        returnVal = decimalVal;
    }else{
        if(s == 'a' || s == 'A')
            returnVal = 10;
        else if(s == 'b' || s == 'B')
            returnVal = 11;
        else if(s == 'c' || s == 'C')
            returnVal = 12;
        else if(s == 'd' || s == 'D')
            returnVal = 13;
        else if(s == 'e' || s == 'E')
            returnVal = 14;
        else if(s == 'f' || s == 'F')
            returnVal = 15;
    }

    return returnVal;
}

