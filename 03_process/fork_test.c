#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[]){
	pid_t child_pid;
	int count = 0;

	child_pid = fork();
	if(child_pid >= 0){
		if(child_pid == 0){
			count = 2;
			printf(" In the child process, counter: %d\n", count++);
			printf(" Child ID: %d is child of Parent ID: %d\n", getpid(), getppid());
			// sleep(1);
		} else {
			printf(" In the parent process, counter: %d\n", ++count);
			printf(" Parent ID: %d \n", getpid());
			// while(1);
		}
	} else {
		printf("fork() unsucessfully \n");
	}
	return 0;
}