# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 11:25:15 by nasamadi          #+#    #+#              #
#    Updated: 2022/10/07 14:06:59 by nasamadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color Aliases

DEFAULT = \033[0m
GRAY = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m

# Variables
CC = gcc
NAME = libftprintf.a
MAKE = make
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_printf_utils.c
HEAD = ft_printf.h
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS) $(HEAD)
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) is up to date!$(DEFAULT)"

.c.o :
	@$(CC) $(FLAGS) -c $<  -o $(<:.c=.o)
	@echo "$(YELLOW)Compiling $< $ $(DEFAULT)"

all : $(NAME)

clean :
	@rm -f ${OBJS}
	@echo "${RED}\t   ----clean--- ft_printf's object files cleaned!$(DEFAULT)"

fclean : clean
	@rm -f $(NAME)
	@echo "${RED}\t   ---fclean--- ft_printf's executable files cleaned!$(DEFAULT)"

norminette :
	@echo "$(MAGENTA)Checking norm for ft_printf...$(DEFAULT)"
	@norminette -R CheckForbiddenSourceHeader $(SRCS)

re : fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$((DEFAULT)"

.PHONY: clean fclean norminette all re
