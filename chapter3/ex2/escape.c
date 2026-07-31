/*
Write a function escape(s,t) that converts characters like newline and tab into visible escape
sequences like \n and \t as it cpies the string t to s. Use a switch.  Write a function for the other
direction as well, coverting escape sequences into the real characters.
*/

#include <stdio.h>

char* escape(char s[], char t[]);
char* reverseEscape(char s[], char t[]);

int main(){
    char s[] = "boopityBop";
    char t[] = "H\\tello\\nWorld";

    // char* c = escape(s,t);
    char* r = reverseEscape(s,t);

    // printf("%s\n", c);
    printf("%s\n", r);

    return 0;
}

char* escape(char s[], char t[]){
    int i,j;

    for(i,j = 0; s[i] != '\0'; i++){
        switch(t[j]){
            case '\n':
                s[i] = '\\';
                s[++i] = 'n';
                break;
            case '\t':
                s[i] = '\\';
                s[++i] = 't';
                break;
            default:
                s[i] = t[j];
        }
        j++;
    }

    return &s[0];
}

char* reverseEscape(char s[], char t[]){
    int i,j;

    for(i,j = 0; s[i] != '\0'; i++){
        printf("%", t[j]);
        if(t[j] == '\\'){
            switch(t[++j]){
                case 'n':
                    s[i] = '\n';
                    s[j] = ' ';
                    break;
                case 't':
                    s[i] = '\t';
                    s[j] = ' ';
                    break;
            }
        }else{
            s[i] = t[j];
        }
        j++;
    }

    return &s[0];
}
