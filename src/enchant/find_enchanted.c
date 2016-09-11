/*
 * Find a file in $PATH
 *
 */


#include"init.h"
#include"namespace.h"

#include<arc/enchant/init.h>
#include<arc/enchant/namespace.h>

#define _GNU_SOURCE
#include<assert.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


char *find_enchanted(char *program, enchantment e) {
	char *loc = find(program);
	enchantment_add(e, loc);
	return loc;
}
