#include "monty.h"
/**
 * splitString - Split a string into an array of strings
 * @line: The string to be split.
 * Return: An array of strings representing or NULL on failure.
 */
char **splitString(char *line)
{
	char **strungs = NULL, *strung;
	char *line_cp;
	int count = 0, i;

	if (line == NULL)
		return (NULL);
	line_cp = strdup(line);
	if (line_cp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strung = strtok(line, DELIMITERS);
	while (strung != NULL)
	{
		count++;
		strung = strtok(NULL, DELIMITERS);
	}
	strungs = malloc(sizeof(char *) * (count + 1));

	strung = strtok(line_cp, DELIMITERS);
	for (i = 0; strung != NULL; i++)
	{
		strungs[i] = strdup(strung);
		if (strung[i] == '\0')
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strung = strtok(NULL, DELIMITERS);
	}
	strungs[i] = NULL;
	free(line_cp);
	return (strungs);
}
