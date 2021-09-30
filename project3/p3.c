#include<stdio.h>

void main(){
    int errorno;
    int status;
    int pid;
    char command[256];
    while(1){
        printf(">");
        fgets(command,256, stdin);
        
        if(fork()==0){
            errorno = execlp(command, command, NULL, NULL);
            perror("error:");

        } 
        else{
            wait(&status);
            printf("child, over, return%d",status);
        }
        
        
    }
}