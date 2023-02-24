#include <stdio.h>
#include "./ex00/ft.h"
#include "./ex01/ft_boolean.h"
#include "./ex02/ft_abs.h"
#include "./ex03/ft_point.h"
#include "./ex04/ft_strs_to_tab.c"
#include "./ex05/ft_show_tab.c"

void	ft_putstr1(char *str)
{
	while (*str)
		write(1, str++, 1);
}

t_bool ft_is_even(int nbr)
{
	return ((EVEN(nbr)) ? TRUE : FALSE);
}

void set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int	main(int ac, char** av)
{
	//ex01
	printf("-------ex01-------\n\n");
	(void)av;
	if (ft_is_even(ac - 1) == TRUE)
		ft_putstr1(EVEN_MSG);
	else
		ft_putstr1(ODD_MSG);
	printf("\n");

	//ex02
	printf("-------ex02-------\n\n");
	int a = -42;
	int b = 64;
	printf("a = %d\nabs(a) = %d\n\n", a, ABS(a));
	printf("b = %d\nabs(b) = %d\n", b, ABS(b));
	printf("\n");

	//ex03
	printf("-------ex03-------\n\n");
	t_point	point;
	set_point(&point);
	printf("x = %d, y = %d\n\n", point.x, point.y);

	//ex04, ex05
	printf("----ex04, ex05----\n");
	struct s_stock_str *str;
	str = ft_strs_to_tab(ac, av);
	ft_show_tab(str);
	free(str);
	return (SUCCESS);
}
