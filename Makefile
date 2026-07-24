NAME		=	libasm.a

NASM		=	nasm
NASMFLAGS	=	-f elf64
AR			=	ar
ARFLAGS		=	rcs

SRCS		=	src/ft_strlen.s \
				src/ft_strcpy.s

OBJS		=	$(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
