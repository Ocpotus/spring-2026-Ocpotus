#!/bin/bash

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ../.forge/bin/debug/verbum.bin generate ebnf/ebnf.ebnf
gcc verbum_ast.c verbum_lexer.c verbum_parser.c verbum_token.c utf8file.c test-ebnf.c -o test-ebnf.bin -g3
