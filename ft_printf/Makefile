SRCS	= ./ft_printf.c \
	  ./print_csd.c \
	  ./utils.c \
	  ./manages.c \
	  ./print_utils.c

NAME	= libftprintf.a
OBJS	= ${SRCS:%.c=%.o}

FLAGS	= -Wall -Wextra -Werror

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I ./
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re : fclean all
