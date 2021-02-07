#ifndef RUSH_H

# include <unistd.h>
# include <stdlib.h>

# define RUSH_H
//# define DEFAULT_DICT_PATH "numbers.dict"
# define DEFAULT_DICT_PATH "/Users/hedgi/CLionProjects/21school/rush02/numbers.dict"
# define BYTE_COUNT 2

typedef struct dict_number
{
	int size;
	int *ranges;
	char *key;
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

void convert_str_t_ranges(d_number **num);

d_str *create_str_elem(const char *line, int from, int size);

d_str *convert_number(d_number *dictionary, d_number *number);

int ft_strlen(char *str);

void ft_putstr(char *str);

#endif