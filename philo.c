#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

void	*func(void *arg)
{
	while (1)
	{
		printf("L");
		sleep((unsigned int)0.8);
	}	
	
	return NULL;
}
void	*func1(void *arg)
{
	while (1)
	{
		printf("M");
		sleep((unsigned int)0.8);
	}
	return NULL;
}

int	main()
{
	pthread_t	thread1, thread2;
	pthread_create(&thread1, NULL, &func, NULL);
	pthread_create(&thread2, NULL, &func1, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
}