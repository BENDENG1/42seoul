#include <stdio.h>

#include "./ex00/ft_ft.c"
#include "./ex01/ft_ultimate_ft.c"
#include "./ex02/ft_swap.c"
#include "./ex03/ft_div_mod.c"
#include "./ex04/ft_ultimate_div_mod.c"
#include "./ex05/ft_putstr.c"
#include "./ex06/ft_strlen.c"
#include "./ex07/ft_rev_int_tab.c"
#include "./ex08/ft_sort_int_tab.c"

int main()
{
	//ex00
	int ex00_num;
	ex00_num = 0;
	printf("ex00\n");
	ft_ft(&ex00_num);
	printf("%d\n\n", ex00_num);

	//ex01
	printf("ex01\n");
	int n = 0;
	int *n1 = &n;
	int **n2 = &n1;
	int ***n3 = &n2;
	int ****n4 = &n3;
	int *****n5 = &n4;
	int ******n6 = &n5;
	int *******n7 = &n6;
	int ********n8 = &n7;
	int *********n9 = &n8;
	ft_ultimate_ft(n9);
	printf("%d\n\n", n);

	//ex02
	printf("ex02\n");
	int ex02_num1 = 10, ex02_num2 = 20;
	printf("before swap\nnum1 = %d, num2 = %d\n", ex02_num1, ex02_num2);
	ft_swap(&ex02_num1, &ex02_num2);
	printf("after swap\na = %d, b= %d\n\n", ex02_num1, ex02_num2);

	//ex03
	printf("ex03\n");
	int ex03_num1 = 20, ex03_num2 = 3;
	int div, mod;
	printf("num1 = %d, num2 = %d\n", ex03_num1, ex03_num2);
	ft_div_mod(ex03_num1, ex03_num2, &div, &mod);
	printf("div(num1, num2) = %d\nmod(num1, num2) = %d\n\n", div, mod);

	//ex04
	printf("ex04\n");
	int ex04_num1 = 30, ex04_num2 = 4;
	printf("num1 = %d, num2 = %d\n", ex04_num1, ex04_num2);
	ft_ultimate_div_mod(&ex04_num1, &ex04_num2);
	printf("div = %d\nmod = %d\n\n", ex04_num1, ex04_num2);

	//ex05
	printf("ex05\n");
	char ex05_arr[] = "Hello 42!";
	ft_putstr(ex05_arr);
	printf("\n\n");

	//ex06
	printf("ex06\n");
	printf("str : %s\n", ex05_arr);
	printf("strlen : %d\n\n", ft_strlen(ex05_arr));

	//ex07
	printf("ex07\n");
	int ex07_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int ex07_i;


	printf ("before rev = ");
	for (ex07_i = 0; ex07_i<9 ; ex07_i++){
	printf("%d", ex07_arr[ex07_i]);
	}
	printf("\n");
	printf("after rev = ");
	ft_rev_int_tab(ex07_arr, 9);
	for (ex07_i=0; ex07_i<9;  ex07_i++){
		printf("%d", ex07_arr[ex07_i]);
	}
	printf("\n\n");


	//ex08
	int ex08_arr[] = {1, 15, 75, 99, 195, 2, 5, 33, 18, 30, 39};
	int ex08_i;

	printf("ex08\n");
	printf("before sort : ");
	for(ex08_i = 0; ex08_i < 11; ex08_i++)
	{
		printf("%d", ex08_arr[ex08_i]);
		if (ex08_i == 10)
			break ;
		printf(", ");
	}
	printf("\n");
	printf("after sort : ");
	ft_sort_int_tab(ex08_arr, 11);
	for(ex08_i = 0; ex08_i < 11; ex08_i++)
	{
		printf("%d", ex08_arr[ex08_i]);
		if (ex08_i == 10)
			break ;
		printf(", ");
	}
	printf("\n");
}
