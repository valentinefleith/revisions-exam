#include <stdlib.h>

int ft_count_words(char *str);
int ft_isspace(char c);

char **ft_split(char *str)
{
	int wordcount = ft_count_words(str);
	char **strs = malloc((1 + wordcount) * sizeof(char *));
	if (strs == NULL)
		return NULL;
	strs = ft_fill_strs(strs, str, wordcount);
	return strs;
}

char **ft_fill_strs(char **strs, char *str, int wordcount)
{

}



int ft_count_words(char *str)
{
	int count = 0;
	while (*str)
	{
		if (!ft_isspace(*str))
		{
			count++;
			while (ft_isspace(*str))
				str++;
		}
		else
		{
			str++;
		}
	}
	return count;
}

int ft_isspace(char c)
{
	char spaces[3] = " \n\t";
	int i = 0;
	while (spaces[i])
	{
		if (spaces[i] == c)
			return 1;
		i++;
	}
	return 0;
}
