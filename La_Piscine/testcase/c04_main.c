#include <stdio.h>
#include <stdlib.h>
// #include "./ex00/ft_strlen.c"
#include "./ex01/ft_putstr.c"
#include "./ex02/ft_putnbr.c"
#include "./ex03/ft_atoi.c"
#include "./ex04/ft_putnbr_base.c"
#include "./ex05/ft_atoi_base.c"

int main()
{
	// //ex00
	// printf("------ ex00 ------\n");
	// char ex00_str1[] = "123456789"; //9
	// char ex00_str2[] = "asdgsah"; // 7
	// char ex00_str3[] = "abcd;25ni`209n62kl"; // 18
	// printf("str1 : %s\n%d\n", ex00_str1, ft_strlen(ex00_str1));
	// printf("str2 : %s\n%d\n", ex00_str2, ft_strlen(ex00_str2));
	// printf("str3 : %s\n%d\n\n", ex00_str3, ft_strlen(ex00_str3));

	//ex01
	printf("------ ex01 ------\n");
	char ex01_str1[] = "Hello my name is Hunpark!";
	char ex01_str2[] = "I love 42";
	char ex01_str3[] = "babambar";
	ft_putstr(ex01_str1);
	printf("\n");
	ft_putstr(ex01_str2);
	printf("\n");
	ft_putstr(ex01_str3);
	printf("\n\n");

	//ex02
	printf("------ ex02 ------\n");
	ft_putnbr(42);
	printf("\n");

	ft_putnbr(-2147483648);
	printf("\n");

	ft_putnbr(2147483647);
	printf("\n");

	ft_putnbr(0);
	printf("\n");

	ft_putnbr(-24252);
	printf("\n\n");

	//ex03
	printf("------ ex03 ------\n");
	char ex03_str1[] ="\t   ----++000846545ags56";
	char ex03_str2[] = "  	 \t	-+--1165ataat++-156";
	char ex03_str3[] = "214564564512313546";

	printf("str1 : %s\nft_atoi(str1) = %d\n\n", ex03_str1, ft_atoi(ex03_str1));
	printf("str2 : %s\nft_atoi(str2) = %d\n\n", ex03_str2, ft_atoi(ex03_str2));
	printf("str3 : %s\nft_atoi(str3) = %d\n\n", ex03_str3, ft_atoi(ex03_str3));
	printf("str3 : %s\natoi(str3) = %d\n\n", ex03_str3, atoi(ex03_str3));

	//ex04
	printf("------ ex04 ------\n");
	printf("-bmLbpjci\n");
	ft_putnbr_base(-2147483648, "abcdEFGhijkLNmopqrST");
	printf("\n\n");

	printf("*///////\n");
	ft_putnbr_base(2147483647, "!@#$%^&*()<>,.?/");
	printf("\n\n");

	printf("-)()()(\n");
	ft_putnbr_base(-42, "()");
	printf("\n\n");

	printf("[SHOULD NOT PRINT]\n");
	ft_putnbr_base(133316, "");
	printf("\n\n");

	printf("[SHOULD NOT PRINT]\n");
	ft_putnbr_base(15361, "aabc!");
	printf("\n\n");

	printf("59483\n");
	ft_putnbr_base(59483, "0123456789");
	printf("\n\n");

	//ex05
	printf("------ ex05 ------\n\n");
	char ex05_str1[] = " \n -+-++-+2147483648";
	char ex05_str2[] = "   ---+AABCDESSEZ";
	char ex05_str3[] = "   ++136667";
	char ex05_str4[] = "   -----+-+!!@@#..<";
	char ex05_str5[] = "  \n \tatoi12-+123base";

	printf("-2147483648\n");
	printf("%d\n\n", ft_atoi_base(ex05_str1, "0123456789"));

	printf("0\n");
	printf("%d\n\n", ft_atoi_base(ex05_str1, ""));

	printf("-67174\n");
	printf("%d\n\n", ft_atoi_base(ex05_str2, "ABCDES"));

	printf("-1\n");
	printf("%d\n\n", ft_atoi_base(ex05_str2, "ABZ"));

	printf("0\n");
	printf("%d\n\n", ft_atoi_base(ex05_str3, "A-+"));

	printf("12347\n");
	printf("%d\n\n", ft_atoi_base(ex05_str3, "3405816"));

	printf("1126397\n");
	printf("%d\n\n", ft_atoi_base(ex05_str4, "!@#$%^&*()~?><'."));

	printf("27\n");
	printf("%d\n\n", ft_atoi_base(ex05_str5, "atoi"));
}



