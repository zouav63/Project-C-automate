#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct relation{
    int source; // etat source
    char gram; // grammaire de la transition
    int dest; // etat de destination
};

struct automate{
    char X[256]; // alphabet
    int Q[50]; // états 
    char I[20]; // états initiaux
    char F[20]; // états finaux 
    struct relation *R; 

    // int nb_states; // nombre d'états
    // int *initial; // les états initiaux
    // int *final; // Les états finaux
    // int nb_transitions; // Le nombre de transitions
    // struct transition *table; // La table de transition
};

void afficherAutomate(struct automate aef){
    printf("X={");
    for (int i = 0; i < sizeof aef.X / sizeof aef.X[0]; i++){
        printf("%c,\n", aef.X[i]);
    }
        
}

int main(int argc, char *argv[]){

    char ch,file_name[30]="../AEF.txt";
        FILE *fp;
        fp = fopen(file_name, "r"); // read mode
        if (fp == NULL){
            perror("Error while opening the file.\n");
            exit(EXIT_FAILURE);
        }

    struct automate aef;

    char *res;
    res = malloc(sizeof(int)*10);
    char curr='\0';
    bool read = false;
    int count=0, countR=0;

    // printf("%s\n", aef.X);
    // strcpy(aef.X, "");
    // printf("%s\n", aef.X);

    // Mode read=true permet de concataner tous les charactères courants 
    while((ch = fgetc(fp)) != EOF){
        if(ch=='X'){
            strcpy(aef.X, "");
            count=0;
            curr = 'X';
            read=false;
        }else if(ch=='Q'){
            count=0;
            curr = 'Q';
            read=false;
        }else if(ch=='I'){
            count=0;
            curr = 'I';
            read=false;
        }else if(ch=='R'){
            count=0;
            curr = 'R';
            read=false;
        }else if(ch=='F'){
            count=0;
            curr = 'F';
            read=false;
        }

        if(ch==',' | ch==')' | ch=='}'){
            read=false;
            memset(res, 0, strlen(res));
        }

        if(read==true && ch!='{'){
            char copy[2]={ch, '\0'};
            strcat(res,copy);
            
            if(curr=='X'){
                strcat(aef.X,res);
                // aef.X[count]=ch;
                printf("%s", res);
                count++;
            }else if(curr=='Q'){
                aef.Q[count]=atoi(res);
                // aef.Q[count]=ch;
                // printf("%s", res);
                count++;
            }else if(curr=='I'){
                // strcat(aef.I, res);
                aef.I[count]=atoi(res);
                // aef.I[count]=ch;
            }else if(curr=='F'){
                strcat(aef.F, res);
                // aef.F[count]=ch;
                count++;
            }
            // else if(curr == 'R'){
            //     if(res[0] != 'q' || strlen(res)==2){
            //         if(countR==0){
            //             strcpy(aef.R[count].source,res);
            //             countR++;
            //         }else if(countR==1){
            //             strcpy(aef.R[count].gram,res);
            //             // strcpy(R[count].gram,res);
            //             countR++;
            //         }else if(countR==2){
            //             strcpy(aef.R[count].dest,res);
            //             // strcpy(R[count].res,res);
            //             countR=0;
            //             count++;
            //         }
            //     }  
            // }
        }
        if(ch=='(' | ch=='{' | ch==',' | ch=='\0' | ch==' ' | ch == '='){
            memset(res, 0, strlen(res));
            read=true;
        }
    }
    printf("%s", aef.X);
    // fclose(fp);
    // afficherAutomate(aef);
    return 0;
}