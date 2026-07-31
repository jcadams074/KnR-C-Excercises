//Write the function any(s1,s2), which returns the first location in the string s1 where
//any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
//The standard library function strpbrk does the same job but returns a pointer to the location.

#include <stdio.h>

int any(char s1[], char s2[]);

int main(){
    char s1[] = "My Party";
    char s2[] = "Pizza";
    char s3[] = "Goucho";

    int result1 = any(s1,s2);
    int result2 = any(s1,s3);

    // Expected result: 3
    printf("%d\n", result1);

    // Expected result: -1
    printf("%d\n", result2);

    return 0;
}

// Super basic and terrible double for loop bc idk
int any(char s1[], char s2[]){
    int i;
    int j;

    for(int i = 0; s2[i] != '\0'; i++)
        for(int j = 0; s1[j] != '\0'; j++)
            if(s1[j] == s2[i])
                return j;

    return -1;
}
