/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:44:27 by gpeyre            #+#    #+#             */
/*   Updated: 2024/01/13 12:10:21 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_next_move(t_data *data, int x, int y)
{
	if (data->game.map[y][x] == (*data).content.wall)
		return (1);
	else if (data->game.map[y][x] == data->content.exit
		&& !data->content.count_c)
		close_window(data);
	else if (data->game.map[y][x] == data->content.exit
		&& data->content.count_c)
		return (1);
	else if (data->game.map[y][x] == data->content.chest)
	{
		data->content.count_c--;
		data->game.map[y][x] = data->content.floor;
		print_texture(data, data->img[CHESTO], x, y);
		if (!data->content.count_c)
			print_texture(data, data->img[EXITO],
				data->game.exit->x,
				data->game.exit->y);
		return (1);
	}
	else if (data->game.map[y][x] == data->content.enemy)
	{
		ft_printf("GAME OVER\nYOU ARE DEAD\n");
		close_window(data);
	}
	return (0);
}

void	move_top(t_data *data)
{
	int	x;
	int	y;

	x = data->game.player->x;
	y = data->game.player->y;
	if (!data->content.first_b)
	{
		if (!check_next_move(data, x, y - 1))
		{
			data->game.map[y - 1][x] = data->content.player;
			print_texture(data, data->img[FLOOR], x, y);
			data->game.map[y][x] = data->content.floor;
			data->game.player->y--;
			data->count_mouv++;
			print_frame(data);
			ft_printf("Move number: %d\n", data->count_mouv);
		}
	}
	data->direction = BACK;
	data->content.first_f = 1;
	data->content.first_b = 0;
	data->content.first_r = 1;
	data->content.first_l = 1;
}

void	move_down(t_data *data)
{
	int	x;
	int	y;

	x = data->game.player->x;
	y = data->game.player->y;
	if (!data->content.first_f)
	{
		if (!check_next_move(data, x, y + 1))
		{
			data->game.map[y + 1][x] = data->content.player;
			print_texture(data, data->img[FLOOR], x, y);
			data->game.map[y][x] = data->content.floor;
			data->game.player->y++;
			data->count_mouv++;
			print_frame(data);
			ft_printf("Move number: %d\n", data->count_mouv);
		}
	}
	data->direction = FRONT;
	data->content.first_f = 0;
	data->content.first_b = 1;
	data->content.first_r = 1;
	data->content.first_l = 1;
}

void	move_left(t_data *data)
{
	int	x;
	int	y;

	x = data->game.player->x;
	y = data->game.player->y;
	if (!data->content.first_l)
	{
		if (!check_next_move(data, x - 1, y))
		{
			data->game.map[y][x - 1] = data->content.player;
			print_texture(data, data->img[FLOOR], x, y);
			data->game.map[y][x] = data->content.floor;
			data->game.player->x--;
			data->count_mouv++;
			print_frame(data);
			ft_printf("Move number: %d\n", data->count_mouv);
		}
	}
	data->direction = LEFT;
	data->content.first_f = 1;
	data->content.first_b = 1;
	data->content.first_r = 1;
	data->content.first_l = 0;
}

void	move_right(t_data *data)
{
	int	x;
	int	y;

	x = data->game.player->x;
	y = data->game.player->y;
	if (!data->content.first_r)
	{
		if (!check_next_move(data, x + 1, y))
		{
			data->game.map[y][x + 1] = data->content.player;
			print_texture(data, data->img[FLOOR], x, y);
			data->game.map[y][x] = data->content.floor;
			data->game.player->x++;
			data->count_mouv++;
			print_frame(data);
			ft_printf("Move number: %d\n", data->count_mouv);
		}
	}
	data->direction = RIGHT;
	data->content.first_f = 1;
	data->content.first_b = 1;
	data->content.first_r = 0;
	data->content.first_l = 1;
}
