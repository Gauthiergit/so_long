#include "so_long.h"

void	clear_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

size_t	count_line_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int count_item(char **map, char c)
{
	int i;
	int j;
	int	item_nb;

	i = 0;
	item_nb = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				item_nb++;
			j++;
		}
		i++;
	}
	return (item_nb);
}
