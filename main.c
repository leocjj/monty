#include <stdio.h>
#include <stdlib.h>

/**
 * find_keyword - Entry point
 *
 * Return: Always 0 (Success)
 */
int find_keyword(char **line)
{
    int n = 0;
    while (( (*line)[n]  != '\0') && ((*line)[n] != ' '))
	n++;
    return n;
}


/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
   FILE *stream;
   char *line = NULL;
   size_t len = 0, len2 = 0;
   ssize_t nread;

   if (argc != 2)
   {
       fprintf(stderr, "USAGE: monty file\n");
       exit(EXIT_FAILURE);
   }

   stream = fopen(argv[1], "r");
   if (stream == NULL)
   {
       fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
       exit(EXIT_FAILURE);
   }

   while ((nread = getline(&line, &len, stream)) != -1)
   {
       printf("%s", line);
       len2 = find_keyword(&line);
       printf("%s - %ld\n", line, len2);
   }

   free(line);
   fclose(stream);
   exit(EXIT_SUCCESS);
}

