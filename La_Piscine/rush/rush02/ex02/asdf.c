#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void	write_num(char *c)
{
	int	j;

	j = 0;
	while (c[j])
		write(1, &c[j++], 1);
}

void one_nine(char c, char hashmap[][2][50], int _ten_to_nineteen);
void	fill_char(char *c, int size);
void	make_map(char *buf, char hashmap[][2][50])
{
	int	i;
	int x;
	int z;
	int is_word;

	x = 0;
	i = 0;
	z = 0;
	is_word = 0;
	while (buf[i])
	{
		if (buf[i] == ':')
		{
			hashmap[x][is_word][z] = '\0';
			is_word = 1;
			z = 0;
		}
		else if (buf[i] == '\n')
		{
			hashmap[x][is_word][z] = '\0';
			is_word = 0;
			z = 0;
			x++;
		}
		else if ((buf[i] >= '0' && buf[i] <= '9') || (buf[i] >= 'a' && buf[i] <= 'z'))
		{
			hashmap[x][is_word][z++] = buf[i];
		}
		i++;
	}
}

void hundred(char c, char hashmap[][2][50])
{
	int	a;

	if (c == '0')
		return ;
	a = c - 48;

	write_num(hashmap[a][1]);
	write(1, " ", 1);
	write_num(hashmap[28][1]);
	write(1, " ", 1);
}

void twen_ninety(char _1th, char _2th, char hashmap[][2][50])
{
	int a;
	int _ten_to_nineteen = 0;
	if (_1th >= '2')
	{
		a = _1th - 48 + 20 - 2;
		write_num(hashmap[a][1]);
		write(1, " ", 1);
	}
	else if (_1th == '1')
	{
		_ten_to_nineteen = 1;
	}
	else if (_1th == '2')
		_ten_to_nineteen = 1;
	one_nine(_2th, hashmap, _ten_to_nineteen);
}

void one_nine(char c, char hashmap[][2][50], int _ten_to_nineteen)
{
	int	a;

	if (!_ten_to_nineteen)
	{
		if (c >= '1')
		{
			a = c - 48;
			write_num(hashmap[a][1]);
		}
	}
	else if (_ten_to_nineteen == 2)
	{
		a = c - 48;
		write_num(hashmap[a][1]);
	}
	else
	{
		a = c - 48 + 10;
		write_num(hashmap[a][1]);
	}
	write(1, " ", 1);
}

void f_digit(char *c, int *size, int *digit)
{
	int c_size;

	c_size = 0;
	while (c[c_size] >= '0' && c[c_size] <= '9')
	{
		c_size++;
	}
	*size = c_size;
	*digit = (*size) / 3;
	char d;
	d = *digit + 48;;
}

void	write_number(char hashmap[][2][50], char *c)
{
	int	j;
	int digit;
	int size;

	f_digit(c, &size, &digit);
	j = 0;
	while (digit > 1)
	{
		hundred(c[j], hashmap);
		twen_ninety(c[j + 1], c[j + 2], hashmap);
		if (c[j] != '0' || c[j + 1] != '0' || c[j + 2] != '0')
			write_num(hashmap[27 + digit][1]);
		write(1, " ", 1);
		j = j + 3;
		digit--;
	}
	if (digit == 1)
	{
		hundred(c[j], hashmap);
		twen_ninety(c[j + 1], c[j + 2], hashmap);
	}
}

void	s_map(char hashmap[42][2][50])
{
	int	i;
	int	j;

	i = 0;
	while (i < 41)
	{
		j = 0;
		while (hashmap[i][0][j])
		{
			write(1, &hashmap[i][0][j++], 1);
		}
		// write(1, "  ", 2);
		j = 0;
		while (hashmap[i][1][j])
		{
			write(1, &hashmap[i][1][j++], 1);
		}
		write(1, "\n", 1);
		i++;
	}
}
char	*stringcheck(char *c)
{
	char 	*temp_str;
	int		minus;
	int		i;
	int		size;

	temp_str = (char *)malloc(sizeof(char)* 4000);
	size = 0;
	i = 0;
	minus = 0;
	while (c[i])
	{
		if (c[i] == '-')
			minus++;
		/*
		else if (c[i] == ' ')
		{
			while(c[i + 1] == ' ')
				i++;
			temp_str[size] = c[i];
			size++;
		}
		*/
		else if (c[i] >= '0' && c[i] <= '9')
		{
			temp_str[size] = c[i];
			size ++;
		}
		i++;
	}
	if (size % 3 != 0)
		fill_char(temp_str, size);
	return temp_str;
}

void	fill_char(char *c, int size)
{
	if (size % 3 == 1)
	{
		c[size + 3] = '\0';
		while (size > 0)
		{
			c[size + 1] = c[size - 1];
			size--;
		}
		c[0] = '0';
		c[1] = '0';
	}
	if (size % 3 == 2)
	{
		c[size + 2] = '\0';
		while (size > 0)
		{
			c[size] = c[size - 1];
			size--;
		}
		c[0] = '0';
	}
}

int main(int argc, char **argv)
{
	char	buf[1000];
	char	map[42][2][50];
	int		fd;
	char	*array;

	argc = 0;
	if((fd = open("numbers.dict", O_RDWR)) == -1)
		return (0);
	read(fd, buf, 1000);
	make_map(buf, map);
	array = stringcheck(argv[1]);
	write_number(map, array);
	close(fd);
	return (0);
}
