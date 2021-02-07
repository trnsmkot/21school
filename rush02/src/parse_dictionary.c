#include <libc.h>
#include "../includes/rush.h"

int ft_open_file(char *file)
{
	return (open(file, O_RDONLY));
}

d_str *create_str_elem(const char *line, int from, int size)
{
	int index;
	d_str *list;

	index = 0;
	list = (d_str *) malloc(sizeof(d_str));
	if (list)
	{
		list->value = (char *) malloc(sizeof(char) * (size + 1));
		while (index < size)
		{
			list->value[index] = line[from];
			from++;
			index++;
		}
		list->value[index] = '\0';
		list->size = size;
		list->next = 0;
	}
	return (list);
}

int get_line_value_size(d_str *dstr, d_str **d_value)
{
	d_str *element;
	int size;
	int was_sep;

	was_sep = 0;
	size = 0;
	element = dstr;
	while (element != 0)
	{
		if (element->size == 1 && element->value[0] == ':')
		{
			was_sep = 1;
			*d_value = element->next;
		}
		if (was_sep)
			size += element->size;
		element = element->next;
	}
	return (size);
}

void get_num_value(char *value, d_str *dstr)
{

}

d_number *create_num_elem(d_str *dstr)
{
	d_number *num;
	d_number *d_value;

	d_value = 0;
	num = (d_number *) malloc(sizeof(d_number));
	if (num)
	{
		num->value = (char *) malloc(sizeof(char) * (get_line_value_size(dstr, &d_value) + 1));
		(d_value) ? printf("    create_num_elem: %s\n", d_value->value) : 0;
//		d_value->value;
//		get_num_value();
//		while (index < size)
//		{
//			list->value[index] = line[index];
//			index++;
//		}
//		list->value[index] = '\0';
//		num->size = size;
		num->next = 0;
	}
	return (num);
}

void ft_list_push_back(d_str **begin_list, const char *line, int start, int size)
{
	d_str *element;
	d_str *last_element;

	if (size <= 0)
		return;
	if (!(element = create_str_elem(line, start, size)))
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

int get_char_idx(const char *str, char sep)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == sep)
			return (index);
		index++;
	}
	return (-1);
}

void ft_fill_str(char *str, int size)
{
	int index;

	index = 0;
	while (index < size)
	{
		str[index] = '\0';
		index++;
	}
}

void ft_number_push_back(d_number **numbers, d_str *line)
{
	d_number *number;
	d_number *last_num;

	if (!(number = create_num_elem(line)))
		return;
	if (!(*numbers))
	{
		*numbers = number;
		return;
	}
	last_num = *numbers;
	while (last_num->next != 0)
		last_num = last_num->next;
	last_num->next = number;
//	free(line->value); // освобождаем память
	free(line);
	line = 0; // обнуляем
}

char *get_substr(const char *str, int index)
{
	int idx;

	idx = 0;
	while (idx < index)
	{
		idx++;
	}
	return (&str[idx]);
}

void process_read_data(d_str **list, d_number **numbers, const char *buffer, int size)
{
	int sep_idx;
	int end_idx;
	int start;

	sep_idx = get_char_idx(buffer, ':');
	end_idx = get_char_idx(buffer, '\n');
//	printf("process_read_data:[%s] sep_idx-%d, end_idx-%d\n", buffer, sep_idx, end_idx);

	if (sep_idx >= 0)
	{
		ft_list_push_back(list, buffer, 0, sep_idx);
		ft_list_push_back(list, ":", 0, 1);
		if (end_idx < 0)
			ft_list_push_back(list, buffer, sep_idx + 1, size - (sep_idx + 1));
		else
		{
			start = sep_idx < end_idx ? sep_idx : 0;
			ft_list_push_back(list, buffer, start, end_idx - start);
		}
	}
	else
		ft_list_push_back(list, buffer, 0, size - (end_idx + 1));

	if (end_idx >= 0)
	{ // sep_idx нет
		start = sep_idx < end_idx ? (sep_idx < 0 ? sep_idx + 1 : sep_idx) : 0;
		ft_list_push_back(list, buffer, start, end_idx - start);

		ft_number_push_back(numbers, *list);
		printf("  ft_number_push_back: (%s) |%s|\n", buffer, (*list)->value);
		*list = create_str_elem(buffer, end_idx + 1, size - (end_idx + 1));
	}
}

d_number *ft_read_file(int fd, int byte_count)
{
	int read_byte;
	char *buffer;
	d_number *numbers;
	d_str *line;

	line = 0;
	line = 0;
	numbers = 0;
	buffer = (char *) malloc(sizeof(char) * (byte_count + 1));
	ft_fill_str(buffer, byte_count);
	while ((read_byte = read(fd, buffer, byte_count)) != 0)
	{
//		printf("ft_read_file: [%s]\n", buffer);
		process_read_data(&line, &numbers, buffer, read_byte);
	}

	free(buffer);
	return (close(fd) == 0 ? numbers : 0);
}

d_number *parse_dictionary(char *path)
{
	int fd;
	if ((fd = ft_open_file(path)))
		return (ft_read_file(fd, BYTE_COUNT));
	return (0);
}
