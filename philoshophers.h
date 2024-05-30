#ifndef PHILOSHOPHERS_H
# define PHILOSHOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data
{
	int				n_philos;
	int				life;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_time;
	pthread_mutex_t	printer;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death;
	pthread_mutex_t	meals;
	struct timeval	tm;
}				t_data;

typedef struct s_philos
{
	int			nm_eat;
	int			id;
	int			left_fork;
	int			right_fork;
	int			lst_meal;
	pthread_t	thrd;
	t_data		*spcf;
}			t_philos;

long long	get_time(t_data *data);
int			ft_atoi(char *str);
int			check_life(t_philos *philo, int val);
void		checking_one(int argc, char **argv);
void		checking(int argc, char **argv);
void		ft_usleep(int time, t_philos *philo);
void		ft_printer(t_philos *philo, char *str);
void		ending_cycle(t_philos *philo, char **argv);
void		eating_cycle(t_philos *philo);

#endif