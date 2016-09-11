/*
 * Execute a program
 *
 */

#include"init.h"
#include"namespace.h"

#define _GNU_SOURCE
#include<sys/types.h>   
#include<sys/wait.h>
#include<signal.h>
#include<unistd.h>
extern char **environ;
#include<stdio.h>


int execute(char **argv) {

	int status[1];
	
	char * program = find(argv[0]);
	
	pid_t child = fork();
	if (child == 0) {
		execve(program, argv, environ);
		abort();
	}
	else if (child < 0) {
        perror("Could not fork child.");
        return -1;
    }    
    else {
        // parent process
    }
	waitpid(child, status, 0);

	return *status;
	
}
