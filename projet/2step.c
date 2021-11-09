#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct relation{
    char etat[10];
    char gram[1];
    char res[10];
};

int main(int argc, char *argv[]){
    char ch,file_name[30]="../AEF.txt";
    FILE *fp;
    fp = fopen(file_name, "r"); // read mode
    if (fp == NULL){
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

    
    
    // int **Q;
    // Q = malloc(sizeof(int)*10*10);
    // Q[0]="hello";
    // // printf("%s\n", Q[0]);
    
    // int numQ=0;
    // char copy[0]='a';
    
    int X[] = {'\0'}; //Grammaire
    int numQ=0;
    char* copy, curr;
    bool read = false;
    curr = '\0';
    copy="h";
    char *res;
    res = malloc(sizeof(int)*10);

    strcat(res, copy);

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

        if(ch==',' | ch==')' | ch=='}'){
            read=false;
            printf("%s\n", res);
            memset(res, 0, strlen(res));
            printf("%s\n", res);
        }
        printf("%c", ch);
        printf("%s", copy);
        // if(read==true && ch!='{'){
        //     strcat(res,copy);
        //     printf("%c: %s\n", copy, res);
        //     if(curr=='X'){
        //         strcat(X, res);
        //         printf("%c: %s\n", curr, X);
        //     }else if(curr=='Q'){
        //         // Q[numQ]=*res;
        //         // numQ++;
        //         // printf("%c: %s\n", curr, Q);
        //     }
        // }

        // if(ch=='(' | ch=='{' | ch==',' | ch=='\0' | ch==' ' | ch == '='){
        //     memset(res, 0, strlen(res));
        //     read=true;
        // }
    }
   fclose(fp);
}