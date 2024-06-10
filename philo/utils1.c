/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:51:58 by akheired          #+#    #+#             */
/*   Updated: 2024/06/10 23:31:51 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_life(t_data *data, int val)
{
	int	fr;

	fr = 0;
	pthread_mutex_lock(&data->philo->mutexs[data->philo->n_philos]);
	if (val)
		data->philo->state = 1;
	fr = data->philo->state;
	pthread_mutex_unlock(&data->philo->mutexs[data->philo->n_philos]);
	return (fr);
}

void	ft_printer(t_data *dt, char *str)
{
	struct timeval	t0;
	int				strt;
	int				at;

	strt = dt->philo->str_tm.tv_sec * 1000 + dt->philo->str_tm.tv_usec / 1000;
	if (!check_life(dt, 0))
	{
		gettimeofday(&t0, NULL);
		at = t0.tv_sec * 1000 + t0.tv_usec / 1000;
		printf("%d %d %s\n", at - strt, dt->id, str);
	}
	return ;
}

void	eating_cycle(t_data *data)
{
	ft_printer(data, "has taken a fork");
	ft_printer(data, "has taken a fork");
	ft_printer(data, "is eating");
	ft_usleep(data->philo->t_eat, data);
	gettimeofday(&data->last_meal, NULL);
	pthread_mutex_lock(&data->mutexs);
	data->philo->nt_eated[data->id - 1] += 1;
	pthread_mutex_unlock(&data->mutexs);
}

int	check_meals(t_data *data)
{
	int	frst;
	int	scnd;

	frst = 0;
	while (frst < data->philo->n_philos && data->philo->n_time != -1)
	{
		pthread_mutex_lock(&data[frst].mutexs);
		scnd = data->philo->nt_eated[frst];
		pthread_mutex_unlock(&data[frst].mutexs);
		if (scnd >= data->philo->n_time)
		{
			if (frst == data->philo->n_philos - 1)
				return (0);
		}
		else
			return (1);
		frst++;
	}
	return (1);
}

void	ending_cycle(t_data *dt)
{
	int				st;
	int				scnd;
	struct timeval	t0;
	int				lst;

	st = 0;
	while (1)
	{
		gettimeofday(&t0, NULL);
		scnd = t0.tv_sec * 1000 + t0.tv_usec / 1000;
		lst = dt[st].last_meal.tv_sec * 1000 + dt[st].last_meal.tv_usec / 1000;
		dt->strt = dt->philo->str_tm.tv_sec * 1000;
		dt->strt += dt->philo->str_tm.tv_usec / 1000;
		if (dt->philo->t_die < scnd - lst || check_meals(dt) == 0)
		{
			check_life(dt, 1);
			usleep(750);
			if (dt->philo->t_die < scnd - lst)
				printf("%d %d %s\n", scnd - dt->strt, dt[st].id, "died");
			return ;
		}
		if (st == dt->philo->n_philos - 1)
			st = -1;
		st++;
	}
}
