#include <unistd.h>

int ft_putchar(char c)
{
	return write(1, &c, 1);
}

int ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\f');
}

int ft_islower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int ft_isupper(char c)
{
	return (c >= 'A' && c < 'Z');
}

void ft_putlower(char c)
{
	if (ft_isupper(c))
		ft_putchar(c + 32);
	else
		ft_putchar(c);
}

void ft_putupper(char c)
{
	if (ft_islower(c))
		ft_putchar(c - 32);
	else
		ft_putchar(c);
}

void ft_str_capitalize(char *str)
{
	int is_new_word = 1;
	while (*str)
	{
		if (!is_new_word)
		{
			ft_putlower(*str);
		}
		else
		{
			ft_putupper(*str);
			is_new_word = 0;
		}
		if (ft_isspace(*str))
			is_new_word = 1;
		str++;
	}

}

int main(int argc, char **argv)
{
	if (argc < 2)
		return ft_putchar('\n');
	int i = 1;
	while (i < argc)
	{
		ft_str_capitalize(argv[i]);
		ft_putchar('\n');
		i++;
	}
}
