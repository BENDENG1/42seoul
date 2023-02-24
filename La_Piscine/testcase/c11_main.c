#include <stdio.h>
#include "./ex00/ft_foreach.c"
#include "./ex01/ft_map.c"
#include "./ex02/ft_any.c"
#include "./ex03/ft_count_if.c"
#include "./ex04/ft_is_sort.c"
#include "./ex06/ft_sort_string_tab.c"
#include "./ex07/ft_advanced_sort_string_tab.c"

void	ft_print_num(int a)
{
	printf("%d ", a);

}

int	ft_arr_change(int a)
{
	return (a * 2);
}

int	ft_check_alpha(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			return (0);
		if (str[i] >= 97 && str[i] <= 122)
			return (0);
		i++;
	}
	return (1);
}

int ft_cmp(int a, int b)
{
	return (a - b);
}

int ft_strcmp11(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i])
	{
		if (*s1 != *s2)
			break;
		i++;
	}
	return (s2[i] - s1[i]);
}

int main()
{
	//ex00
	printf("-------ex00-------\n\n");
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printf("arr : ");
	for(int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	printf("foreach : ");
	ft_foreach(arr, 10, &ft_print_num);
	printf("\n\n");

	//ex01
	printf("-------ex01-------\n\n");
	int *arr_ex01;
	printf("arr : ");
	for(int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	printf("map : ");
	arr_ex01 = ft_map(arr, 10, &ft_arr_change);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr_ex01[i]);
	}
	printf("\n\n");

	//ex02
	printf("-------ex02-------\n\n");
	char *ex02_arr[5];
	ex02_arr[0] = "helloworld";
	ex02_arr[1] = "abc";
	ex02_arr[2] = "hunpark";
	ex02_arr[3] = "seoul";
	ex02_arr[4] = 0;
	printf("0 : %d\n", ft_any(ex02_arr, &ft_check_alpha));
	ex02_arr[2] = "0123456";
	printf("1 : %d\n\n", ft_any(ex02_arr, &ft_check_alpha));

	//ex03
	printf("-------ex03-------\n\n");
	printf("1 : %d\n\n", ft_count_if(ex02_arr, 4, &ft_check_alpha));

	//ex04
	printf("-------ex04-------\n\n");
	int ex04_arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int ex04_arr2[10] = {5, 2, 3, 1, 5, 6, 3, 8, 2, 10};
	int ex04_arr3[10] = {100, 54, 43, 33, 29, 20, 10, 8, 1, 0};

	printf("1 : %d\n", ft_is_sort(ex04_arr1, 10, &ft_cmp));
	printf("0 : %d\n", ft_is_sort(ex04_arr2, 10, &ft_cmp));
	printf("1 : %d\n\n", ft_is_sort(ex04_arr3, 10, &ft_cmp));

	printf("-------ex06-------\n");
	char *ex06_strs[6];
	ex06_strs[0] = "asdf";
	ex06_strs[1] = "asbf";
	ex06_strs[2] = "aaa";
	ex06_strs[3] = "asdfasdf";
	ex06_strs[4] = "aaaaab";
	ex06_strs[5] = 0;
	printf("\nBefore sort\n\n");
	for(int i=0;i<6;i++)
		printf("%s\n",ex06_strs[i]);
	ft_sort_string_tab(ex06_strs);
	printf("\nAfter sort\n\n");
	for(int i=0;i<6;i++)
		printf("%s\n",ex06_strs[i]);

	printf("-------ex07-------\n");
	char *ex07_strs[6];
	ex07_strs[0] = "asdf";
	ex07_strs[1] = "asbf";
	ex07_strs[2] = "aaa";
	ex07_strs[3] = "asdfasdf";
	ex07_strs[4] = "aaaaab";
	ex07_strs[5] = 0;
	printf("\nBefore sort\n\n");
	for(int i=0;i<6;i++)
		printf("%s\n",ex07_strs[i]);
	ft_advanced_sort_string_tab(ex07_strs, &ft_strcmp11);
	printf("\nAfter sort\n\n");
	for(int i=0;i<6;i++)
		printf("%s\n",ex07_strs[i]);
}


