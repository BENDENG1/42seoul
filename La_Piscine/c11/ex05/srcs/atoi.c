/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:59:48 by gyroh             #+#    #+#             */
/*   Updated: 2022/05/04 19:45:07 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	sum(int a, int b);
int	minus(int a, int b);
int	mul(int a, int b);
int	div(int a, int b);
int	mod(int a, int b);

int	ft_atoi(char *str)
{
	int	i;
	int	pm;
	int	ans;

	ans = 0;
	i = 0;
	pm = 1;
	if (str[i] != '\0')
	{
		while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
			i++;
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				pm *= -1;
			i++;
		}
		while ('0' <= str[i] && str[i] <= '9')
		{
			ans *= 10;
			ans += (str[i] - '0');
			i++;
		}
	}
	return (ans * pm);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		c = '0' + nb;
		write(1, &c, 1);
	}
}

int	get_operator(char c)
{
	if (c == '+')
		return (0);
	else if (c == '-')
		return (1);
	else if (c == '*')
		return (2);
	else if (c == '/')
		return (3);
	else if (c == '%')
		return (4);
	else
		return (5);
}

int	ft_operator(int a, char oper, int b)
{
	int	((*f[5]))(int a, int b);
	int	op;

	f[0] = sum;
	f[1] = minus;
	f[2] = mul;
	f[3] = div;
	f[4] = mod;
	op = get_operator(oper);
	if (op == 5)
		return (0);
	return ((*f[op])(a, b));
}

int	main(int ac, char **av)
{
	int		num1;
	int		num2;
	int		ans;

	if (ac != 4)
		return (0);
	num1 = ft_atoi(av[1]);
	num2 = ft_atoi(av[3]);
	if (num2 == 0 && av[2][0] == '%')
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	else if (num2 == 0 && av[2][0] == '/')
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	ans = ft_operator(num1, av[2][0], num2);
	ft_putnbr(ans);
	write(1, "\n", 1);
	return (0);
}
