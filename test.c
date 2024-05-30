// #include <sys/time.h>
// #include <stdio.h>

// long long gettime() {
// 	struct timeval time;

// 	gettimeofday(&time, NULL);
// 	return (((long long)time.tv_sec * 1000 + (long long)time.tv_usec / 1000));
// }

// int main()
// {
// 	printf("%lld\n", gettime());
// }
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