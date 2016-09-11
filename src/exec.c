/*
 * Execute a program
 *
 */

#include"init.h"
#include"namespace.h"

#include<stdarg.h>
#include<stdlib.h>


int _exec(char *program, ...) {

	size_t argc = 0;
	char **argv = NULL;
#define add_arg(x) 	\
	do { \
		argc++; \
		argv = realloc(argv, argc * sizeof(char *)); \
		argv[argc - 1] = (x); \
	} while (0)
		
	add_arg(program);
	
	va_list args;
	va_start(args, program);
	{

		for (char *s; (s = va_arg(args, char *));)
			add_arg(s);
	
		add_arg(NULL);
		
	}
	va_end(args);

	return execute(argv);

}
