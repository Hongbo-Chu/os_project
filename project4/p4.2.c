/*
 * @Author: your name
 * @Date: 2021-10-01 10:44:09
 * @LastEditTime: 2021-10-01 19:50:56
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /os_project/project4/p4.2.c
 */
// #include <sys/ipc.h>
// #include <sys/shm.h>
// #include<stdio.h>
// #include<stdlib.h>
// #define size 100

// struct shared_mem{
//     int writen;
//     char txt[size];
// }buf;

// int sever(){
//     int shmid,shmaddr;
//     int reseve_error;
//     shmid = shmget(50, size, IPC_CREAT|0666 ) ;
//     if(shmid == -1){
//         perror("error");
//         exit(-1);
//     }
//     shmaddr = (char *)shmat( shmid, NULL, 0 ) ;
//     if ( (int)shmaddr == -1 ){
//         perror("shmat addr error") ;
//         return -1 ;
//     }
//     while(shmaddr!=-1){
//         printf("(sever)reseved%d",shmaddr);
//     }
//     // reseve_error = shmctl(shmid,IPC_STAT,&buf);
//     // if(reseve_error == -1){
//     //     return -1;
//     // }    
//     //  shmdt( shmaddr ) ;
//     // printf("sever reseved%s",buf.txt);

// }

// void client(){
//      int shmid,shmaddr;
//     shmid = shmget(50, size, IPC_CREAT|0600 ) ;
//     if(shmid == -1){
//         perror("error");
//         exit(-1);
//     }
//     shmaddr = (char *)shmat( shmid, NULL, 0 ) ;
//     strcpy( shmaddr, "hi, dad\n");
//     shmdt(shmaddr);

// }
// void main(){
//     int pid = fork();
//     if(pid==-1){
//         wait(2);
//         perror("forkerror");
//     }
//     if(pid>0){
//         client();
//     }
// }

#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int shmid,i;
int *addr;

int CLIENT()
{	
	int i;	
	shmid=shmget(75,1024, 0777|IPC_CREAT);    /*获取共享区，长度1024/
	addr=shmat(shmid,0,0);                /*共享区起始地址为addr*/	
	for(i=9;i>=0;i--) 	
	{		
		while(*addr != -1);                  		
		printf("(client)sent\n");                 /*打印（client）sent*/		
		*addr=i;                             /*把i赋给addr*/	
	}	
	exit(0);
}

int SERVER()
{ 	
	do{	
		while(*addr == -1);							
		printf("(server)received\n%d",*addr);               /*服务进程使用共享区*/	
		if(*addr!=0)
			*addr=-1;	
	}while(*addr);	
	wait(0);
	shmctl(shmid,IPC_RMID,0);	
}

int main()
{	
	shmid=shmget(75,1024,0777|IPC_CREAT);  /*创建共享区*/	
	addr=shmat(shmid,0,0);                         /*共享区起始地址为addr*/	
	*addr=-1;	
	if(fork())
	{
		SERVER();	
	}
	else
	{
		CLIENT();	
	}
 }

