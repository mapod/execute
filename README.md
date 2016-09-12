Arcane Execution
================

*Arcane Execution* is a library for executing programs
without calling shell.

## Download/Compile/Install

To compile and install Arcane Execution, make sure you have these:
 * [Tup](http://gittup.org/tup/)
 * C compiler

Then run this in your shell:
```sh
./configure.sh
tup
./install.sh
```

If you're not the root user, you can install it locally with:
`PREFIX=$HOME ./install.sh`, instead of the third line.

You can also enable some functions that interface with *Arcane Enchantment*:
`enchant=use ./configure.sh`.


## Usage

Include the headers:
```c
#include<arc/execute/init.h>
#include<arc/execute/namespace.h> // optional, but you'll need to prefix everything with arcane_
```

The easiest thing to do is just run a program:
```c
// some code
int status = exec("ls", "-a", "/bin");
// more code here
```

Sometimes, you want to pass an array instead of an argument list...
```c
int main (int argc, char ** argv) {
    char *args[] = &( argv[1] );
    return execute(args);
}
```

Or just find out where the program is:
```c
char * path = find("sl");
exec("rm", path);
free(path);
```
compile with `cc code.c -larcane-execution`.

## License

LGPL >=3
