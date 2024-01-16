/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:39:40 by gpeyre            #+#    #+#             */
/*   Updated: 2024/01/16 09:10:02 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_place(t_place **itemlist, t_game *game, char **map);
char	**extract_map(char *map);
int		count_lines(char *map);
t_place	*init_size(char **map);

void	game_init(t_game *game, char *param)
{
	t_place	*chestlist;

	chestlist = NULL;
	game->player = NULL;
	game->exit = NULL;
	game->map = extract_map(param);
	init_place(&chestlist, game, game->map);
	game->chest = chestlist;
	game->size = init_size(game->map);
}

char	**extract_map(char *map)
{
	char	**extract;
	int		line_nb;
	int		i;
	int		fd;
	char	*line;

	line_nb = count_lines(map);
	extract = (char **)malloc((line_nb + 1) * sizeof(char *));
	fd = open(map, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		extract[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(fd);
	extract[i] = 0;
	return (extract);
}

int	count_lines(char *map)
{
	int		fd;
	int		line_nb;
	char	*line;

	fd = open(map, O_RDONLY);
	line_nb = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		line_nb++;
		free(line);
	}
	close(fd);
	return (line_nb);
}

void	init_place(t_place **itemlist, t_game *game, char **map)
{
	size_t	y;
	size_t	x;
	t_place	*item;

	y = 0;
	item = NULL;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P' && !game->player)
				game->player = newplace(x, y);
			else if (map[y][x] == 'E' && !game->exit)
				game->exit = newplace(x, y);
			else if (map[y][x] == 'C')
			{
				item = newplace(x, y);
				add_place(itemlist, item);
			}
			x++;
		}
		y++;
	}
}

t_place	*init_size(char **map)
{
	size_t	y;
	size_t	x;
	t_place	*size;

	x = ft_strlen(*map) - 3;
	y = count_line_tab(map) - 2;
	size = newplace(x, y);
	return (size);
}
