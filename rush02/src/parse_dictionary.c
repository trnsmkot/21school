#include <libc.h>
#include "../includes/rush.h"

int ft_open_file(char *file)
{
	return (open(file, O_RDONLY));
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

int get_line_path_size(d_str *dstr, d_str **d_value, int is_key)
{
	d_str *element;
	int size;

	size = 0;
	element = dstr;
	*d_value = dstr;
	while (element != 0)
	{
		if (element->size == 1 && element->value[0] == ':')
		{
			if (!is_key)
			{
				size = -1;
				*d_value = element->next;
			}
			else
				return (size);
		}
		size += element->size;
		element = element->next;
	}
	return (size);
}

void convert_key_to_d(char *line, d_str *str)
{
	int index;
	int sub_idx;
	d_str *element;
	char ch;

	index = 0;
	element = str;
	while (element)
	{
		sub_idx = 0;
		while (sub_idx < element->size)
		{
			ch = element->value[sub_idx];
			if (ch == ':')
				return;
			if (ch != ' ' && ch != '\0' && ch != '\n')
			{
				line[index] = ch;
				index++;
			}
			sub_idx++;
		}
		element = element->next;
	}
}

void convert_value_to_d(char *line, d_str *str)
{
	int index;
	int sub_idx;
	d_str *element;
	char ch;
	int space;

	space = 0;
	index = 0;
	element = str;
	while ((element))
	{
		sub_idx = 0;
		while (sub_idx < element->size)
		{
			if (((ch = element->value[sub_idx]) != ' ' || space) && ch != '\0' && ch != '\n')
			{
				line[index] = ch;
				index++;
				space = 1;
			}
			sub_idx++;
		}
		element = element->next;
	}
}

void free_d_str(d_str *dstr)
{
	d_str *element;
	d_str *next_element;

	next_element = dstr;
	while (next_element)
	{
		element = next_element;
		next_element = next_element->next;
		free(element->value);
		free(element);
	}
}

void add_divs_to_ranges(d_number *number, int index, int index_div, int size_div)
{
	int sum;

	while (index_div < size_div)
	{
		sum = 0;
		sum = (sum * 10) + (number->key[index] - '0');
		sum = (sum * 10) + (number->key[index + 1] - '0');
		sum = (sum * 10) + (number->key[index + 2] - '0');
		number->ranges[index_div] = sum;
		index_div++;
		index += 3;
	}
}

void add_num_to_ranges(d_number *number)
{
	int index;
	int size_div;
	int size_mod;
	int sum;

	sum = 0;
	index = 0;
	size_mod = number->size % 3;
	size_div = number->size / 3;
	number->size = size_div + (size_mod > 0);
	number->ranges = (int *) malloc(sizeof(int) * number->size);
	while (index < size_mod)
	{
		sum = (sum * 10) + (number->key[index] - '0');
		index++;
	}
	if (size_mod > 0)
		number->ranges[0] = sum;
	add_divs_to_ranges(number, index, size_mod > 0, size_div + (size_mod > 0 && size_div > 0));
}

void convert_str_t_ranges(d_number **num)
{
	d_number *number;

	number = *num;
	if (number)
	{
		number->size = ft_strlen(number->key);
		add_num_to_ranges(number);
	}
}

d_number *create_num_elem(d_str *dstr)
{
	d_number *num;
	d_str *d_value;
	d_str *d_key;
	int size_v;
	int size_k;

	num = (d_number *) malloc(sizeof(d_number));
	if (num)
	{
		size_k = get_line_path_size(dstr, &d_key, 1) + 1;
		size_v = get_line_path_size(dstr, &d_value, 0) + 1;
		num->key = (char *) malloc(sizeof(char) * size_k);
		num->value = (char *) malloc(sizeof(char) * size_v);
		ft_fill_str(num->key, size_k);
		ft_fill_str(num->value, size_v);
		convert_key_to_d(num->key, d_key);
		convert_value_to_d(num->value, d_value);
		free_d_str(d_key);
		convert_str_t_ranges(&num);
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
	line = 0; // обнуляем
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
//		printf("  ft_number_push_back: (%s) |%s|\n", buffer, (*list)->value);
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
