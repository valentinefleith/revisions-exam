#include <stdarg.h>
#include <unistd.h>
#define DEC "0123456789"
#define HEX "0123456789abcdef"

int ft_strlen(char *s)
{
	int len = 0;
	while(s[len])
		len++;
	return len;
}

int ft_print_char(char c)
{
	write(1, &c, 1);
	return 1;
}

int ft_print_str(char *str)
{
	if (!str)
		return ft_print_str("(null)");
	int count;
	count = 0;
	while (str[count])
	{
		ft_print_char(str[count]);
		count++;
	}
	return count;
}

int ft_print_unsigned_base(unsigned long long nb, char *base)
{
	int count = 0;
	size_t base_len = ft_strlen(base);
	if (nb < base_len)
		count += ft_print_char(base[nb % base_len]);
	else 
	{
		count += ft_print_unsigned_base(nb / base_len, base);
		count += ft_print_unsigned_base(nb % base_len, base);
	}
	return count;
}

int ft_print_nbr_base(long long nb, char *base)
{
	if (nb < 0)
	{
		ft_print_char('-');
		return (1 + ft_print_unsigned_base(-nb, base));
	}
	return ft_print_unsigned_base(nb, base);

}

//int ft_print_unsigned(unsigned int nb)
//{
//	int count = 0;
//	if (nb < 10)
//		count += ft_print_char(nb + '0');
//	else 
//	{
//		count += ft_print_unsigned(nb / 10);
//		count += ft_print_unsigned(nb % 10);
//	}
//	return (count);
//}
//
//int ft_print_nb(int nb)
//{
//	if (nb < 0)
//	{
//		ft_print_char('-');
//		return (ft_print_unsigned(-nb) + 1);
//	}
//	return ft_print_unsigned(nb);
//}
//

int ft_print_arg(char format, va_list arguments)
{
	if (format == 's')
		return ft_print_str(va_arg(arguments, char *));
	if (format == 'd')
		return ft_print_nbr_base(va_arg(arguments, int), DEC);
	if (format == 'x')
		return ft_print_nbr_base(va_arg(arguments, unsigned int), HEX);
	return 0;
}

int ft_printf(const char *format, ...)
{
	if (!format)
		return 0;
	va_list arguments;
	va_start(arguments, format);
	int count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_print_arg(*format, arguments);
		}
		else 
			count += ft_print_char(*format);
		format++;
	}
	va_end(arguments);
	return count;
}
//
//int main()
//{
//	ft_printf("hello : %d hexa is %x\n", 42, 42);
//	ft_printf("%d%d%d%x\n", 0, 0, 42, 42);
//	ft_printf("%x", 80000000);
//	ft_printf("INT MAX:\n");
//	ft_printf("%d\n%x\n", 2147483647, 2147483647);
//	ft_printf("INT MIN:\n");
//	ft_printf("%d--%x\n", -2147483648, -2147483648);
//	ft_printf("");
//}
