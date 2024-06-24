void ft_swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

void sort_int_tab(int *tab, unsigned int size)
{
	//boucler sur la tab tant que le mombre de swap est nul
	//comparer chaque paire
	//si la paire est desordonnee, alors swap et augmenter count
	//si plus de swap, return
	
	int swap_count; 
	swap_count = 1;
	while (swap_count > 0)
	{
		swap_count = 0;
		for (unsigned int i = 0; i < size - 1; i++)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(tab + i, tab + i + 1);
				swap_count++;
			}
		}
	}
}
#include <stdio.h>

int main(void)
{
	int tab[5];

	tab[0] = 5;
	tab[1] = 4;
	tab[2] = 0;
	tab[3] = 19;
	tab[4] = 1;

	sort_int_tab(tab, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%i\n", tab[i]);
	}
}
