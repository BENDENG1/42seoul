
#include <stdlib.h>

char	**ft_split(char *str)
{
	int	i;
	int	j;
	int	k;
	char **arr;

	i = 0;
	k = 0;
	if(!(arr = (char **)malloc(sizeof(char *) * 256)))
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		j = 0;
		if(!(arr[k] = (char *)malloc(sizeof(char) * 4000)))
			return (0);
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
		{
			arr[k][j] = str[i];
			j++;
			i++;
		}
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		arr[k][j] = 0;
		k++;
	}
	arr[k] = 0;
	return (arr);
}


#include <stdio.h>
int main(int ac, char **av)
{
	int	i = 0;
	char **split;
	(void) ac;

	split = ft_split(av[1]);
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}

/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);

*/
