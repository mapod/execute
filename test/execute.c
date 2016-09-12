#include<arc/execute/init.h>
#include<arc/execute/namespace.h>

int main (int argc, char ** argv) {
	char **args = &( argv[1] );
	return execute(args);
}
