#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i] != 0)
	{
		i++;
	}

	return i;
}

int main(int ac, char **av)
{
	char ascii[255];
	char str[4096]={0,};

	if (ac == 3)
	{
		int av1Length = ft_strlen(av[1]);
		int av2Length = ft_strlen(av[2]);

		for(int i = 0; i < 255; i ++){
			ascii[i] = 0;
		}

		for (int i = 0; i < av1Length; i++)
		{
			str[i] += av[1][i];
		}

		for (int i = av1Length; i < av1Length + av2Length; i++)
		{
			str[i] += av[2][i];
		}
		str[av1Length + av2Length] = 0;

		for(int i = 0; i < av1Length + av2Length;i++){
			if(ascii[(int)str[i]] != 1){
				ascii[(int)str[i]] = 1;
				write(1,&str[i],1);
			}
		}
	}

	write(1, "\n", 1);
}
