/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:19:27 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/15 11:26:44 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		return ft_putchar('\n');
	}
	char *str = argv[1];
	while (*str == ' ' || *str == '\t')
		str++;
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
		{
			while ((*str == ' ' || *str == '\t') && *(str + 1) != '\0')
			{
				str++;
			}
			if (*(str + 1) == '\0' && (*str == ' ' || *str == '\t'))
				break;
			else
			{
				ft_putchar(' ');
			}
			while (*str == ' ' || *str == '\t')
				str++;
		}
		ft_putchar(*str);
		str++;
	}

	return ft_putchar('\n');
}
