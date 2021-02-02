#ifndef FT_H
# define FT_H
// 30 ko - o octet (8 бит) или "типа байт" - 30 килобайтов. 1ko = 1000o
// 30000 * 8 = 239000
# define BYTE_COUNT 239000

void	ft_swap(int *a, int *b);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_fill_str(char *str, int size);
void	ft_put_substr(char *str, int size);

#endif
