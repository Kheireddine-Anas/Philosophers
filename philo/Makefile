# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akheired <akheired@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 19:49:26 by akheired          #+#    #+#              #
#    Updated: 2024/06/10 16:18:58 by akheired         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# CFLAGS = -Wall -Werror -Wextra 
# LDFLAGS = -Wall -Werror -Wextra 

# philo: philo.o utils.o utils1.o
# 	$(CC) $(LDFLAGS) $^ -o $@

# philo.o: philo.c
# 	$(CC) $(CFLAGS) -c philo.c

# utils.o: utils.c
# 	$(CC) $(CFLAGS) -c utils.c

# utils1.o: utils1.c
# 	$(CC) $(CFLAGS) -c utils1.c

# clean:
# 	rm -f *.o philo

NAME = philo

SRCS = philo.c utils1.c utils.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -fsanitize=thread -g

all: $(NAME)


$(NAME): $(OBJS) philosophers.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re : fclean all
