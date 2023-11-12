#!/bin/sh

set -x

clang -Wall -Wextra -pedantic -O3 -lraylib -lm -o metaballs main.c
