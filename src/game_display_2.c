/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:08:10 by gpeyre            #+#    #+#             */
/*   Updated: 2024/01/13 11:24:34 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_frame(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y <= 50)
	{
		x = 0;
		while (x <= 150)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, 0);
			x++;
		}
		y++;
	}
	print_counter(data);
	return (0);
}

void	print_counter(t_data *data)
{
	char	*m_num;
	char	*w_num;
	char	*m_put;
	char	*w_put;

	m_num = ft_itoa(data->count_mouv);
	w_num = ft_itoa(data->content.count_c);
	m_put = ft_strjoin("Move number: ", m_num);
	w_put = ft_strjoin("Chest number: ", w_num);
	mlx_string_put(data->mlx, data->win, 25, 15, 0xFFFFFF, m_put);
	mlx_string_put(data->mlx, data->win, 25, 35, 0xFFFFFF, w_put);
	free(m_num);
	free(m_put);
	free(w_num);
	free(w_put);
}

void	kill(t_data *data, int x, int y)
{
	if (data->game.map[y][x] == data->content.enemy)
	{
		data->game.map[y][x] = FLOOR;
		print_texture(data, data->img[FLOOR], x, y);
	}
}

void	check_kill(t_data *data)
{
	int	x;
	int	y;

	x = data->game.player->x;
	y = data->game.player->y;
	if (data->direction == FRONT)
		kill(data, x, y + 1);
	else if (data->direction == BACK)
		kill(data, x, y - 1);
	else if (data->direction == RIGHT)
		kill(data, x + 1, y);
	else if (data->direction == LEFT)
		kill(data, x - 1, y);
}
