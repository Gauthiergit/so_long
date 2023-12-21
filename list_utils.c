#include "so_long.h"

t_place	*newplace(int x, int y)
{
	t_place	*newplace;

	newplace = (t_place *)malloc(sizeof(*newplace));
	if (!newplace)
		return (NULL);
	newplace->x = x;
	newplace->y = y;
	newplace->next = NULL;
	return (newplace);
}

void	add_place(t_place **itemlist, t_place *newitem)
{
	if (!newitem)
		return ;
	newitem->next = *itemlist;
	*itemlist = newitem;
}

void	clear_list(t_place **itemlist)
{
	t_place	*current;
	t_place	*futur;

	current = *itemlist;
	if (!itemlist || !(*itemlist))
		return ;
	while (current->next != NULL)
	{
		futur = current->next;
		free(current);
		current = futur;
	}
	free(current);
	*itemlist = NULL;
}

void	clear_game(t_game *game)
{
	if (!game)
		return ;
	clear_tab(game->map);
	free(game->exit);
	free(game->perso);
	clear_list(&game->item);
	free(game->size);
	free(game);
}
