// Write an alternate version of squeeze(s1, s2) that deletes each character in s1
// that matches any character in the string s2.

#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    char item;
    struct tree *parent;
    struct tree *left;
    struct tree *right;
} tree;

tree* charChachTree;

char* squeeze(char s1[], char s2[]);
char findCharInString(char s[], char c);
tree* searchTree(tree *l, char c);
void insertTree(tree **l, char c, tree *parent);

int main(){
    char stringOne[] = "Hello, World";
    char stringTwo[] = "Hola, Mundo";

    // Expected result string = eWr
    char *resultString = squeeze(stringOne, stringTwo);

    printf("%s\n", resultString);
    return 0;
}


char* squeeze(char s1[], char s2[]){
    int i,j;

    for(i = j = 0; s1[i] != '\0'; i++){
        if(searchTree(charChachTree, s1[i]) == NULL)
            if(findCharInString(s2, s1[i]) == '0')
                s1[j++] = s1[i];
    }

    s1[j] = '\0';

    return &s1[0];
}

char findCharInString(char s[], char c){
    int i;

    for(i = 0; s[i] != '\0'; i++)
        if(s[i] == c){
            insertTree(&charChachTree, c, NULL);
            return '1';
        }

    return '0';
}


// BST functions for caching found characters and avoiding repetative search
// I stole these from the algorithm design manual, but the idea to include them
// at all was mine so I will take partial credit for good design :)

// The inclusion of this stuff is totally not needed and kinda extra because
// the book has not covered pointers at this point

tree* searchTree(tree *l, char c){
    if (l == NULL)
        return (NULL);

    if (l->item == c)
        return (l);

    if(c < l->item)
        return(searchTree(l->left, c));
    else
        return(searchTree(l->right,c));
}

void insertTree(tree **l, char c, tree *parent){
    tree *p;

    if(*l == NULL){
        p = malloc(sizeof(tree));
        p->item = c;
        p->left = p->right = NULL;
        p->parent = parent;
        *l = p;
        return;
    }

    if(c < (*l)->item)
        insertTree(&((*l)->left),c,*l);
    else
        insertTree(&((*l)->right),c,*l);
}



