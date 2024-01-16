/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:43:41 by gpeyre            #+#    #+#             */
/*   Updated: 2024/01/15 15:54:20 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	clear_list(t_place *itemlist)
{
	t_place	*current;
	t_place	*futur;

	current = itemlist;
	if (!itemlist)
		return ;
	while (current)
	{
		futur = current->next;
		free(current);
		current = futur;
	}
	itemlist = NULL;
}

void	clear_game(t_game *game)
{
	if (!game)
		return ;
	clear_tab(game->map);
	clear_list(game->exit);
	clear_list(game->player);
	clear_list(game->chest);
	clear_list(game->size);
}
