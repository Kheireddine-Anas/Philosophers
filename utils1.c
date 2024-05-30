#include "philoshophers.h"

int	check_life(t_philos *philo, int val)
{
	int	fr;

	fr = 0;
	pthread_mutex_lock(&philo->spcf->death);
	if (val)
		philo->spcf->life = 1;
	fr = philo->spcf->life;
	pthread_mutex_unlock(&philo->spcf->death);
	return (fr);
}

void	ft_printer(t_philos *philo, char *str)
{
	if (!check_life(philo, 0))
		printf("%lld %d %s\n", get_time(philo->spcf), philo->id, str);
	return ;
}

void	eating_cycle(t_philos *philo)
{
	pthread_mutex_lock(&philo->spcf->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->spcf->forks[philo->right_fork]);
	ft_printer(philo, "has taken a fork");
	ft_printer(philo, "has taken a fork");
	ft_printer(philo, "is eating");
	pthread_mutex_lock(&philo->spcf->meals);
	philo->lst_meal = get_time(philo->spcf);
	philo->nm_eat += 1;
	pthread_mutex_unlock(&philo->spcf->meals);
	ft_usleep(philo->spcf->t_eat, philo);
	pthread_mutex_unlock(&philo->spcf->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->spcf->forks[philo->right_fork]);
}

int	check_meals(t_philos *philo)
{
	int	frst;
	int	scnd;

	frst = 0;
	while (frst < philo->spcf->n_philos)
	{
		pthread_mutex_lock(&philo->spcf->meals);
		scnd = philo->nm_eat;
		pthread_mutex_unlock(&philo->spcf->meals);
		if (scnd > philo->spcf->n_time)
		{
			if (frst == philo->spcf->n_philos - 1)
				return (0);
		}
		else
			return (1);
		frst++;
	}
	return (1);
}

void	ending_cycle(t_philos *philo, char **argv)
{
	int	frst;
	int	scnd;

	frst = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->spcf->meals);
		scnd = get_time(philo->spcf) - philo[frst].lst_meal;
		pthread_mutex_unlock(&philo->spcf->meals);
		if (philo->spcf->t_die <= scnd
			|| (argv[5] && check_meals(philo) == 0))
		{
			check_life(philo, 1);
			if (philo->spcf->t_die <= scnd)
				printf("%lld %d %s\n", get_time(philo->spcf), philo->id, "died");
			return ;
		}
		frst = (frst + 1) % philo->spcf->n_philos;
	}
}
