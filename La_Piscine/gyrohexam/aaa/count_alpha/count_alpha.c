
#include <stdio.h>

int is_alpha(char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

char lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 32;
	return c;
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int m[127] = {0};
		char *s = av[1];
		int count = 0;
		for (int i = 0; s[i]; i++)
		{
			unsigned char c = lower(s[i]);
			if (is_alpha(c) && !m[c])
			{
				int n = 0;
				for (int j = i; s[j]; j++)
					if (lower(s[j]) == c)
						n++;
				if (count)
					printf(", ");
				printf("%d%c", n, c);
				m[c] = 1;
				count++;
			}
		}
	}
	printf("\n");
}


/*
Assignment name  : count_alpha
Expected files   : count_alpha.c
Allowed functions: write, printf
--------------------------------------------------------------------------------

Write a program called count_alpha that takes a string and displays the number
of occurences of its alphabetical characters. Other characters are not counted.
The order is the order of occurence in the string. The display must be ended by
a newline.

The format is in the examples.

If the number of arguments is not 1, display only a newline.

Examples :
$> ./count_alpha abbcc
1a, 2b, 2c
$> ./count_alpha "abbcc"
1a, 2b, 2c
$> ./count_alpha "abbcc" "dddeef" | cat -e
$
$> ./count_alpha "My Hyze 47y 7." | cat -e
1m, 3y, 1h, 1z, 1e$
$> ./count_alpha "" | cat -e
$

*/
