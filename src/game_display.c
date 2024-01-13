/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:31:50 by gpeyre            #+#    #+#             */
/*   Updated: 2024/01/13 11:28:35 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_display(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->game.map[y])
	{
		x = 0;
		while (data->game.map[y][x] && data->game.map[y][x] != '\n')
		{
			if (data->game.map[y][x] == data->content.wall)
				print_texture(data, data->img[WALL], x, y);
			else if (data->game.map[y][x] == data->content.floor)
				print_texture(data, data->img[FLOOR], x, y);
			else if (data->game.map[y][x] == data->content.exit)
				print_texture(data, data->img[EXITC], x, y);
			else if (data->game.map[y][x] == data->content.chest)
				print_texture(data, data->img[CHESTC], x, y);
			else if (data->game.map[y][x] == data->content.enemy)
				print_texture(data, data->img[ENY], x, y);
			x++;
		}
		y++;
	}
	print_frame(data);
}

void	print_texture(t_data *data, void *texture, int x, int y)
{
	mlx_put_image_to_window((*data).mlx, (*data).win, texture,
		x * (*data).width, y * (*data).height);
}

int	close_window(t_data *data)
{
	clear_all_img(data);
	clear_game(&data->game);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	if (keycode == 119 || keycode == 65362)
		move_top(data);
	if (keycode == 115 || keycode == 65364)
		move_down(data);
	if (keycode == 97 || keycode == 65361)
		move_left(data);
	if (keycode == 100 || keycode == 65363)
		move_right(data);
	if (keycode == 32)
	{
		data->cur_anim = 0;
		data->strike = 1;
		check_kill(data);
	}
	return (0);
}
