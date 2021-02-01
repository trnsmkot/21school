SRC_DIR 	= ./srcs
SRC_FILES 	= $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES 	= $(wildcard $(SRC_DIR)/*.o)
H_FILES 	= ./includes/ft.h
OBJS 		= ${SRC_FILES:.c=.o}
NAME 		= ft_display_file
CFLAGS		= -Wall -Wextra -Werror

.c.o:		gcc ${CFLAGS} -I${H_FILES} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			gcc ${CFLAGS} -I${H_FILES} ${OBJ_FILES} main.c -o ${NAME}
			#gcc ${CFLAGS} -I${H_FILES} ${NAME}
			#ar rc ${NAME} ${SRC_DIR}/*.o
			#runlib ${NAME}

all:		${NAME}

clean:
			rm -f ${OBJ_FILES}

fclean:		clean
			rm -f ${NAME_H} ${NAME}

re:			clean all

.PHONY:     all clean fclean re