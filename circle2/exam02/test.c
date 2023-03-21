//#include <stdarg.h>
//#include <unistd.h>

//int ft_putchar(char c)
//{
//	write(1,&c,1);
//	return 1;
//}

//int ft_putstr(char *str)
//{
//	int i = 0;

//	if(!str){
//		write(1,"(null)",6);
//		return (0);

//	}
//	while (str[i]){
//		ft_putchar(str[i]);
//		i++;
//	}
//	return i;
//}

//int ft_putnbr(int nb){
//	long long n;
//	int len = 0;

//	n = nb;
//	if(n < 0){
//		n = -n;
//		len += ft_putchar('-');
//	}
//	if(n > 9){
//		len += ft_putnbr(n / 10);
//		len += ft_putnbr(n % 10);
//	}
//	else{
//		len += ft_putchar(n + 48);
//	}
//	return len;
//}

//int ft_puthex(unsigned int num){
//	int len = 0;

//	if (num > 15){
//		len += ft_puthex(num / 16);
//		len += ft_puthex(num % 16);
//	}
//	else if (num > 9){
//		len += ft_putchar(num + 87);
//	}
//	else{
//		len += ft_putchar(num + 48);
//	}
//	return len;
//}

//int ft_printf(const char *format, ...)
//{
//	int i = 0;
//	int len = 0;
//	va_list ptr;

//	va_start(ptr,format);
//	while(format[i])
//	{
//		if (format[i] != '%')
//			len += write(1,&format[i],1);
//		else if(format[i] == '%' &&format[i+1]){
//			i++;
//			if(format[i] == 's')
//				len += ft_putstr(va_arg(ptr,char *));
//			else if(format[i] == 'x')
//				len += ft_puthex(va_arg(ptr,unsigned int));
//			else if(format[i] =='d')
//				len += ft_putnbr(va_arg(ptr,int));
//		}
//		i++;
//	}
//	va_end(ptr);
//	return (len);
//}


//#include <unistd.h>


//#define BUFFER_SIZE 4000

//int ft_strlen(char *str)
//{
//	int i = 0;

//	while (str[i]!= '\0')
//	{
//		i++;
//	}
//	return i;
//}

//char *ft_strdup(char *str)
//{
//	int len = ft_strlen(str);
//	int i = 0;
//	char *dup = malloc(len + 1);

//	if(!dup)
//		return NULL;
//	while (str[i]){
//		dup[i]  = str[i];
//		i++;
//	}
//	dup[i] = 0;
//	return (dup);
//}

//char *get_next_line(int fd)
//{
//	char buffer;
//	char rtn[700000];
//	int n;
//	int i = 0;

//	if (fd < 0 || BUFFER_SIZE < 0)
//		return (0);
//	n = read(fd,&buffer,1);
//	while(n>0){
//		rtn[i++] = buffer;
//		if (buffer == '\n')
//			break;
//		n = read(fd,&buffer,1);
//	}
//	rtn[i] = 0;
//	if(n <=0 && i ==0)
//		return (0);
//	return (ft_strdup(rtn));
//}
