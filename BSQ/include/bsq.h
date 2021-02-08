#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>

# define BYTE_COUNT 15

typedef struct s_settings
{
	char empty;
	char obstacle;
	char full;
	int x;
	int y;
	int max_size;
	unsigned long width;
	unsigned long height;
} t_settings;

// str_lib.c
void ft_fill_str(char *buffer, int size);
int	ft_strlen(char *str);
int ft_index_of(const char *str, char ch, int index);
int	ft_strcmp(char *s1, char *s2);
void ft_putstr(char *str);

#endif
