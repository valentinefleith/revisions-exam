#include <stdlib.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
	{
		i++;
	}
	return i;
}

char    *ft_strdup(char *src)
{
	char *new;

	new = malloc((1 + ft_strlen(src) * sizeof(char)));
	if (new == NULL)
		return NULL;
	int i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return new;
}
