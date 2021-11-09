#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct relation{
    char etat[10];
    char gram[2];
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


    char **X;
    X = malloc(sizeof(char)*10*10);
    char **Q;
    Q = malloc(sizeof(int)*10*10);
    char *I;
    char **F;
    F = malloc(sizeof(int)*10*10);

    // à revoir 

    // struct relation R;
    // strcpy( R.etat, "Sara" );
    // printf("%s\n", R.etat);
    // struct relation **R;
    // R = malloc(sizeof(int)*10*10);
    // strcpy(R[0]->etat, "Sara" );
    // printf("%s\n", R[0]->etat);
    return 0;
    char *res;
    res = malloc(sizeof(int)*10);

    char curr='\0';
    bool read = false;

    int count=0, countR=0;

    while((ch = fgetc(fp)) != EOF){
        if(ch=='X'){
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
        // printf("%c", ch);

        if(read==true && ch!='{'){
            char copy[2]={ch, '\0'};
            strcat(res,copy);
            if(curr=='X'){
                X[count]=res;
                count++;
            }else if(curr=='Q' && strlen(res)==2){
                Q[count]=res;
                count++;
            }else if(curr=='I'  && strlen(res)==2){
                I=res;
            }else if(curr=='F'  && strlen(res)==2){
                F[count]=res;
                count++;
            }else if(curr=='R'){
                if(res!="q" || strlen(res)==2){
                    if(countR==0){

                    }else if(countR==1){

                    }else if(countR==2){
                        countR=0;
                    }
                }  
                countR++;
            }
        }

        if(ch=='(' | ch=='{' | ch==',' | ch=='\0' | ch==' ' | ch == '='){
            memset(res, 0, strlen(res));
            read=true;
        }
    }
   fclose(fp);
}