void	*ft_print_memory(void *addr, unsigned int size);

int	main()
{
	char	str[92] = "Bonjour les aminches   c  est fou tout ce qu on peut faire avec   print_memory    lol lol";
	str[20] = 0x09;
 	str[21] = 0x0a;
 	str[22] = 0x09;
 	str[33] = 0x09;
 	str[38] = 0x09;
 	str[63] = 0x09;
 	str[64] = 0x0a;
 	str[65] = 0x09;
 	str[78] = 0x0a;
 	str[79] = 0x0a;
 	str[80] = 0x0a;
 	str[81] = 0x09;
	str[85] = 0x2e;
	str[89] = 0x0a;
	str[90] = 0x20;
	ft_print_memory(str, 92);
}
