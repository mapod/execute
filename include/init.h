/*
 * Execution
 *
 */

#pragma once

#include<stdlib.h>

#ifdef execute
# define user_wants_execution_namespace
#endif
#include"namespace.h"


// execute a program
int _exec(char *program, ...)
	__attribute__ ((sentinel));
#define arcane_exec(program, args...) _exec(program, ##args, NULL);

// execute a program (program is taken from argv[0])
int execute(char **argv);

// find file in $PATH:
// malloc version
char *find(char *program)
	__attribute__((warn_unused_result));
// enchantment version
#ifdef arcane_enchantment
char *find_enchanted(char *program, arcane_enchantment e)
	__attribute__((warn_unused_result));
#endif


#ifndef user_wants_execution_namespace
# include"namevoid.h"
#endif

#if 0 // TODO:
// sds version
# ifdef __SDS_H
sds find_sds(char *program);
# endif
#endif
