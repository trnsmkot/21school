SRC_DIR 		= "."
EXCLUDE_DIR 	= "./cmake-build-debug/*"
INC_DIR 		= "."
SRC_FILES 		= ft_memset.c
OBJ_FILES		= $(SRC_FILES:.c=.o)
SRC_FILES_BONUS	=
OBJ_FILES_BONUS	= $(SRC_FILES_BONUS:.c=.o)
NAME 			= libft.a
CFLAGS			= -Wall -Wextra -Werror

all: 			$(NAME)

$(NAME):		$(OBJ_FILES)
				ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_FILES): 	$(SRC_FILES)
				gcc $(CFLAGS) -I. -c $(SRC_FILES)

bonus:			$(OBJ_FILES) $(OBJ_FILES_BONUS)
				ar rcs $(NAME) $(OBJ_FILES) $(OBJ_FILES_BONUS)

clean:
				rm -f $(OBJ_FILES)

fclean:			clean
				rm -f $(NAME)

re:				clean all

.PHONY:     	all clean fclean re