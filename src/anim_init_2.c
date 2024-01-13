/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_init_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:09:43 by gpeyre            #+#    #+#             */
/*   Updated: 2024/01/11 10:45:29 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	**sf_init(void *mlx_ptr, int width, int height)
{
	void	**sf_anim;

	sf_anim = (void **)malloc(5 * sizeof(void *));
	if (!sf_anim)
		return (NULL);
	sf_anim[0] = mlx_xpm_file_to_image(mlx_ptr, SF_PATH_1, &width, &height);
	sf_anim[1] = mlx_xpm_file_to_image(mlx_ptr, SF_PATH_2, &width, &height);
	sf_anim[2] = mlx_xpm_file_to_image(mlx_ptr, SF_PATH_3, &width, &height);
	sf_anim[3] = mlx_xpm_file_to_image(mlx_ptr, SF_PATH_4, &width, &height);
	sf_anim[4] = 0;
	return (sf_anim);
}

void	**sb_init(void *mlx_ptr, int width, int height)
{
	void	**sb_anim;

	sb_anim = (void **)malloc(5 * sizeof(void *));
	if (!sb_anim)
		return (NULL);
	sb_anim[0] = mlx_xpm_file_to_image(mlx_ptr, SB_PATH_1, &width, &height);
	sb_anim[1] = mlx_xpm_file_to_image(mlx_ptr, SB_PATH_2, &width, &height);
	sb_anim[2] = mlx_xpm_file_to_image(mlx_ptr, SB_PATH_3, &width, &height);
	sb_anim[3] = mlx_xpm_file_to_image(mlx_ptr, SB_PATH_4, &width, &height);
	sb_anim[4] = 0;
	return (sb_anim);
}

void	**sr_init(void *mlx_ptr, int width, int height)
{
	void	**sr_anim;

	sr_anim = (void **)malloc(5 * sizeof(void *));
	if (!sr_anim)
		return (NULL);
	sr_anim[0] = mlx_xpm_file_to_image(mlx_ptr, SR_PATH_1, &width, &height);
	sr_anim[1] = mlx_xpm_file_to_image(mlx_ptr, SR_PATH_2, &width, &height);
	sr_anim[2] = mlx_xpm_file_to_image(mlx_ptr, SR_PATH_3, &width, &height);
	sr_anim[3] = mlx_xpm_file_to_image(mlx_ptr, SR_PATH_4, &width, &height);
	sr_anim[4] = 0;
	return (sr_anim);
}

void	**sl_init(void *mlx_ptr, int width, int height)
{
	void	**sl_anim;

	sl_anim = (void **)malloc(5 * sizeof(void *));
	if (!sl_anim)
		return (NULL);
	sl_anim[0] = mlx_xpm_file_to_image(mlx_ptr, SL_PATH_1, &width, &height);
	sl_anim[1] = mlx_xpm_file_to_image(mlx_ptr, SL_PATH_2, &width, &height);
	sl_anim[2] = mlx_xpm_file_to_image(mlx_ptr, SL_PATH_3, &width, &height);
	sl_anim[3] = mlx_xpm_file_to_image(mlx_ptr, SL_PATH_4, &width, &height);
	sl_anim[4] = 0;
	return (sl_anim);
}
