/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:50:08 by gpeyre            #+#    #+#             */
/*   Updated: 2024/01/11 18:02:57 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_move_img(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(data->mlx, data->anims.pl_anim[i]);
		i++;
	}
	free(data->anims.pl_anim);
	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(data->mlx, data->anims.pb_anim[i]);
		i++;
	}
	free(data->anims.pb_anim);
	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(data->mlx, data->anims.pr_anim[i]);
		i++;
	}
	free(data->anims.pr_anim);
}

void	clear_strike_img(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(data->mlx, data->anims.sb_anim[i]);
		i++;
	}
	free(data->anims.sb_anim);
	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(data->mlx, data->anims.sl_anim[i]);
		i++;
	}
	free(data->anims.sl_anim);
	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(data->mlx, data->anims.sr_anim[i]);
		i++;
	}
	free(data->anims.sr_anim);
}

void	clear_all_img(t_data *data)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		mlx_destroy_image(data->mlx, data->img[i]);
		i++;
	}
	free(data->img);
	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(data->mlx, data->anims.pf_anim[i]);
		i++;
	}
	free(data->anims.pf_anim);
	clear_move_img(data);
	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(data->mlx, data->anims.sf_anim[i]);
		i++;
	}
	free(data->anims.sf_anim);
	clear_strike_img(data);
}
