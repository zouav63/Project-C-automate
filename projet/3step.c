#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// struct alphabet{
//     char a1[1];
//     char b1[1];
//     char c1[1];
// };

struct relation{
    char etat[10];
    char gram[1];
    char res[10];
};

struct arr {
    int arr[50][50];
};
struct regles {
    int arr[50][50];
};


// struct arr transform(char str[]){
//     // char L[] = "aaa*b*(ab+bb*)aa*"; // Equation de l'automate -> peut être traduit shématiquement 
//     //          aaa*b*ab + aaa*b*bb*
//     struct arr L;
//     char lang[100]="\0";
//     int j=0; int num=0;
//     for (int i = 0; i <= strlen(str); i++){
//         if(str[i]=='('){
//             int a=i+1; int p=0; char res[100]="\0"; int cmpt=0;
//             while(str[a]!=')'){
//                 res[p]=str[a];
//                 printf("%c\n", str[a]);
//                 // struct arr result;
//                 // // printf("---%d\n", a);
//                 // if(str[a+1]=='+'| str[a+1]==')'){
//                 //     strcpy(result.arr[cmpt],res);
//                 //     memset(res, 0, strlen(res));
//                 //     a++;cmpt++;
//                 // }
//                 // a++;p++;
//                 // a++;
//             }
//             i=a;
//         }else{
//             if(str[i]=='+' | i==strlen(str)){
//             strcpy(L.arr[num],lang);
//             memset(lang, 0, strlen(lang));
//             j=0; num++;
//         }else{
//             lang[j]=str[i];
//             j++;
//             }
//         }
//     }
//     return L;
// }

// Bien comprendre les pointeurs (assignation à une addresse mémoire)
// void changepointeur(int* p){
//     *p=20;
// } //Ne retourne rien mais change quand même la valeur de a, on change directement dans la mémoire
// int a = 10;
// int* pointeur = &a;
// printf("%d\n", a);
// changepointeur(pointeur);
// printf("%d\n", a);

int main(int argc, char *argv[]){

    //3eme étape
    // char L[] = "aaa*b*(ab+bb*)"; // Equation de l'automate -> peut être traduit shématiquement 
    // aaa*b*ab+aaa*b*bb*
    // char str[]="bbb";
    // printf("%d\n",appartientAutomate(str, L));
    // struct arr Lang=transform(L);
    // printf("%s\n", Lang.arr[0]);
    // printf("%s\n", Lang.arr[1]);

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
