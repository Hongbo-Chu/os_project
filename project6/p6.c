/*
 * @Author: your name
 * @Date: 2021-10-20 10:00:02
 * @LastEditTime: 2021-10-20 10:44:10
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /os_project/os_project/project6/p6.c
 */
/* example.c*/
#include <stdio.h>
#include <pthread.h>
#include<stdlib.h>
void thread_int(void* arg)
{
int i;
int* num = (int*)arg;
//  for(i=0;i<3;i++)
printf("This is a int pthread, arg = %d.\n",*num);
}

void thread_char(void* arg)
{
int i;
int* num = (char*) arg;
//  for(i=0;i<3;i++)
printf("This is a cahr_pthread. num = %c\n",*num);
}
int main(void)
{
pthread_t id;
int i,ret, ret2;
int test = 4;
int* attr = &test;
char test2 = "c";
char* attr2 = &test2; 

ret=pthread_create(&id,NULL,(void *) thread_int,attr);
ret2=pthread_create(&id,NULL,(void *) thread_char, attr2);
if(ret!=0){
printf ("Create pthread error!\n");
exit (1);
}
for(i=0;i<3;i++){
printf("This is the main process.\n");
}
pthread_join(id,NULL);
return (0);
}
