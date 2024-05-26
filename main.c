#include "philoshophers.h"

int	ft_atoi(char *str)
{
	int	sig;
	int	rzl;

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
	}
	return (rzl * sig);
}

void	checking_nums(int argc, char **argv)
{
	if (ft_atoi(argv[1]) <= 0 && ft_atoi(argv[1]) >= 200)
	{
		printf("\x1B[31mWrong ARGS\n");
		exit(1);
	}
	
}

void	checking_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				exit(1);
			j++;
		}
		i++;
	}
	checking_nums(argc, argv);
}

void	init(t_data *data, int argc, char **argv)
{
	int i = 0;
	data->n_philos = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->n_time = -1;
	if (argc == 6)
		data->n_time = ft_atoi(argv[5]);
	data->philo = malloc(sizeof(t_philos) * data->n_philos);
	while (i < data->n_philos)
	{
		data->philo[i].id = i + 1;
		data->philo[i].nm_eat = data->n_time;
		printf("%d\n", data->philo[i].nm_eat);
		i++;
	}
}

void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_init(data.philo[i]->left_fork, NULL);
	}
	
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 5 || argc == 6)
	{
		checking_args(argv);
		data = malloc(sizeof(t_data));
		init(data, argc, argv);
		init_forks(data);
	}
}