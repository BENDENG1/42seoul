#include <stdlib.h>
#include <unistd.h>

void fpr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

char *fstrsub(char *r, int n)
{
	char *s = malloc(n + 1);
	int i;
	for (i = 0; i < n; i++)
		s[i] = r[i];
	s[i] = 0;
	return s;
}

int len(char *s)
{
	int i = 0;
	while (*s++)
		i++;
	return i;
}

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		char *mn = av[1];
		for (int i = 2; i < ac; i++)
		{
			int mx = 0;
			char *st = NULL;
			for (char *s = mn; *s; s++)
			{
				for (char *r = av[i]; *r; r++)
				{
					int n = 0;
					char *_s = s, *_r = r;
					while (*_s && *_r && *_s == *_r)
					{
						_s++;
						_r++;
						n++;
					}
					if (n > mx)
					{
						mx = n;
						st = s;
					}
				}
			}
			if (mx < len(mn))
				mn = fstrsub(st, mx);
		}
		fpr(mn);
	}
	fpr("\n");
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
