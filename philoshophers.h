#ifndef PHILOSHOPHERS_H
# define PHILOSHOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct 	s_philos
{
	int					nm_eat;
	int					id;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		*right_fork;
}						t_philos;

typedef struct	s_data
{
	int			n_philos;
	t_philos	*philo;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			n_time;
}				t_data;

#endif