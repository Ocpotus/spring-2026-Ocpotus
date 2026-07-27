# This repo/project has been replaced! More to come

# KSU CIS 598 Senior Capstone Project
This project serves as a proof of concept and application of material I learned in school and should not be used in production.
I referenced material I learned in CIS 570 (Introduction to Formal Language Theory) and CIS 505 (Introduction to Programming Languages).

## Verbum
Verbum is an EBNF-to-C parser generator. The goal of Verbum is to generate fast, simple, and readable code that can be easily integrated within the user's own projects (i.e. interpreter, compiler, etc.). The generated code will allow the user to bypass writing code for lexical analysis and abstract syntax tree construction.

## Usage
### Building
Verbum uses [`forge`](https://github.com/Ocpotus/forge) as its build system. Simply run the following:
```
$ forge build
```
### Language Compilation
Verbum takes in an EBNF grammar as in input and generates C header and source files. Simply run:
```
$ verbum generate <file>
```

### Testing
This project contains various tests of varying success in the `test/` directory.
