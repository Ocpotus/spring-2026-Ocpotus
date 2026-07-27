#!/bin/bash

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ../.forge/bin/debug/verbum.bin generate ebnf/c.ebnf
gcc verbum_ast.c verbum_lexer.c verbum_parser.c verbum_token.c utf8file.c test-c.c -o test-c.bin -g3
