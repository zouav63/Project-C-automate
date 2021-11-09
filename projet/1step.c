#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct alphabet{
    char a1[1];
    char b1[1];
    char c1[1];
};


bool appartient(char str[], struct alphabet alphabet){
    for(int i=0; i<strlen(str); i++){
        if(str[i]!=*alphabet.a1 && str[i]!=*alphabet.b1 && str[i]!=*alphabet.c1){
            return false;
        }
    }
    return true;
}

bool vide(char str[]){if(strcmp(str, "\0")==0){return true;}else{return false;}}

char* puis(char string[], int m){
    char* result="";
    char string1[100]="";
    if (m==0){
        return result;
    }else{
        strcpy(string1, string);
        for (int i=0; i<m-1; i++){
            result = strcat(string1, string);
        }
        return result;
    }
}

bool estFini(char str[]){
    for(int i=0; i<strlen(str); i++){
        if(str[i]=='*'){
            return false;
        }
    }
    return true;
}

char* miroir(char m[]){
    char *result;
    char a[100]="";
    int i=0; 
    for(int j=strlen(m)-1; j>=0; j--){
        a[i] = m[j];
        i++;
    }
    result=a;
    return result;
}

bool appartientAutomate(char str[], char L[]){
    int a=0; // Permet d'indexer le str
    int i=0; // Permet d'indexer le Langage (L)
    while (a!=strlen(str)){
        if(str[a]!=L[i] && str[a]!='('){
            return false;
        }else{
            a++;
            if(L[i+1]=='*'){
                while(str[a]==L[i]){
                    a++;
                }
                i++;
            }else if(L[i+1]=='('){
                /* code */
                i+=2;
                int j=i;
                char res[100]="";
                while(L[i]!=')'){
                    //code

                }
            }
            i++;
        }
    }
    return true;
}

int main(int argc, char *argv[]){
    //   1er étape, mise en jambe
    struct alphabet alphabet={"a","b","c"};
    printf("%d\n", appartient("abc", alphabet)); 
    printf("%s\n", puis("abc",3));
    printf("%s\n", miroir("hello"));
    printf("%d\n", vide("abc"));
    printf("%d\n", estFini("abc"));

}