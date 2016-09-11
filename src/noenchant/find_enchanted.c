/*
 * Do nothing; for people without enchantment.
 *
 */

#include"init.h"
#include"namespace.h"


struct __enchantment {
    // amount of pointers
    size_t size;
    // list of pointers
    void **ptrs;
};

typedef struct __enchantment _enchantment;

typedef _enchantment * enchantment;


#include<stdlib.h>


char *find_enchanted(char *program, arcane_enchantment e) {
	return NULL;
}
