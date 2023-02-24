#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void rush(int x, int y);

int main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		return (0);
	while (argv[1][i] != '\0')
	{
		if (!('0' <= argv[1][i] && argv[1][i] <= '9'))
			return (0);
		i++;
	}
	i = 0;
	while (argv[2][i] != '\0')
	{
		if (!('0' <= argv[2][i] && argv[2][i] <= '9'))
			return(0);
		i++;
	}
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	rush (a, b);
	return (0);
}
