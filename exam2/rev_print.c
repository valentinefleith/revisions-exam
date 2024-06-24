#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
	{
		i++;
	}
	return i;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return 1;
	}

	int i = ft_strlen(argv[1]) - 1;
	for (i = ft_strlen(argv[1]) - 1; i >= 0; i--)
	{
		ft_putchar(argv[1][i]);
	}
	ft_putchar('\n');
}
