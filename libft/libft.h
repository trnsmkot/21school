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

#endif
