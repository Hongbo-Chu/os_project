#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#define size 100

struct shared_mem{
    int writen;
    char txt[size];
}buf;

int sever(){
    int shmid,shmaddr;
    int reseve_error;
    shmid = shmget(50, size, IPC_CREAT|0600 ) ;
    if(shmid == -1){
        perror("error");
        exit(-1);
    }
    shmaddr = (char *)shmat( shmid, NULL, 0 ) ;
    if ( (int)shmaddr == -1 ){
        perror("shmat addr error") ;
        return -1 ;
    }
    reseve_error = shmctl(shmid,IPC_STAT,&buf);
    if(reseve_error == -1){
        return -1;
    }    
     shmdt( shmaddr ) ;
    printf("sever reseved%s",buf.txt);

}

void client(){
     int shmid,shmaddr;
    shmid = shmget(50, size, IPC_CREAT|0600 ) ;
    if(shmid == -1){
        perror("error");
        exit(-1);
    }
    shmaddr = (char *)shmat( shmid, NULL, 0 ) ;
    strcpy( shmaddr, "hi, dad\n");
    shmdt(shmaddr);

}
void main(){
    int pid = fork();
    if(pid==-1){
        wait(2);
        perror("forkerror");
    }
    if(pid>0){
        client();
    }
}
