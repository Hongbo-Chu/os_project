/*
 * @Author: your name
 * @Date: 2021-10-13 10:44:55
 * @LastEditTime: 2021-10-20 10:52:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /os_project/project5/p5.c
 */
// /*
//  * @Author: your name
//  * @Date: 2021-10-07 11:54:19
//  * @LastEditTime: 2021-10-13 10:36:01
//  * @LastEditors: Please set LastEditors
//  * @Description: In User Settings Edit
//  * @FilePath: /os_project/os_project/project5/p5.c
//  */


#include <stdio.h>
#include <signal.h>

static void	sig_usr(int);	/* one handler for both signals */

int
main(void)
{
	if (signal(SIGINT, sig_usr) == SIG_ERR)
	{
		printf("can't catch SIGUSR1\n");
		exit(1);
	}
	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
	{
		printf("can't catch SIGUSR2\n");
		exit(1);
	}
	for ( ; ; )
		pause();
}

static void
sig_usr(int signo)		/* argument is signal number */
{
	if (signo == SIGINT
		printf("received SIGUSR1\n");
	else if (signo == SIGUSR2)
		printf("received SIGUSR2\n");
	else
	{
		printf("received signal %d\n", signo);
		exit(1);
	}
}

// #include <stdio.h>
// #include <signal.h>

// typedef void (*signal_handler)(int);

// void signal_handler_fun(int signum){
//     printf("catch signal %d",signum);//为啥必须有\n

// }

// int main(int argc, char *argv[]) {
//     signal(SIGINT, signal_handler_fun);
//     while(1);
//     return 0;
// }


