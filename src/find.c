/*
 * Find a file in $PATH
 *
 */


#include"init.h"
#include"namespace.h"

#define _GNU_SOURCE
#include<assert.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


char *find (char *program) {

	if (! program) return NULL;

	if (program[0] == '/' ||
		program[0] == '.')
		return strdup(program);
	
	char *progfull = NULL;

	char *path = strdup(getenv("PATH"));
	char *freepath = path; // for some reason, we need this
	char *dir  = NULL;
	
	while (( dir = strsep(&path, ":") )) {

		DIR *dp;
		struct dirent *ep;
		dp = opendir(dir);
			
		if (dp) {
			
			while ((ep = readdir (dp)))
				
				if (strcmp(ep->d_name, program) == 0) {
					
					progfull = malloc(strlen(dir) +
					                  strlen("/") +
					                  strlen(program) +
					                  1);
						
					if (! progfull) goto CONCLUDE;

					strcpy(progfull, dir);
					strcat(progfull, "/");
					strcat(progfull, program);

					goto CONCLUDE;
					
				}
			
			closedir(dp);
			
		}
		else {
			
			perror("Could not open a directory in $PATH.");
			
		}
		
	}


CONCLUDE:

	assert(freepath != NULL);

	free(freepath);
	
	return progfull;
	
}
