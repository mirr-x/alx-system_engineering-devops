#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * infinite_while - creat an infinite loop
 * Return: always 0
*/
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - creat 5 five zombie process
 * Return: 0
*/
int main(void)
{
	pid_t pid;
	int count = 0;

	while (count < 5)
	{
		pid = fork();
		if (pid > 0)
		{
			printf("Zombie process created, PID: %d\n", pid);
			sleep(1);
			count++;
		}
		else
			exit(0);
	}
	infinite_while();
	return (0);
}
