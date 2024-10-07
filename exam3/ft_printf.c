#include <unistd.h>
#include <stdarg.h>

#define DEC "0123456789"
#define HEX "0123456789abcdef"

int ft_print_char(char c) {
	write(1, &c, 1);
	return 1;
}

int ft_print_str(char *str) {
	if (!str)
		return ft_print_str("(null)");
	int i = 0;
	while (str[i]) {
		i += ft_print_char(str[i]);
	}
	return i;
}

size_t ft_strlen(char *str) {
	size_t len = 0;
	while (str[len]) {
		len ++;
	}
	return len;
}

int ft_print_unsigned(unsigned long long nb, char *base) {
	int count = 0;
	size_t base_len = ft_strlen(base);
	if (nb < base_len)
		count += ft_print_char (base[nb % base_len]);
	else {
		count += ft_print_unsigned(nb / base_len, base);
		count += ft_print_unsigned(nb % base_len, base);
	}
	return count;
}

int ft_print_nbr_base(long long nb, char *base) {
	if (nb < 0) {
		ft_print_char('-');
		return (1 + ft_print_unsigned(-nb, base));
	}
	return ft_print_unsigned(nb, base);
}

int ft_print_arg(char c, va_list arguments) {
	if (c == 's')
		return ft_print_str(va_arg(arguments, char *));
	if (c == 'd') 
		return ft_print_nbr_base(va_arg(arguments, int), DEC);
	if (c == 'x')
		return ft_print_nbr_base(va_arg(arguments, unsigned int), HEX);
	return 0;
}

int ft_printf(char *format, ...) {
	if (!format)
		return 0;
	va_list arguments;
	va_start(arguments, format);
	int count = 0;
	while (*format) {
		if (*format == '%') {
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
