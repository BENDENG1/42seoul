#include <unistd.h>

int			ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int			ft_strstr(char *s1, char *s2, int n)
{
	int		i;

	if (!s1 || !s2)
		return (0);
	while (*s2)
	{
		i = 0;
		while (s1[i] && s2[i] && i < n)
		{
			if (s1[i] != s2[i])
				break ;
			i++;
		}
		if (i == n || !s1[i])
			return (1);
		s2++;
	}
	return (0);
}

// i_j_m_l_i = arr
void		str_maxlenoc(int nb, char **tab)
{
	char	*test;
	int		arr[5] = {-1, -1, 0, 1, 0};

	test = tab[0];
	while (++arr[1] < ft_strlen(tab[0]))
	{
		while (arr[1] + arr[3] <= ft_strlen(tab[0]))
		{
			arr[0] = -1;
			while (++arr[0] < nb)
			{
				if (!ft_strstr(&test[arr[1]], tab[arr[0]], arr[3]))
					break ;
			}
			if (arr[0] < nb)
				break ;
			if (arr[3] > arr[2])
			{
				arr[2] = arr[3];
				arr[4] = arr[1];
			}
			arr[3]++;
		}
	}
	write(1, &test[arr[4]], arr[3] - 1);
}

int			main(int argc, char **argv)
{
	if (argc > 1)
		str_maxlenoc(argc - 1, &argv[1]);
	write(1, "\n", 1);
	return (0);
}


/*
Assignment name  : str_maxlenoc
Expected files   : str_maxlenoc.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes one or more strings and displays, followed by a
newline, the longest string that appears in every parameter. If more that one
string qualifies, it will display the one that appears first in the first
parameter. Note that the empty string technically appears in any string.

If there are no parameters, the program displays \n.

Examples:

$>./str_maxlenoc ab bac abacabccabcb
a
$>./str_maxlenoc bonjour salut bonjour bonjour
u
$>./str_maxlenoc xoxAoxo xoxAox  oxAox oxo  A ooxAoxx oxooxo Axo | cat -e
$
$>./str_maxlenoc bosdsdfnjodur atehhellosd afkuonjosurafg headfgllosf fghellosag afdfbosnjourafg
os
$>./str_maxlenoc | cat -e
$


*/
