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



// bool appartient(char str[], struct alphabet alphabet){
//     for(int i=0; i<strlen(str); i++){
//         if(str[i]!=*alphabet.a1 && str[i]!=*alphabet.b1 && str[i]!=*alphabet.c1){
//             return false;
//         }
//     }
//     return true;
// }

// bool vide(char str[]){if(strcmp(str, "\0")==0){return true;}else{return false;}}

// char* puis(char string[], int m){
//     char* result="";
//     char string1[100]="";
//     if (m==0){
//         return result;
//     }else{
//         strcpy(string1, string);
//         for (int i=0; i<m-1; i++){
//             result = strcat(string1, string);
//         }
//         return result;
//     }
// }

// bool estFini(char str[]){
//     for(int i=0; i<strlen(str); i++){
//         if(str[i]=='*'){
//             return false;
//         }
//     }
//     return true;
// }

// char* miroir(char m[]){
//     char *result;
//     char a[100]="";
//     int i=0; 
//     for(int j=strlen(m)-1; j>=0; j--){
//         a[i] = m[j];
//         i++;
//     }
//     result=a;
//     return result;
// }

// bool appartientAutomate(char str[], char L[]){
//     int a=0; // Permet d'indexer le str
//     int i=0; // Permet d'indexer le Langage (L)
//     while (a!=strlen(str)){
//         if(str[a]!=L[i] && str[a]!='('){
//             return false;
//         }else{
//             a++;
//             if(L[i+1]=='*'){
//                 while(str[a]==L[i]){
//                     a++;
//                 }
//                 i++;
//             }else if(L[i+1]=='('){
//                 /* code */
//                 i+=2;
//                 int j=i;
//                 char res[100]="";
//                 while(L[i]!=')'){
//                     //code

//                 }
//             }
//             i++;
//         }
//     }
//     return true;
// }

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

    //1er étape, mise en jambe
    // struct alphabet alphabet={"a","b","c"};
    // printf("%d\n", appartient("abc", alphabet)); 
    // printf("%s\n", puis("abc",3));
    // printf("%s\n", miroir("hello"));
    // printf("%d\n", vide("abc"));
    // printf("%d\n", estFini("abc"));


    //2eme étape

    //EXEMPLE DE AEF
    // struct arr Q;
    
    // printf("%s", X);
    // int Q[] = {'q0', 'q1', 'q2', 'q3'}; //Etats 
    // int I = 'q0'; //Etat initial
    // struct relation R1={"q0",'a', 'q3'}; //Relations
    // struct relation R2={"q0",'b', 'q1'};
    // struct relation R3={"q1",'a', 'q1'};
    // struct relation R4={"q1",'b', 'q2'};
    // struct relation R5={"q3",'a', 'q3'};
    // int F[]='q2q3'; //Etat Final
    
    char ch,file_name[30]="AEF.txt";
    FILE *fp;
    fp = fopen(file_name, "r"); // read mode
    if (fp == NULL){
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

    char *res;
    res = malloc(sizeof(int)*10);
    char* copy, curr;
    // char * res = (char *) malloc(100);
    bool read= false;
    curr = '\0';
    int **Q;
    Q = malloc(sizeof(int)*10*10);
    Q[0]="hello";
    // printf("%s\n", Q[0]);
    int X[] = {'\0'}; //Grammaire
    int numQ=0;
    char copy[0]='a';

    printf("%s\n", res);
    strcat(res, copy);
    printf("%s\n", res);

    while((ch = fgetc(fp)) != EOF){
        if(ch=='X'){
            curr = 'X';
            read=false;
        }else if(ch=='Q'){
            curr = 'Q';
            read=false;
        }else if(ch=='I'){
            curr = 'I';
            read=false;
        }else if(ch=='R'){
            curr = 'R';
            read=false;
        }else if(ch=='F'){
            curr = 'F';
            read=false;
        }

        // if(ch==',' | ch==')' | ch=='}'){
        //     read=false;
            // memset(res, 0, strlen(res));
        // }

        // if(read==true && ch!='{'){
        //     // copy[0]=ch;
        //     const char *copy = ch;
        //     strcat(res,copy);
        //     printf("%c: %s\n", copy, res);
        //     if(curr=='X'){
        //         strcat(X, res);
        //         printf("%c: %s\n", curr, X);
        //     }else if(curr=='Q'){
        //         Q[numQ]=*res;
        //         numQ++;
        //         printf("%c: %s\n", curr, Q);
        //     }
        }

        // if(ch=='(' | ch=='{' | ch==',' | ch=='\0' | ch==' ' | ch == '='){
        //     // memset(res, 0, strlen(res));
        //     read=true;
        // }
        
    // }
   fclose(fp);


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
