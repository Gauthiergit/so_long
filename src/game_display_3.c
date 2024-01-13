/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:29:27 by gpeyre            #+#    #+#             */
/*   Updated: 2024/01/13 11:25:17 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	strike_it(t_data *data);

void	anime_it(t_data *data)
{
	int	x;
	int	y;

	x = data->game.player->x;
	y = data->game.player->y;
	if (data->direction == FRONT && !data->strike)
		mlx_put_image_to_window((*data).mlx, (*data).win,
			data->anims.pf_anim[data->cur_anim],
			x * (*data).width, y * (*data).height);
	else if (data->direction == RIGHT && !data->strike)
		mlx_put_image_to_window((*data).mlx, (*data).win,
			data->anims.pr_anim[data->cur_anim],
			x * (*data).width, y * (*data).height);
	else if (data->direction == LEFT && !data->strike)
		mlx_put_image_to_window((*data).mlx, (*data).win,
			data->anims.pl_anim[data->cur_anim],
			x * (*data).width, y * (*data).height);
	else if (data->direction == BACK && !data->strike)
		mlx_put_image_to_window((*data).mlx, (*data).win,
			data->anims.pb_anim[data->cur_anim],
			x * (*data).width, y * (*data).height);
	strike_it(data);
}

void	strike_it(t_data *data)
{
	int	x;
	int	y;

	x = data->game.player->x;
	y = data->game.player->y;
	if (data->direction == FRONT && data->strike)
		mlx_put_image_to_window((*data).mlx, (*data).win,
			data->anims.sf_anim[data->cur_anim],
			x * (*data).width, y * (*data).height);
	else if (data->direction == BACK && data->strike)
		mlx_put_image_to_window((*data).mlx, (*data).win,
			data->anims.sb_anim[data->cur_anim],
			x * (*data).width, y * (*data).height);
	else if (data->direction == RIGHT && data->strike)
		mlx_put_image_to_window((*data).mlx, (*data).win,
			data->anims.sr_anim[data->cur_anim],
			x * (*data).width, y * (*data).height);
	else if (data->direction == LEFT && data->strike)
		mlx_put_image_to_window((*data).mlx, (*data).win,
			data->anims.sl_anim[data->cur_anim],
			x * (*data).width, y * (*data).height);
}

int	player_clock(t_data *data)
{
	if (data->anim_clock == 3000)
	{
		if (data->cur_anim == 3)
		{
			data->cur_anim = 0;
			data->strike = 0;
		}
		else
		{
			anime_it(data);
			data->cur_anim++;
		}
		data->anim_clock = 0;
	}
	else
		data->anim_clock++;
	return (0);
}
