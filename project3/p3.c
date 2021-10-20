/*
 * @Author: your name
 * @Date: 2021-10-17 12:21:37
 * @LastEditTime: 2021-10-17 14:17:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /os_project/project3/p3.c
//  */
// #include<stdio.h>
// #include<stdlib.h>
// void main(){
//     int errorno;
//     int status;
//     int pid;
//     char command[256];
//     while(1){
//         printf(">");
//         fgets(command,256, stdin);
        
//         if(fork()==0){
//             errorno = execlp(command, command, NULL, NULL);
//             perror("error12:");
//             exit(errorno);


//         } 
//         else{
//             wait(&status);
//             printf("child, over, return%d",status);
//         }
        
        
//     }
// }

#include <stdio.h>

char command[256]; 
int main() 
{ 
	int rtn; /*子进程的返回数值*/ 
	int errorno;
	while(1) { 
		/* 从终端读取要执行的命令 */ 
		printf( ">" ); 
		fgets( command, 256, stdin ); 
		command[strlen(command)-1] = 0; 
		if ( fork() == 0 ) { 
			/* 子进程执行此命令 */ 
			errorno=execlp(command, command, NULL, NULL); 
			/* 如果exec函数返回，表明没有正常执行命令，打印错误信息*/ 
			perror( command ); 
			exit(errorno); 
		} 
		else { 
			/* 父进程， 等待子进程结束，并打印子进程的返回值 */ 
			wait ( &rtn ); 
			printf( " child process return %d\n", rtn ); 
		} 
	} 
	return 0;
} 
