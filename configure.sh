#!/bin/sh
#
# Install the library
#


# help
if [ "$1" != "help" ] && [ "$1" != "--help" ] && [ "$1" != "-h" ]; then
  true
else
  echo "Usage: [enchant=use] ./configure.sh [--help]"
  exit 0
fi

if [ ! -z $enchant ]; then
  echo 'Compiling with enchant support.'
  cp -v src/enchant/find_enchanted.c src/
  echo 'cat >Tuprules.tup Tuprules.default.tup Tuprules.enchant.tup'
  cat >Tuprules.tup Tuprules.default.tup Tuprules.enchant.tup
else
  echo 'Compiling without enchant support.'
  echo 'Enchant is a c library for (de)?allocating many pointers at once.'
  echo 'If you want to compile with enchant support, run `enchant=use ./configure.sh`.'
  cp -v src/noenchant/find_enchanted.c src/
  echo 'cat >Tuprules.tup Tuprules.default.tup'
  cat >Tuprules.tup Tuprules.default.tup
fi
