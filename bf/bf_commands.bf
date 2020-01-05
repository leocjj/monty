The eight language commands each consist of a single character:

Character 	Meaning
> 	increment the data pointer (to point to the next cell to the right).
< 	decrement the data pointer (to point to the next cell to the left).
+ 	increment (increase by one) the byte at the data pointer.
- 	decrement (decrease by one) the byte at the data pointer.
. 	output the byte at the data pointer.
, 	accept one byte of input, storing its value in the byte at the data pointer.
[ 	if the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ] command.
] 	if the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching [ command.


(Alternatively, the ] command may instead be translated as an unconditional jump to the corresponding [ command, or vice versa; programs will behave the same but will run more slowly, due to unnecessary double searching.)


[ and ] match as parentheses usually do: each [ matches exactly one ] and vice versa, the [ comes first, and there can be no unmatched [ or ] between the two.


Brainfuck programs can be translated into C using the following substitutions, assuming ptr is of type char* and has been initialized to point to an array of zeroed bytes:

brainfuck command 	C equivalent
(Program Start) 	char array[30000] = {0};
			char *ptr=array;
> 			++ptr;
< 			--ptr;
+ 			++*ptr;
- 			--*ptr;
. 			putchar(*ptr);
, 			*ptr=getchar();
[ 			while (*ptr) {
] 			}


,>,<[>+<]










