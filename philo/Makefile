# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akheired <akheired@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 19:49:26 by akheired          #+#    #+#              #
#    Updated: 2024/06/11 10:49:33 by akheired         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

SRCS = philo.c utils1.c utils.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g

all: $(NAME)


$(NAME): $(OBJS) philosophers.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re : fclean all
