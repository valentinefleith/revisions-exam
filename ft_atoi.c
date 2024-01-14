unsigned int ft_atoui(char *str);

int ft_isdigit(char c)
{
	char *digits;
	digits = "0123456789";

	while (*digits)
	{
		if (*digits == c)
		{
			return 1;
		}
		digits++;
	}
	return 0;
}

int ft_atoi(char *str)
{
	if (*str == '-')
	{
		str++;
		return -ft_atoui(str);
	}
	return ft_atoui(str);
}

unsigned int ft_atoui(char *str)
{
	unsigned int output = 0;

	while (*str && ft_isdigit(*str))
	{
		output = output * 10 + (*str - '0');
		str++;
	}
	return output;
}

int main(void)
{
	char test[] = "-42";
	#include <stdio.h>
	printf("%i\n", ft_atoi(test));

}
