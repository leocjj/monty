# 0x19. C - Stacks, Queues - LIFO, FIFO (Monty Bytecode Interpreter)

## Learning Objectives

* What do LIFO and FIFO mean
* What is a stack, and when to use it
* What is a queue, and when to use it
* What are the common implementations of stacks and queues
* What are the most common use cases of stacks and queues
* What is the proper way to use global variables

## Requirements

Compiled with Ubuntu 14.04 LTS with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic

## How to install
```sh
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

## How to use
Write ./monty <file_name>
* <file_name> should contain one instruction per line
* Each instruction in <file_name> should be an operator (see operators)
* You can use '#' to write comments in <file_name>
* Spaces and new lines are ignored.

## How the program works

| Function | Description | Usage |
| ------ | ------ | ------ |
| main | Prints error messages, call function who gets operator and free memory |
| get_opcode | Reads opcode and verifies if it's valid |
| free_stack_t | Frees a stack of type stack_t |
| add | Adds the top two elements of the stack | add |
| _div | Divides the second top element of the stack by the top element | div |
| _mod | Get the module of the second top element of the stack and top element | mod |
| _mul | Multiply top element of the stack with the second top element | mul |
| _nop | nop doesn’t do anything | nop |
| pall | Prints all elements in the stack | pall |
| _pchar | Prints the char at the top of the stack, followed by a new line | pchar |
| _pint | Prints the value at the top of the stack | pint |
| pop | Removes the top elements of the stack | pop |
| _mod | get the module of the second top element of the stack and top element | mod |
| _rotl | rotates the stack to the top | rotl |
| _rotr | rotates the stack to the bottom | rotr |
| _sub | subtracts top element of the stack from the second top element | sub |
| _swap | swaps the top two elements of the stack | swap |

### Other files and folders
* monty.h - doubly linked list representation of a stack (or queue), opcode and its function and prototypes of all functions of the program.
* bc - test cases.
* bf - Other tasks in brainfuck languaje.

## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Authors

* Diego Betancourt Q. [Dfbq91](https://github.com/dfbq91)
* Leonardo Calderon J - [LeoCJJ](https://github.com/leocjj)

01/04/2019
