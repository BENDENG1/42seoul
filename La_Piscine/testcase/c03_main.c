#include <stdio.h>
#include <string.h>
#include "./ex00/ft_strcmp.c"
#include "./ex01/ft_strncmp.c"
#include "./ex02/ft_strcat.c"
#include "./ex03/ft_strncat.c"
#include "./ex04/ft_strstr.c"
#include "./ex05/ft_strlcat.c"

int	main()
{
	//ex00
	printf("ex00\n");
	char ex00_s1[] = "hello world!";
	char ex00_s2[] = "hello warld!";
	printf("s1 : %s\ns2 : %s\n", ex00_s1, ex00_s2);
	printf("strcmp : %d\nft_strcmp : %d\n\n\n", strcmp(ex00_s1,ex00_s2), ft_strcmp(ex00_s1, ex00_s2));

	//ex01
	printf("ex01\n");
	printf("s1 : %s\ns2 : %s\n", ex00_s1, ex00_s2);
	printf("strncmp, n=5 : %d\nstrncmp, n=8 : %d\n", strncmp(ex00_s1,ex00_s2, 5), strncmp(ex00_s1, ex00_s2, 8));
	printf("ft_strncmp, n=5 : %d\nft_strncmp, n=8 : %d\n\n\n", ft_strncmp(ex00_s1,ex00_s2, 5), ft_strncmp(ex00_s1, ex00_s2, 8));
	//ex02
	printf("ex02\n");
	char ex02_dest1[50] = "Hi my name is ";
	char ex02_src1[50] = "Hunpark!!";
	char ex02_dest2[50] = "Hi my name is ";
	char ex02_src2[50] = "Hunpark!!";
	printf("dest : %s\nsrc : %s\n", ex02_dest1, ex02_src1);
	printf("strcat : %s\nft_strcat : %s\n\n\n", strcat(ex02_dest1, ex02_src1), ft_strcat(ex02_dest2, ex02_src2));

	//ex03
	printf("ex03\n");
	char ex03_dest1[50] = "Hi my name is ";
	char ex03_src1[50] = "Hunpark!!";
	char ex03_dest2[50] = "Hi my name is ";
	char ex03_src2[50] = "Hunpark!!";
	char ex03_dest3[50] = "Hi my name is ";
	char ex03_src3[50] = "Hunpark!!";
	char ex03_dest4[50] = "Hi my name is ";
	char ex03_src4[50] = "Hunpark!!";
	printf("dest : %s\nsrc : %s\n", ex03_dest1, ex03_src1);
	printf("strncat, n=5 : %s\nstrncat, n=8 : %s\n", strncat(ex03_dest1,ex03_src1, 5), strncat(ex03_dest2, ex03_src2, 8));
	printf("ft_strncat, n=5 : %s\nft_strncat, n=8 : %s\n\n\n", ft_strncat(ex03_dest3,ex03_src3, 5), ft_strncat(ex03_dest4, ex03_src4, 8));

	//ex04
	printf("ex04\n");
	char str[] = "hello world!";

	printf("str : %s\nto_find : ll\nstrstr : %s\n\n", str, strstr(str, "ll"));
	printf("str : %s\nto_find : la\nstrstr : %s\n\n", str, strstr(str, "la"));
	printf("str : %s\nto_find : ll\nft_strstr : %s\n\n", str, ft_strstr(str, "ll"));
	printf("str : %s\nto_find : la\nft_strstr : %s\n\n\n", str, ft_strstr(str, "la"));

	//ex05
	printf("ex05\n");
	char	ex05_dest1[50] = "hello my name";
	char	ex05_src1[50] = " is hunpark!";
	char	ex05_dest2[50] = "hello my name";
	char	ex05_src2[50] = " is hunpark!";
	char	ex05_dest3[50] = "hello my name";
	char	ex05_src3[50] = " is hunpark!";
	char	ex05_dest4[50] = "hello my name";
	char	ex05_src4[50] = " is hunpark!";

	printf("strlcat, n=5 : %lu\nstrlcat, n=15 : %lu\n", strlcat(ex05_dest1, ex05_src1, 5), strlcat(ex05_dest2, ex05_src2, 15));
	printf("ft_strlcat, n=5 : %d\nft_strlcat, n=15 : %d\n\n", ft_strlcat(ex05_dest3, ex05_src3, 5), ft_strlcat(ex05_dest4, ex05_src4, 15));
}

