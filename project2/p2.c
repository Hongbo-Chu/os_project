/*
 * @Author: your name
 * @Date: 2021-10-07 11:37:40
 * @LastEditTime: 2021-10-07 11:37:40
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /os_project/os_project/project2/p2.c
 */
//effwwfwfwaef
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
//#include<sys/types.h>
#include <stdlib.h>
void main(){
	printf("before forkd\n");
	int file[2];
	char *msg1 = "Child 1 is sending a message!\n";
	char *msg2 = "Child 2 is sending a message!\n";
	char buffer[32];
	if(pipe(file)<0){
		printf("creat pipe fail");
	}	
	
	pid_t p1 = fork();
	if(p1==0){
		sleep(1);
		printf("procese in child1\n");
		write(file[1],msg1,32);

	}

	else{	
		pid_t p2 = fork();
                if(p2==0){
         	      	 printf("procese in child2\n");
               		 write(file[1],msg2,32);
			
       		 }
		else{
                	int x = 0;
                //	printf("p1=%d,p2=%d",p1,p2);
       //        	 sleep(2);
	 		while(x<2){	 
               			read(file[0], buffer, 64);
               		 	printf("%s\n", buffer);
               		 	x++;
			}

		}
	
	

	}
}
