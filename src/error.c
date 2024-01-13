/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:37:33 by gpeyre            #+#    #+#             */
/*   Updated: 2024/01/13 12:08:33 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_walls(char **map);
int		is_rectangle(char **map);
int		check_valid_path(char *map, t_game *game);

int	check_error_map(char **argv, t_game *game)
{
	if (check_walls(game->map))
		return (ft_printf("Error\nThe map isn't closed\n"), 1);
	if (is_rectangle(game->map))
		return (ft_printf("Error\nThe map isn't a rectangle\n"), 1);
	if (count_item(game->map, 'P') != 1)
		return (ft_printf("Error\nNo starting position or too much\n"), 1);
	if (count_item(game->map, 'E') != 1)
		return (ft_printf("Error\nNo exit item or too much\n"), 1);
	if (!count_item(game->map, 'C'))
		return (ft_printf("Error\nThere is no collectable\n"), 1);
	if (check_valid_path(argv[1], game))
		return (ft_printf("Error\nThere is no valid path\n"), 1);
	return (0);
}

int	check_walls(char **map)
{
	size_t	cur_line;
	int		i;

	cur_line = 0;
	while (map[cur_line])
	{
		if (cur_line == 0 || cur_line == (count_line_tab(map) - 1))
		{
			i = 0;
			while (map[cur_line][i] && map[cur_line][i] != '\n')
			{
				if (map[cur_line][i] != '1')
					return (1);
				i++;
			}
		}
		else
		{
			if (map[cur_line][0] != '1' ||
				map[cur_line][ft_strlen(map[cur_line]) - 2] != '1')
				return (1);
		}
		cur_line++;
	}
	return (0);
}

int	is_rectangle(char **map)
{
	int		i;
	size_t	len_base;
	size_t	len;

	i = 0;
	len_base = ft_strlen(map[0]);
	if (map[0][len_base - 1] == '\n')
		len_base--;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (map[i][len - 1] == '\n')
			len--;
		if (len == count_line_tab(map) || len != len_base)
			return (1);
		i++;
	}
	return (0);
}

void	find_path(char **map, t_place *size, t_place *perso, int exit)
{
	if (exit)
	{
		if (perso->y < 1 || perso->y > size->y
			|| perso->x < 1 || perso->x > size->x
			|| map[perso->y][perso->x] == '1'
			|| map[perso->y][perso->x] == 'V'
			|| map[perso->y][perso->x] == 'E')
			return ;
	}
	else
	{
		if (perso->y < 1 || perso->y > size->y
			|| perso->x < 1 || perso->x > size->x
			|| map[perso->y][perso->x] == '1'
			|| map[perso->y][perso->x] == 'V')
			return ;
	}
	map[perso->y][perso->x] = 'V';
	find_path(map, size, &(t_place){perso->x - 1, perso->y, perso->next}, exit);
	find_path(map, size, &(t_place){perso->x + 1, perso->y, perso->next}, exit);
	find_path(map, size, &(t_place){perso->x, perso->y - 1, perso->next}, exit);
	find_path(map, size, &(t_place){perso->x, perso->y + 1, perso->next}, exit);
}

int	check_valid_path(char *map, t_game *game)
{
	char	**newmap;
	t_place	*cur;

	newmap = extract_map(map);
	find_path(newmap, game->size, game->player, 1);
	cur = game->chest;
	while (cur)
	{
		if (newmap[cur->y][cur->x] != 'V')
			return (clear_tab(newmap), 1);
		cur = cur->next;
	}
	clear_tab(newmap);
	newmap = extract_map(map);
	find_path(newmap, game->size, game->player, 0);
	if (newmap[game->exit->y][game->exit->x] != 'V')
		return (clear_tab(newmap), 1);
	clear_tab(newmap);
	return (0);
}
