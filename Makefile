# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mo0k <mo0k@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 09:22:47 by mo0k              #+#    #+#              #
#    Updated: 2018/05/31 13:55:45 by mo0k             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME =				libfts.a
CFLAGS =			-f macho64
ASM = 				nasm
CC = 				gcc

SRCS_PATH = 		srcs

SRCS = 			 ft_bzero.s \
				ft_isalpha.s \
				ft_isdigit.s \
				ft_isalnum.s \
				ft_isascii.s \
				ft_isprint.s \
				ft_isupper.s \
				ft_toupper.s \
				ft_islower.s \
				ft_tolower.s \
				ft_memcpy.s \
				ft_memset.s \
				ft_puts.s \
				ft_strcat.s \
				ft_strlen.s \
				ft_strdup.s \
				ft_cat.s \
				ft_memrcpy.s \
				ft_memmove.s \
				ft_memcmp.s
				 


OBJS =				$(SRCS:%.s=%.o)

C_LGREEN = "\033[92m"
C_LRED = "\033[91m"
C_RED = "\033[31m"
C_DFL	="\033[0m"

ECHO = echo -n


all: $(NAME)

$(NAME): $(OBJS) Makefile
	ar rcs $(NAME) $(OBJS)
	
%.o: %.s
	$(ASM) $(CFLAGS) -o $@ $<

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)
re: fclean all

.PHONY: OBJS clean fclean