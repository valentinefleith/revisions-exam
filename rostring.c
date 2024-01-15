#include <inttypes.h>
#include <unistd.h>
#include <stdlib.h>

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

void ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

int ft_isspace(char c)
{
	char spaces[] = " \t\v\n\r\f";
	int i = 0;
	while (spaces[i])
	{
		if (spaces[i] == c)
			return 1;
		i++;
	}
	return 0;
}

int ft_countwords(char *str)
{
	int count = 0;
	while (*str)
	{
		if (!ft_isspace(*str))
		{
			count++;
			while (*str && !ft_isspace(*str))
				str++;
		}
		else
		{
			str++;
		}
	}
	return count;
}

char *ft_substr(char *str, int index, int len)
{
	char *substr;

	substr = malloc((1 + len) * sizeof(char));
	if (substr == NULL)
		return NULL;
	int i = 0;
	while (i < len)
	{
		substr[i] = str[index + i];
		i++;
	}
	substr[i] = '\0';
	return substr;

}

int ft_strlen_sep(char *str)
{
	int len = 0;
	while (*str && !ft_isspace(*str))
	{
		str++;
		len++;
	}
	return len;
}

void ft_free_all_substrs(char **strs, int len)
{
	int i = 0;
	while (i < len)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char **ft_fill_strs(char **strs, char *str, int wordcount)
{
	int i = 0;
	int j = 0;
	while (i < wordcount)
	{
		if (!ft_isspace(str[j]))
		{
			strs[i] = ft_substr(str, j, ft_strlen_sep(str + j));
			i++;
			if (strs[i - 1] == NULL)
			{
				ft_free_all_substrs(strs, i);
				return NULL;
			}
			while (str[j] && !ft_isspace(str[j]))
				j++;
		}
		j++;
	}
	strs[i] = 0;
	return strs;

}

char **ft_split(char *str)
{
	char **strs;
	int wordcount = ft_countwords(str);
	strs = malloc((1 + wordcount) * sizeof(char *));
	if (strs == NULL)
		return NULL;
	strs = ft_fill_strs(strs, str, wordcount);
	return strs;
}

char **rotate(char **strs, int wordcount)
{
	int i = 0;
	char *first = strs[i];
	while (i < wordcount - 1)
	{
		strs[i] = strs[i+1];
		i++;
	}
	strs[i] = first;
	return strs;
}


void print_string_tab(char **strs)
{
	int i = 0;
	while (strs[i])
	{
		ft_putstr(strs[i]);
		if (strs[i + 1])
			ft_putchar(' ');
		i++;
	}
}


int main(int argc, char **argv)
{
	if (argc < 2)
		return ft_putchar('\n');
	int wordcount = ft_countwords(argv[1]);
	char **strs;
	strs = ft_split(argv[1]);
	if (strs == NULL)
		return ft_putchar('\n');
	print_string_tab(rotate(strs, wordcount));
	ft_putchar('\n');
}
