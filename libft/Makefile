SRC_DIR 	= "."
EXCLUDE_DIR = "./cmake-build-debug/*"
INC_DIR 	= "."
SRC_FILES 	= $(shell find $(SRC_DIR) -type f -name "*.c" ! -path $(EXCLUDE_DIR))
OBJ_FILES 	= $(shell find $(SRC_DIR) -type f -name "*.o" ! -path $(EXCLUDE_DIR))
OBJ			= $(SRC_FILES:%.c=%.o)
NAME 		= libft.a
CFLAGS		= -Wall -Wextra -Werror

all: 		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ_FILES)

$(OBJ): 	$(FILES)
			gcc $(CFLAGS) -I. -c $(SRC_FILES)

clean:
			rm -f $(OBJ_FILES)

fclean:		clean
			rm -f $(NAME)

re:			clean all

.PHONY:     all clean fclean re