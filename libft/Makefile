SRC_DIR 	= .
EXCLUDE_DIR = "./cmake-build-debug/*"
INC_DIR 	= "./include"
SRC_FILES 	= $(shell find $(SRC_DIR) -type f -name "*.c" ! -path $(EXCLUDE_DIR))
OBJ_FILES 	= $(shell find $(SRC_DIR) -type f -name "*.o" ! -path $(EXCLUDE_DIR))
OBJS 		= ${SRC_FILES:.c=.o}
NAME 		= libft
CFLAGS		= -Wall -Wextra -Werror

all:		${OBJS}
			gcc ${CFLAGS} -I${INC_DIR} -c ${SRC_FILES}
			ar rc ${NAME}.a ${OBJ_FILES}

clean:
			rm -f ${OBJ_FILES}

fclean:		clean
			rm -f ${NAME}.a

re:			clean all

.PHONY:     all clean fclean re