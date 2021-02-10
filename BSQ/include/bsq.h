#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BYTE_COUNT 20

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
void ft_putchar(char ch);
int	ft_strcmp(char *s1, char *s2);
void ft_putstr(char *str);

// num_lib.c
unsigned long ft_get_num(const char *buffer, int size);
int ft_get_min(int item_1, int item_2, int item_3);
void ft_fill_num(int *buffer, unsigned long size);

// io_lib.c
int ft_try_open_file(char *file);
int **malloc_matrix(t_settings *settings);
void fill_empty_matrix(int **matrix, t_settings *settings);
t_settings *create_settings();

// settings_lib.c
int ft_parse_settings(t_settings **settings, char *buffer);
char *append_to_line(char *line, int size, char ch);
int read_settings(int fd, t_settings *settings);
char *read_first_line(int fd);

// matrix_lib.c
int read_and_fill(int fd, char *buffer, int **matrix, t_settings *settings);
void ft_full_map(int **matrix, t_settings *settings);
void fill_first_line_matrix(int **matrix, t_settings *settings, const char *line);
int fill_matrix(int **matrix, t_settings *settings, int fd);

// map_lib.x
void ft_print_filled_map(int **matrix, t_settings *settings);
void ft_scan_map(int **matrix, t_settings *settings);
void process_map_item(int obstacle, unsigned long  *index_x, unsigned long  *index_y, int **matrix);
void down_vertical(unsigned long  *index_x, unsigned long  *index_y);

#endif
