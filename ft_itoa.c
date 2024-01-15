/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:54:14 by vafleith          #+#    #+#             */
/*   Updated: 2024/01/15 19:59:18 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_find_strsize(int nbr)
{
	int size = 0;
	if (nbr < 0)
	{
		size++;
		nbr *= -1;
	}
	if (nbr == 0)
		return 1;
	while (nbr)
	{
		nbr = nbr / 10;
		size++;
	}
	return size;
}

char *ft_uitoa(unsigned int nbr, char *output, int size)
{
	int i = size - 1;
	while (i >=0)
	{
		output[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
	output[size] = '\0';
	return output;
}


char	*ft_itoa(int nbr)
{
	int size;
	char *output;

	size = ft_find_strsize(nbr);
	output = malloc((1 + size) * sizeof(char));
	if (output == NULL)
		return NULL;
	if (nbr < 0)
	{
		output[0] = '-';
		output++;
		output = ft_uitoa(-nbr, output, size - 1);
		return (output - 1);
	}
	return ft_uitoa(nbr, output, size);
}
/*
#include <stdio.h>
int main(void)
{
	int test = 0;
	printf("%s\n", ft_itoa(test));
}
*/
