# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhan <hhan@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 15:21:39 by hhan              #+#    #+#              #
#    Updated: 2020/03/06 15:25:47 by hhan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   libft.a
HEADER      =   libft.h
CC          =   gcc
FLAGS       =   -Wall -Wextra -Werror -c
INCLUDE     =   -include $(HEADER)
SRCS        =   ft_atoi.c\
                ft_bzero.c\
                ft_calloc.c\
                ft_isalnum.c\
                ft_isalpha.c\
                ft_isascii.c\
                ft_isdigit.c\
                ft_isprint.c\
                ft_itoa.c\
                ft_lstadd_back.c\
                ft_lstadd_front.c\
                ft_lstclear.c\
                ft_lstdelone.c\
                ft_lstiter.c\
                ft_lstlast.c\
                ft_lstmap.c\
                ft_lstnew.c\
                ft_lstsize.c\
                ft_memccpy.c\
                ft_memchr.c\
                ft_memcmp.c\
                ft_memcpy.c\
                ft_memmove.c\
                ft_memset.c\
                ft_putchar_fd.c\
                ft_putendl_fd.c\
                ft_putnbr_fd.c\
                ft_putstr_fd.c\
                ft_split.c\
                ft_strchr.c\
                ft_strdup.c\
                ft_strjoin.c\
                ft_strlcat.c\
                ft_strlcpy.c\
                ft_strlen.c\
                ft_strmapi.c\
                ft_strncmp.c\
                ft_strnstr.c\
                ft_strrchr.c\
                ft_strtrim.c\
                ft_substr.c\
                ft_tolower.c\
                ft_toupper.c
SOURCE = $(wildcard *.c)
OBJS        =   $(SOURCE:.c=.o)

$(NAME)     :   
	$(CC) $(FLAGS) *.c $(INCLUDE)
	ar rc $(NAME) $(OBJS)

all         :   $(NAME)

clean       :
	rm -f $(OBJS)
fclean      :	clean
	rm -f $(NAME)
re          :   fclean all

.PHONY : all clean
