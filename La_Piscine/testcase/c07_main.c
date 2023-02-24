#include <stdio.h>
// #include "./ex00/ft_strdup.c"
// #include "./ex01/ft_range.c"
// #include "./ex02/ft_ultimate_range.c"
// #include "./ex03/ft_strjoin.c"
#include "./ex04/ft_convert_base.c"
#include "./ex04/ft_convert_base2.c"
#include "./ex05/ft_split.c"


int main()
{
    // //ex00
    // printf("-------ex00-------\n\n");
    // char ex00_src[] = "hello my name is hunpark!";

    // printf("src : %s\n", ex00_src);
    // printf("strdup : %s\n\n", ft_strdup(ex00_src));
    // free(ft_strdup(ex00_src));

    // //ex01
    // printf("-------ex01-------\n\n");
    // int *ex01_arr1;
    // int *ex01_arr2;
    // int *ex01_arr3;

    // printf("min : 1, max : 10\n");
    // ex01_arr1 = ft_range(1, 10);
    // for(int i = 0; i < 9; i++)
    // {
    //     printf("%d ", ex01_arr1[i]);
    // }
    // printf("\n\n");
    // printf("min : 10, max : 1\n");
    // ex01_arr2 = ft_range(1, 0);
    // printf("%p ", ex01_arr2);
    // printf("\n\n");
    // printf("min : -25, max : -10\n");
    // ex01_arr3 = ft_range(-25, -10);
    // for(int i = 0; i < 15; i++)
    // {
    //     printf("%d ", ex01_arr3[i]);
    // }
    // printf("\n\n");
    // free(ex01_arr1);
    // free(ex01_arr2);
    // free(ex01_arr3);

    // printf("-------ex02-------\n\n");
    // int	*ex02_arr1;
    // int	*ex02_arr2;
    // int	*ex02_arr3;
	// int size1 = ft_ultimate_range(&ex02_arr1, 5, 10);
    // int size2 = ft_ultimate_range(&ex02_arr2, -4, 10);
    // int size3 = ft_ultimate_range(&ex02_arr3, 10, 1);

    // printf("min : 5, max : 10, size : %d\n", size1);
	// for (int i = 0; i < size1 ; i++)
	// {
	// 	printf("%d ", ex02_arr1[i]);
	// }
    // printf("\n\n");
    // printf("min : -4, max : 10, size : %d\n", size2);
	// for (int i = 0; i < size2 ; i++)
	// {
	// 	printf("%d ", ex02_arr2[i]);
	// }
    // printf("\n\n");
    // printf("min : 10, max : 1, size : %d\n", size3);
	// printf("%p ", ex02_arr3);
    // printf("\n\n");
    // free(ex02_arr1);
    // free(ex02_arr2);
    // free(ex02_arr3);

    // printf("-------ex03-------\n\n");
    // char *ex03_arr1;
    // char *ex03_arr2;
    // char *ex03_arr3;
	// char *ex03_str[5];

	// ex03_str[0] = "hello";
	// ex03_str[1] = "my";
	// ex03_str[2] = "name";
	// ex03_str[3] = "is";
	// ex03_str[4] = "hunpark!";
	// ex03_arr1 = ft_strjoin(5, ex03_str, " ");
    // ex03_arr2 = ft_strjoin(5, ex03_str, ".");
    // ex03_arr3 = ft_strjoin(5, ex03_str, "-");
	// printf("%s\n", ex03_arr1);
    // printf("%s\n", ex03_arr2);
    // printf("%s\n\n", ex03_arr3);
    // free(ex03_arr1);
    // free(ex03_arr2);
    // free(ex03_arr3);

    // printf("-------ex04-------\n\n");
	// char *str;
	// str = ft_convert_base("15858", "012345678", "0123456789ABCDEF");
	// printf("2A9B : %s\n", str);
	// free(str);
	// str = ft_convert_base("  \t \n -+-+-28909abc", "0123456789abcdef", "0123456789ABCDEFGHIJ");
	// printf("-ACDADBG : %s\n", str);
	// free(str);
	// str = ft_convert_base(" --zzixzoz", "ozix", "POIUYTREWQ");
	// printf("TWYO : %s\n", str);
	// free(str);
	// char base[6] = {-19, 66, -1, -8, -20, 0};
	// str = ft_convert_base("++858a112", "845a", base);
	// printf("B?? : %s\n", str);
	// free(str);
	// str = ft_convert_base("15858", "01234aa5678", "012345679ABCDEF");
	// printf("null : %s\n", str);
	// free(str);
	// str = ft_convert_base("15858", "01278", "0");
	// printf("null : %s\n", str);
	// free(str);
	// str = ft_convert_base("15858", "01-278", "019ABCDEF");
	// printf("null : %s\n\n", str);
	// free(str);

    printf("-------ex05-------\n\n");
    char **ex05_split1;
    char **ex05_split2;
    char **ex05_split3;
	char *ex05_str1 = "hello my name is hunpark!";
	char *ex05_str2 = "good@day!cat#dog!vim12!";
	char *ex05_str3 = "i1my2me3mine4you5your6you7yours";



	ex05_split1 = ft_split(ex05_str1, " ");
    ex05_split2 = ft_split(ex05_str2, "@!#");
    ex05_split3 = ft_split(ex05_str3, "1234567");
    printf("---test1---\n");
	for (int j = 0; j < 5; j++)
	{
		printf("%s\n", ex05_split1[j]);
	}
    printf("\n\n");
    printf("---test2---\n");
    for (int j = 0; j < 5; j++)
	{
		printf("%s\n", ex05_split2[j]);
	}
    printf("\n\n");
    printf("---test3---\n");
    for (int j = 0; j < 8; j++)
	{
		printf("%s\n", ex05_split3[j]);
	}
    printf("\n\n");
	free(ex05_split1);
    free(ex05_split3);
    free(ex05_split2);



}
