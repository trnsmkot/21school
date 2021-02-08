SRC_DIR 	= ./src
INC_DIR 	= ./include
SRC_FILES 	= $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ_FILES 	= $(shell find $(SRC_DIR) -type f -name "*.o")
OBJS 		= ${SRC_FILES:.c=.o}
NAME 		= bsq
CFLAGS		= -Wall -Wextra -Werror

all:		${OBJS}
			gcc ${CFLAGS} -I${INC_DIR} ${OBJ_FILES} -o ${NAME}

clean:
			rm -f ${OBJ_FILES}

fclean:		clean
			rm -f ${NAME}

re:			clean all

.PHONY:     all clean fclean re