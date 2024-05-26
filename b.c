#include <sys/time.h>
#include <stdio.h>

long long gettime() {
	struct timeval time;

	gettimeofday(&time, NULL);
	return (((long long)time.tv_sec * 1000 + (long long)time.tv_usec / 1000));
}

int main()
{
	printf("%lld\n", gettime());
}