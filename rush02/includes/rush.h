#ifndef RUSH_H

# include <unistd.h>
# include <stdlib.h>

# define RUSH_H
//# define DEFAULT_DICT_PATH "numbers.dict"
# define DEFAULT_DICT_PATH "/Users/stass/_github/rush02/numbers.dict"
# define BYTE_COUNT 10

typedef struct dict_number
{
	int size;
	int *ranges;
	char *value;
	struct dict_number *next;
} d_number;

typedef struct dict_str
{
	int size;
	char *value;
	struct dict_str *next;
} d_str;

d_number *parse_dictionary(char *path);

d_number *parse_number(char *path);

int convert_number(d_number *dictionary, d_number *number);

#endif