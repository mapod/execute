#include<arc/execute/init.h>
#include<arc/execute/namespace.h>
#include<stdio.h>
#include<stdlib.h>

int main (int argc, char ** argv) {
	char * foo = find(argv[1]);
	if (! foo)
		printf("Error finding %s!\n", argv[1]);
	printf("%s\n", foo);
	free(foo);
	return 0;
}
