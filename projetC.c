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
        if(str[a]!=L[i]){
            return false;
        }else{
            a++;
            if(L[i+1]=='*'){
                while(str[a]==L[i]){
                    a++;
                }
                i++;
            }
            i++;
        }
    }
    return true;
}

// Bien comprendre les pointeurs (assignation de l'addresse mémoire)
// void changepointeur(int* p){
//     *p=20;
// } //Ne retourne rien mais change quand même la valeur de a, on change directement dans la mémoire
// int a = 10;
// int* pointeur = &a;
// printf("%d\n", a);
// changepointeur(pointeur);
// printf("%d\n", a);

int main(int argc, char *argv[]){

    //1er étape, mise en jambe
    struct alphabet alphabet={"a","b","c"};
    printf("%d\n", appartient("abc", alphabet)); 
    printf("%s\n", puis("abc",3));
    printf("%s\n", miroir("hello"));
    printf("%d\n", vide("abc"));
    printf("%d\n", estFini("abc"));

    //2eme étape 
    char L[] = "abb*a*"; // Equation de l'automate -> peut être traduit shématiquement 
    char str[]="ab";
    printf("%d\n",appartientAutomate(str, L));
    return 0;
}

// Compilation avec un pc ayant un noyau Unix : 
// gcc -Wall -o nom_du_fichier_objet  -c nom_du_fichier_source_C


//Fonctionne mais ne retourne rien, je préfère qu'elle retourne qlq chose (ne retourne pas parce que on copie la string transformé et est directement mémoirisé car pointeur )
// void puis(char* string[], int m){
//     char string1[100]="";
//     if (m==0){
//         strcpy(string, string1);
//     }else{
//         strcpy(string1, string);
//         for (int i=0; i<m-1; i++){
//             strcat(string1, string);
//         }
//         strcpy(string, string1);
//     }
// }
