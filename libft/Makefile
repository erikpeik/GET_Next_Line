# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emende <emende@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 15:19:20 by emende            #+#    #+#              #
#    Updated: 2022/01/12 01:05:33 by emende           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_strnew.c ft_strdup.c ft_strchr.c ft_strjoin.c \
	   ft_strdel.c ft_bzero.c ft_memset.c ft_memcpy.c \
	   ft_strlen.c

OBJS = $(SRCS:.c=.o)

OPTIONS = -c

CFLAG = -Wall -Wextra -Werror -Wconversion

all: $(NAME)

$(NAME):
	@echo "[LIBFT] Making objects..."
	@gcc $(CFLAG) $(OPTIONS) $(SRCS)
	@echo "[LIBFT] Crating library from object files..."
	@ar rcs $(NAME) $(OBJS)
	@echo "[LIBFT] Generated archive libft.a"

clean:
	@echo "[LIBFT] Cleaning object files..."
	@/bin/rm -f $(OBJS)

fclean: clean
	@echo "[LIBFT] Removing libft.a library file..."
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
