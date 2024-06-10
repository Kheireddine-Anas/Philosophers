/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:51:54 by akheired          #+#    #+#             */
/*   Updated: 2024/06/10 23:37:59 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philos(t_philos *philo, char **argv)
{
	int			i;

	i = -1;
	philo->n_philos = ft_atoi(argv[1]);
	philo->t_die = ft_atoi(argv[2]);
	philo->t_eat = ft_atoi(argv[3]);
	philo->t_sleep = ft_atoi(argv[4]);
	philo->n_time = -1;
	if (argv[5])
		philo->n_time = ft_atoi(argv[5]);
	philo->nt_eated = malloc(philo->n_philos * sizeof(int));
	philo->mutexs = malloc((philo->n_philos + 1) * sizeof(pthread_mutex_t));
}

void	*repetition(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	if (data->left_fork == data->philo->n_philos)
		data->left_fork = 0;
	if (data->id % 2 != 0)
	{
		ft_printer(data, "is thinking");
		ft_usleep(data->philo->t_eat, data);
	}
	while (1)
	{
		if (check_life(data, 0))
			return (NULL);
		pthread_mutex_lock(&data->philo->mutexs[data->right_fork]);
		pthread_mutex_lock(&data->philo->mutexs[data->left_fork]);
		eating_cycle(data);
		pthread_mutex_unlock(&data->philo->mutexs[data->right_fork]);
		pthread_mutex_unlock(&data->philo->mutexs[data->left_fork]);
		ft_printer(data, "is sleeping");
		ft_usleep(data->philo->t_sleep, data);
		ft_printer(data, "is thinking");
	}
	return (NULL);
}

void	ft_destroy(t_data *data)
{
	int	i;

	i = -1;
	while (++i <= data->philo->n_philos)
	{
		pthread_mutex_destroy(&data->philo->mutexs[i]);
		if (i < data->philo->n_philos)
			pthread_mutex_destroy(&data[i].mutexs);
	}
	free(data->philo->mutexs);
	free(data->philo->nt_eated);
	free(data);
}

void	thread_make(t_data *data, t_philos *philo)
{
	int	i;

	i = 0;
	while (i <= philo->n_philos)
	{
		pthread_mutex_init(&philo->mutexs[i], NULL);
		if (i < philo->n_philos)
			pthread_mutex_init(&data[i].mutexs, NULL);
		i++;
	}
	philo->state = 0;
	i = -1;
	gettimeofday(&philo->str_tm, NULL);
	while (++i < philo->n_philos)
	{
		data[i].id = i + 1;
		data[i].philo = philo;
		data[i].right_fork = i;
		data[i].left_fork = (i + 1);
		philo->nt_eated[i] = 0;
		gettimeofday(&data[i].last_meal, NULL);
		pthread_create(&data[i].thrd, NULL, repetition, &data[i]);
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

int	main(int argc, char **argv)
{
	t_data		*data;
	t_philos	philo;

	checking(argc, argv);
	data = malloc(sizeof(t_data) * ft_atoi(argv[1]));
	init_philos(&philo, argv);
	thread_make(data, &philo);
	ending_cycle(data);
	thread_join(data, philo.n_philos);
	ft_destroy(data);
}
