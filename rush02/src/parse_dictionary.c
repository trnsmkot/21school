#include <libc.h>
#include "../includes/rush.h"

int ft_open_file(char *file)
{
	return (open(file, O_RDONLY));
}

d_str *create_str_elem(const char *line, int size)
{
	d_str *list;
	int index;

	index = 0;
	list = (d_str *) malloc(sizeof(d_str));
	if (list)
	{
		list->value = (char *) malloc(sizeof(char) * (size + 1));
		while (line[index])
		{
			list->value[index] = line[index];
			index++;
		}
		list->value[index] = '\0';
		list->size = size;
		list->next = 0;
	}
	return (list);
}

void ft_list_push_back(d_str **begin_list, const char *line, int size)
{
	d_str *element;
	d_str *last_element;

	if (!(element = create_str_elem(line, size)))
		return;
	if (!(*begin_list))
	{
		*begin_list = element;
		return;
	}
	last_element = *begin_list;
	while (last_element->next != 0)
		last_element = last_element->next;
	last_element->next = element;
}

int ft_read_file(int fd, int byte_count)
{
	int code;
	int read_byte;
	char *buffer;
	d_str *line;

	line = 0;
	buffer = (char *) malloc(sizeof(char) * (byte_count));
	while ((read_byte = read(fd, buffer, byte_count)) != 0)
	{
		ft_list_push_back(&line, buffer, byte_count);
	}

	printf("%s", line->value);

	code = close(fd);
	free(buffer);
	return (code);
}

d_number *parse_dictionary(char *path)
{
	int fd;
	d_number *array;

	if ((fd = ft_open_file(path)))
	{
		if (!ft_read_file(fd, BYTE_COUNT))
		{
//			 TODO
		}
	}
	return (array);
}
