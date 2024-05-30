#include "philoshophers.h"

t_philos	*init(t_data *data, char **argv)
{
	int			i;
	t_philos	*philo;

	i = -1;
	data->n_philos = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->n_time = ft_atoi(argv[5]);
	philo = malloc(sizeof(t_philos) * data->n_philos);
	gettimeofday(&data->tm, NULL);
	while (++i < data->n_philos)
	{
		philo[i].id = i + 1;
		philo[i].right_fork = i;
		philo[i].left_fork = i + 1;
		if (i == data->n_philos - 1)
			philo[i].left_fork = 0;
		philo[i].spcf = data;
		philo[i].nm_eat = 0;
		philo[i].lst_meal = get_time(data);
		pthread_mutex_init(&data->forks[i], NULL);
	}
	return (philo);
}

void	repetition(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	if (philo->id % 2 != 0)
	{
		ft_printer(philo, "is thinking");
		ft_usleep(philo->spcf->t_eat, philo);
	}
	while (1)
	{
		if (check_life(philo, 0))
			return ;
		eating_cycle(philo);
		ft_printer(philo, "is sleeping");
		ft_usleep(philo->spcf->t_sleep, philo);
		ft_printer(philo, "is thinking");
	}
}

void	thread_make(t_philos *philo)
{
	int	i;

	pthread_mutex_init(&philo->spcf->printer, 0);
	pthread_mutex_init(&philo->spcf->meals, 0);
	pthread_mutex_init(&philo->spcf->death, 0);
	philo->spcf->life = 0;
	i = 0;
	while (i < philo->spcf->n_philos)
	{
		pthread_mutex_init(&philo->spcf->forks[i], 0);
		i++;
	}
	i = 0;
	while (i < philo->spcf->n_philos)
	{
		pthread_create(&philo[i].thrd, NULL, (void *)repetition, &philo[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_philos	*philo;

	philo = NULL;
	checking(argc, argv);
	data.forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	philo = init(&data, argv);
	thread_make(philo);
	ending_cycle(philo, argv);
}
