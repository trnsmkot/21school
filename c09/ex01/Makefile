SRC_DIR 	= ./srcs
SRC_FILES 	= $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES 	= $(wildcard $(SRC_DIR)/*.o)
H_FILES 	= ./includes/ft.h
OBJS 		= ${SRC_FILES:.c=.o}
NAME 		= libft.a
NAME_H 		= libft.h

CFLAGS		= -Wall -Wextra -Werror
.c.o:
			gcc ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${SRC_DIR}/*.o
			cp ${H_FILES} ./${NAME_H}

all:		${NAME}

clean:
			rm -f ${OBJ_FILES}

fclean:		clean
			rm -f ${NAME_H} ${NAME}

re:			clean all

.PHONY: all clean fclean re