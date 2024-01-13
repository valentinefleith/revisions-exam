#include <stdlib.h>

int ft_count_words(char *str);
char **ft_fill_strs(char **strs, int wordcount, char *str);
int ft_isspace(char c);
char *ft_substr(char *str, int start, size_t len);
size_t ft_strlen_custom(char *str);


char **ft_split(char *str)
{
	int wordcount;
	char **strs;

	wordcount = ft_count_words(str);
	strs = malloc((1 + wordcount) * sizeof(char *));
	if (strs == NULL)
		return NULL;
	strs = ft_fill_strs(strs, wordcount, str);
	return strs;
}

char **ft_fill_strs(char **strs, int wordcount, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < wordcount)
	{
		if (!ft_isspace(str[j]))
		{
			strs[i] = ft_substr(str, j, ft_strlen_custom(str + j));
			i++;
			//if (!strs)
			//{
			//	ft_free_substrs(strs, i);
			//	return NULL;
			//}
			while (str[j] && !ft_isspace(str[j]))
				j++;
		}
	}
	strs[i] = '\0';
	return strs;
}

char *ft_substr(char *str, int start, size_t len)
{
	char *substr = malloc((1+len)*sizeof(char));
	if (substr == NULL)
		return NULL;
	int i = 0;
	while ((size_t)start < len)
	{
		substr[i] = str[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return substr;
}

size_t ft_strlen_custom(char *str)
{
	size_t i = 0;
	while (*str && !(ft_isspace(*str)))
	{
		i++;
	}
	return i;
}


int ft_count_words(char *str)
{
	int count;

	count = 0;
	while (ft_isspace(*str))
		str++;
	while (*str)
	{
		if (ft_isspace(*str))
		{
			count++;
			while (ft_isspace(*str))
				str++;
		}
		str++;
	}
	return count;
}

int ft_isspace(char c)
{
	char *spaces = " \t\n";

	while (*spaces)
	{
		if (c == *spaces)
			return 1;
		spaces++;
	}
	return 0;
}

#include <stdio.h>
int main(void)
{
	char hello[] = "salut bonjour hello";
	char **strs = ft_split(hello);
	for (int i = 0; i < 3; i++)
	{
		printf("%ie mot : %s\n", i, strs[i]);
	}
}
