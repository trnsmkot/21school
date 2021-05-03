#ifndef LIBFT_H
#define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef	struct	s_list
{
    void			*content;
    struct s_list	*next;
}				t_list;

typedef struct	s_split_next
{
    size_t start;
    size_t length;
}				t_split_next;

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

#endif
