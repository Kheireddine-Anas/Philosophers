/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:52:03 by akheired          #+#    #+#             */
/*   Updated: 2024/06/10 23:46:23 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *str)
{
	int		sig;
	long	rzl;

	sig = 1;
	rzl = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sig = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		rzl = rzl * 10 + (*str - 48);
		str++;
		if (rzl > INT_MAX)
		{
			printf("\x1B[31mWrong ARGS\n");
			exit(1);
		}
	}
	return (rzl * sig);
}

void	checking_one(int argc, char **argv)
{
	if (ft_atoi(argv[4]) < 60)
	{
		printf("\x1B[31mWrong ARGS time to sleep\n");
		exit(1);
	}
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
	{
		printf("\x1B[31mWrong ARGS n_time to eat\n");
		exit(1);
	}
}

void	checking(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("\x1B[31mWrong ARGS Nums\n");
		exit(1);
	}
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
	{
		printf("\x1B[31mWrong ARGS Philos\n");
		exit(1);
	}
	if (ft_atoi(argv[2]) < 60)
	{
		printf("\x1B[31mWrong ARGS time to die\n");
		exit(1);
	}
	if (ft_atoi(argv[3]) < 60)
	{
		printf("\x1B[31mWrong ARGS time to eat\n");
		exit(1);
	}
	checking_one(argc, argv);
}

void	ft_usleep(int time, t_data *data)
{
	struct timeval	frst;
	struct timeval	scnd;

	gettimeofday(&frst, 0);
	while (1)
	{
		if (check_life(data, 0))
			return ;
		gettimeofday(&scnd, 0);
		if (((scnd.tv_sec * 1000 + scnd.tv_usec / 1000)
				- (frst.tv_sec * 1000 + frst.tv_usec / 1000)) >= time)
			return ;
		usleep(200);
	}
}

void	thread_join(t_data *data, int philos)
{
	int	i;

	i = 0;
	pthread_mutex_unlock(&data->philo->mutexs[data->right_fork]);
	while (i < philos)
		pthread_join(data[i++].thrd, NULL);
}
