#include <stdio.h>
#include "./ex00/ft_iterative_factorial.c"
#include "./ex01/ft_recursive_factorial.c"
#include "./ex02/ft_iterative_power.c"
#include "./ex03/ft_recursive_power.c"
#include "./ex04/ft_fibonacci.c"
#include "./ex05/ft_sqrt.c"
#include "./ex06/ft_is_prime.c"
#include "./ex07/ft_find_next_prime.c"
#include "./ex08/ft_ten_queens_puzzle.c"

int main()
{
	//ex00
	printf("-------ex00-------\n");
	printf("nb = 0\n%d\n\n", ft_iterative_factorial(0));
	printf("nb = -1\n%d\n\n", ft_iterative_factorial(-1));
	printf("nb = 5\n%d\n\n", ft_iterative_factorial(5));
	printf("nb = 10\n%d\n\n", ft_iterative_factorial(10));
	printf("nb = 20 (overflow)\n%d\n\n", ft_iterative_factorial(20));

	// //ex01
	printf("-------ex01-------\n");
	printf("nb = 0\n%d\n\n", ft_recursive_factorial(0));
	printf("nb = -1\n%d\n\n", ft_recursive_factorial(-1));
	printf("nb = 5\n%d\n\n", ft_recursive_factorial(5));
	printf("nb = 10\n%d\n\n", ft_recursive_factorial(10));
	printf("nb = 20 (overflow)\n%d\n\n", ft_recursive_factorial(20));

	//ex02
	printf("-------ex02-------\n");
	printf("nb = 0, power = 0\n%d\n\n", ft_iterative_power(0, 0));
	printf("nb = 0, power = 3\n%d\n\n", ft_iterative_power(0, 3));
	printf("nb = 10, power = 0\n%d\n\n", ft_iterative_power(10, 0));
	printf("nb = 10, power = 3\n%d\n\n", ft_iterative_power(10, 3));
	printf("nb = 50, power = -3\n%d\n\n", ft_iterative_power(50, -3));
	printf("nb = -10, power = 5\n%d\n\n", ft_iterative_power(-10, 5));

	// //ex03
	printf("-------ex03-------\n");
	printf("nb = 0, power = 0\n%d\n\n", ft_recursive_power(0, 0));
	printf("nb = 0, power = 3\n%d\n\n", ft_recursive_power(0, 3));
	printf("nb = 10, power = 0\n%d\n\n", ft_recursive_power(10, 0));
	printf("nb = 10, power = 3\n%d\n\n", ft_recursive_power(10, 3));
	printf("nb = 50, power = -3\n%d\n\n", ft_recursive_power(50, -3));
	printf("nb = -10, power = 5\n%d\n\n", ft_recursive_power(-10, 5));

	// //ex04
	printf("-------ex04-------\n");
	printf("5\n%d\n\n55\n%d\n\n610\n%d\n\n6765\n%d\n\n", ft_fibonacci(5), ft_fibonacci(10), ft_fibonacci(15), ft_fibonacci(20));

	// //ex05
	printf("-------ex05-------\n");
	printf("3\n%d\n\n200\n%d\n\n1000\n%d\n\n13\n%d\n\n", ft_sqrt(9), ft_sqrt(40000), ft_sqrt(1000000), ft_sqrt(169));
	printf("0\n%d\n\n1395\n%d\n\n", ft_sqrt(2147483647), ft_sqrt(1946025));

	// //ex06
	printf("-------ex06-------\n");
	printf("1\n%d\n\n0\n%d\n\n0\n%d\n\n0\n%d\n\n1\n%d\n\n", ft_is_prime(2147483647), ft_is_prime(4), ft_is_prime(0), ft_is_prime(4564987), ft_is_prime(149));

	// //ex07
	printf("-------ex07-------\n");
	printf("2147483647\n%d\n\n101\n%d\n\n75169\n%d\n\n4894933\n%d\n\n11\n%d\n\n", ft_find_next_prime(2147483640), ft_find_next_prime(100), ft_find_next_prime(75168), ft_find_next_prime(4894891), ft_find_next_prime(9));

	// //ex08
	printf("-------ex08-------\n");
	printf("%d",ft_ten_queens_puzzle());

}
