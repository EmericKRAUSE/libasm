NAME		=	libasm.a
NASM		=	nasm
NASMFLAGS	=	-f elf64
AR			=	ar
ARFLAGS		=	rcs
SRCS		=	src/ft_strlen.s \
				src/ft_strcpy.s \
				src/ft_strcmp.s \
				src/ft_write.s \
				src/ft_read.s \
				src/ft_strdup.s
OBJS		=	$(SRCS:.s=.o)

MAIN		=	src/main.c
TEST_EXEC	=	test
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(TEST_EXEC)

re: fclean all

test: $(NAME)
	$(CC) $(MAIN) $(NAME) -o $(TEST_EXEC)

.PHONY: all clean fclean re test
