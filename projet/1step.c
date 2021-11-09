#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct alphabet{
    char a1[1];
    char b1[1];
    char c1[1];
};

int main(int argc, char *argv[]){
    //   1er étape, mise en jambe
    struct alphabet alphabet={"a","b","c"};
    printf("%d\n", appartient("abc", alphabet)); 
    printf("%s\n", puis("abc",3));
    printf("%s\n", miroir("hello"));
    printf("%d\n", vide("abc"));
    printf("%d\n", estFini("abc"));

}