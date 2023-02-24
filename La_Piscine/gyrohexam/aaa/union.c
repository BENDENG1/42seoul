/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:55:57 by gyroh             #+#    #+#             */
/*   Updated: 2022/05/05 15:09:52 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_strcat(char *a, char *b)
{
	int	alen;
	int	blen;
	int	i;

	i = 0;
	alen = 0;
	blen = 0;
	while (a[alen] != '\0')
	{
		alen++;
	}
	while (b[blen] != '\0')
	{
		a[alen] = b[blen];
		alen++;
		blen++;
	}
	a[alen] = 0;
	return (a);
}

int main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac == 3)
	{
		char	*str;
		str = ft_strcat(av[1], av[2]);
		while (str[i])
		{
			j = 0;
			while (j < i)
			{
				if (str[i] == str[j])
					break;
				j++;
			}
			if (j == i)
				write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>

*/
