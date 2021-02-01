SRC_DIR 	= ./srcs
SRC_FILES 	= $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ_FILES 	= $(shell find $(SRC_DIR) -type f -name "*.o")
H_FILES 	= ./includes/ft.h
OBJS 		= ${SRC_FILES:.c=.o}
NAME 		= ft_display_file
CFLAGS		= -Wall -Wextra -Werror

.c.o:		gcc ${CFLAGS} -I${H_FILES} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			gcc ${CFLAGS} -I${H_FILES} ${OBJ_FILES} -o ${NAME}

all:		${NAME}

clean:
			rm -f ${OBJ_FILES}

fclean:		clean
			rm -f ${NAME_H} ${NAME}

re:			clean all

.PHONY:     all clean fclean re