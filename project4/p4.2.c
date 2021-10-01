#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#define size 100

void server(){
	int i=0,shmid;
	int* shmaddr;//TODO why char??
	shmid = shmget(75, 1024, 0666|IPC_CREAT);
	shmaddr = shmat(shmid, 0, 0);
	while(i++ < 9){
		printf("sever rescived:%p\n", shmaddr);
		shmaddr++;
	}
	shmdt(shmaddr);
	if(shmctl(shmid,IPC_RMID,NULL) < 0)
	{
		perror("shmctl");
		return -1;
	}
	
}

void client(){
	int i=0,shmid;
	int* shmaddr;
	shmid = shmget(75, 1024, 0666|IPC_CREAT);
	shmaddr = shmat(shmid, 0, 0);
	for (int i = 0; i < 9; i++){
		*shmaddr = i;
		shmaddr++;
	}
	shmdt(shmaddr);
	

}
void main(){
	int pid = fork();
	if(pid<0){
		perror("forkerr");
	}
	if(pid==0){
		server();

	}
	else{
		client();
	}

}/*
 * @Author: your name
 * @Date: 2021-10-01 10:44:09
 * @LastEditTime: 2021-10-01 21:51:53
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /os_project/project4/p4.2.c
 */
#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#define size 100

// struct shared_mem{
//     int writen;
//     char txt[size];
// }buf;

int sever(){
    int shmid;
	int* shmaddr;
    int reseve_error;
    shmid = shmget(50, size, IPC_CREAT|0666 ) ;
    if(shmid == -1){
        perror("error");
        exit(-1);
    }
    shmaddr = shmat( shmid, NULL, 0 ) ;
    if ( (int)shmaddr == -1 ){
        perror("shmat addr error") ;
        return -1 ;
    }
	int j=0;
	while(j++ < 9){
		printf("sever rescived:%p\n", shmaddr);
		shmaddr++;
	}
	//printf("(seveer)id=%p, txt =%d", shmaddr,*shmaddr);
    // do{
	// 	printf("(sever)receive%d",*shmaddr);
	// }while(shmaddr!=0);
    // reseve_error = shmctl(shmid,IPC_STAT,&buf);
    // if(reseve_error == -1){
    //     return -1;
    // }    
    //  shmdt( shmaddr ) ;
    // printf("sever reseved%s",buf.txt);

}

void client(){
     int shmid;
	 int *shmaddr;
    shmid = shmget(50, size, IPC_CREAT|0666 ) ;
    if(shmid == -1){
        perror("error11");
        exit(-1);
    }
    shmaddr = shmat( shmid, NULL, 0 ) ;
	for(int i=9;i<=0;i--){
		while(shmaddr!=-1);
		*shmaddr =8;
		printf("(client)send:%d\n", *shmaddr);
		shmaddr++;
	}
	shmctl(shmid,IPC_RMID,0);
}
void main(){
    int pid = fork();
    if(pid==-1){
        perror("forkerror");
    }
    if(pid>0){
        client();
    }
	else{
		//wait(0);
		sever();
	}
}



