#include <stdio.h>
#include <string.h>
#include "./ex00/ft_strcpy.c"
#include "./ex01/ft_strncpy.c"
#include "./ex02/ft_str_is_alpha.c"
#include "./ex03/ft_str_is_numeric.c"
#include "./ex04/ft_str_is_lowercase.c"
#include "./ex05/ft_str_is_uppercase.c"
#include "./ex06/ft_str_is_printable.c"
#include "./ex07/ft_strupcase.c"
#include "./ex08/ft_strlowcase.c"
#include "./ex09/ft_strcapitalize.c"
#include "./ex10/ft_strlcpy.c"
#include "./ex11/ft_putstr_non_printable.c"

int main()
{
    //ex00
    printf("ex00\n");
    char ex00_src[] = "hello world!";
	char ex00_dest[20];
    printf("src : %s\n", ex00_src);
	ft_strcpy(ex00_dest, ex00_src);
	printf("ft_strcpy : %s\n\n", ex00_dest);
	// printf ("%d\n", ex00_dest[12]);

    // //ex01
    printf("ex01\n");
    char ex01_src[] = "Hello world!";
	char ex01_dest[20]= "asdfasdfasdfasdf";
	printf("src : %s\nn = 14\n", ex01_src);
	ft_strncpy(ex01_dest, ex01_src, 14);
    printf("%c\n", ex01_dest[15]);
    printf("%d\n", ex01_dest[13]);
	printf("ft_strncpy : %s.\n\n", ex01_dest);

    // //ex02
    printf("ex02\n");
    char ex02_arr1[] = "asdg";
	char ex02_arr2[] = " a663dtsljljk at;kzcgk";
	char ex02_arr3[] = "51235 sdtlna ;kl";
	char ex02_arr4[] = "";
	printf("arr1 : %s\n%d\n", ex02_arr1, ft_str_is_alpha(ex02_arr1));
    printf("arr2 : %s\n%d\n", ex02_arr2, ft_str_is_alpha(ex02_arr2));
    printf("arr3 : %s\n%d\n", ex02_arr3, ft_str_is_alpha(ex02_arr3));
    printf("arr4 : %s\n%d\n\n", ex02_arr4, ft_str_is_alpha(ex02_arr4));

    // // //ex03
    printf("ex03\n");
    char ex03_arr1[] = "asdg";
	char ex03_arr2[] = " a663dtsljljk at;kzcgk";
	char ex03_arr3[] = "12125136";
	char ex03_arr4[] = "";
    printf("arr1 : %s\n%d\n", ex03_arr1, ft_str_is_numeric(ex03_arr1));
    printf("arr2 : %s\n%d\n", ex03_arr2, ft_str_is_numeric(ex03_arr2));
    printf("arr3 : %s\n%d\n", ex03_arr3, ft_str_is_numeric(ex03_arr3));
    printf("arr4 : %s\n%d\n\n", ex03_arr4, ft_str_is_numeric(ex03_arr4));

    // //ex04
    printf("ex04\n");
    char ex04_arr1[] = "asdg";
	char ex04_arr2[] = "atsljljkSDTNL";
	char ex04_arr3[] = "51235 sdtlna ;kl";
	char ex04_arr4[] = "";
    printf("arr1 : %s\n%d\n", ex04_arr1, ft_str_is_lowercase(ex04_arr1));
    printf("arr2 : %s\n%d\n", ex04_arr2, ft_str_is_lowercase(ex04_arr2));
    printf("arr3 : %s\n%d\n", ex04_arr3, ft_str_is_lowercase(ex04_arr3));
    printf("arr4 : %s\n%d\n\n", ex04_arr4, ft_str_is_lowercase(ex04_arr4));

    // //ex05
    printf("ex05\n");
    char ex05_arr1[] = "asdg";
	char ex05_arr2[] = "ASNLTLKAT";
	char ex05_arr3[] = "51235 ASTNKSKLsdtlna ;kl";
	char ex05_arr4[] = "";
    printf("arr1 : %s\n%d\n", ex05_arr1, ft_str_is_uppercase(ex05_arr1));
    printf("arr2 : %s\n%d\n", ex05_arr2, ft_str_is_uppercase(ex05_arr2));
    printf("arr3 : %s\n%d\n", ex05_arr3, ft_str_is_uppercase(ex05_arr3));
    printf("arr4 : %s\n%d\n\n", ex05_arr4, ft_str_is_uppercase(ex05_arr4));

    // //ex06
    printf("ex06\n");
    char ex06_arr1[] = "asdg";
	char ex06_arr2[] = "ASNLTLKAT";
	char ex06_arr3[] = "한국";
	char ex06_arr4[] = "";
    printf("arr1 : %s\n%d\n", ex06_arr1, ft_str_is_printable(ex06_arr1));
    printf("arr2 : %s\n%d\n", ex06_arr2, ft_str_is_printable(ex06_arr2));
    printf("arr3 : %s\n%d\n", ex06_arr3, ft_str_is_printable(ex06_arr3));
    printf("arr4 : %s\n%d\n\n", ex06_arr4, ft_str_is_printable(ex06_arr4));

    // //ex07
    printf("ex07\n");
    char ex07_str[] = "Hello I'm hunpark!!";
    printf("before str : %s\n", ex07_str);
	printf("after str : %s\n\n", ft_strupcase(ex07_str));

    // //ex08
    printf("ex08\n");
    char ex08_str[] = "Hello I'm hunpark!!";
    printf("before str : %s\n", ex08_str);
	printf("after str : %s\n\n", ft_strlowcase(ex08_str));

    // //ex09
    printf("ex09\n");
    char ex09_str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    printf("before str : %s\n", ex09_str);
	printf("after str : %s\n\n", ft_strcapitalize(ex09_str));

    // //ex10
    printf("ex10\n");
    char ex10_src[] = "hello my name is hunpark!";
	char ex10_dest[50];
    printf("src : %s, size = 5\n", ex10_src);
	printf("ft_strlcpy : %d\n", ft_strlcpy(ex10_dest, ex10_src, 5));
	printf("dest : %s\n\n", ex10_dest);

    //ex11
    printf("ex11\n");
    char ex11_str[] = "Coucou\ntu vas bien ?";
    printf("str : %s\n", ex11_str);
	ft_putstr_non_printable(ex11_str);
    printf("\n");
}
