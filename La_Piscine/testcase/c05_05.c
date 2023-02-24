#include <stdio.h>

int main()
{
	int i;

	i = 1;
	while(i<46350)
	{
		printf("%d  %d\n", i*i, i);
		i++;
	}
}
