/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:52:08 by akheired          #+#    #+#             */
/*   Updated: 2024/06/10 23:17:39 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philos
{
	int				n_philos;
	int				state;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_time;
	int				*nt_eated;
	pthread_mutex_t	*mutexs;
	struct timeval	str_tm;
}				t_philos;

typedef struct s_data
{
	t_philos		*philo;
	int				strt;
	int				id;
	int				left_fork;
	int				right_fork;
	struct timeval	last_meal;
	pthread_t		thrd;
	pthread_mutex_t	mutexs;
}			t_data;

long long	get_time(t_data *data);
int			ft_atoi(char *str);
int			check_life(t_data *data, int val);
void		checking_one(int argc, char **argv);
void		checking(int argc, char **argv);
void		ft_usleep(int time, t_data *data);
void		ft_printer(t_data *data, char *str);
void		eating_cycle(t_data *data);
void		ending_cycle(t_data *data);
void		ft_destroy(t_data *data);

#endif