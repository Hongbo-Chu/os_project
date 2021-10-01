#include<stdio.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include<stdlib.h>
#define size 100
struct abc{
    int m;//type
    int fu;
}msg, msg11;

void server(){
    int msgid;
    int i=0;
    int id = msgid = msgget(5, 0666|IPC_CREAT); 
    if(id == -1){
        perror("error:");
    }
    do{
        int errno = msgrcv(msgid, &msg, 1024, 0, 0);
        if(errno==-1){
            perror("eee:");
        }
        printf("(server)reseved%d\n",msg.m);
    }while(msg.m<10);
    msgctl(msgid, IPC_RMID,0);
    exit(0);
}

void client(){
    int msgid;
     int id = msgid = msgget(5, 0666|IPC_CREAT); 
    if(id == -1){
        perror("error:");
    }
    for(int i =0;i<10;i++){
        msg.m = i;
        int tt = msgsnd(msgid, &msg,1024,0);
        if(tt!=-1){
            printf("(client)send\n");
        }
    }
    exit(0);


}
int main(){
    int pid = fork();
    if(pid<0){
        perror("err");
    }
    if(pid==0){
        client();
    }
    else{
        server();
    }

}
