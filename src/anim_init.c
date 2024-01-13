/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:19:02 by gpeyre            #+#    #+#             */
/*   Updated: 2024/01/11 10:10:06 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	**pf_init(void *mlx_ptr, int width, int height)
{
	void	**pf_anim;

	pf_anim = (void **)malloc(5 * sizeof(void *));
	if (!pf_anim)
		return (NULL);
	pf_anim[0] = mlx_xpm_file_to_image(mlx_ptr, PF_PATH_1, &width, &height);
	pf_anim[1] = mlx_xpm_file_to_image(mlx_ptr, PF_PATH_2, &width, &height);
	pf_anim[2] = mlx_xpm_file_to_image(mlx_ptr, PF_PATH_3, &width, &height);
	pf_anim[3] = mlx_xpm_file_to_image(mlx_ptr, PF_PATH_4, &width, &height);
	pf_anim[4] = 0;
	return (pf_anim);
}

void	**pr_init(void *mlx_ptr, int width, int height)
{
	void	**pr_anim;

	pr_anim = (void **)malloc(5 * sizeof(void *));
	if (!pr_anim)
		return (NULL);
	pr_anim[0] = mlx_xpm_file_to_image(mlx_ptr, PR_PATH_1, &width, &height);
	pr_anim[1] = mlx_xpm_file_to_image(mlx_ptr, PR_PATH_2, &width, &height);
	pr_anim[2] = mlx_xpm_file_to_image(mlx_ptr, PR_PATH_3, &width, &height);
	pr_anim[3] = mlx_xpm_file_to_image(mlx_ptr, PR_PATH_4, &width, &height);
	pr_anim[4] = 0;
	return (pr_anim);
}

void	**pb_init(void *mlx_ptr, int width, int height)
{
	void	**pb_anim;

	pb_anim = (void **)malloc(5 * sizeof(void *));
	if (!pb_anim)
		return (NULL);
	pb_anim[0] = mlx_xpm_file_to_image(mlx_ptr, PB_PATH_1, &width, &height);
	pb_anim[1] = mlx_xpm_file_to_image(mlx_ptr, PB_PATH_2, &width, &height);
	pb_anim[2] = mlx_xpm_file_to_image(mlx_ptr, PB_PATH_3, &width, &height);
	pb_anim[3] = mlx_xpm_file_to_image(mlx_ptr, PB_PATH_4, &width, &height);
	pb_anim[4] = 0;
	return (pb_anim);
}

void	**pl_init(void *mlx_ptr, int width, int height)
{
	void	**pl_anim;

	pl_anim = (void **)malloc(5 * sizeof(void *));
	if (!pl_anim)
		return (NULL);
	pl_anim[0] = mlx_xpm_file_to_image(mlx_ptr, PL_PATH_1, &width, &height);
	pl_anim[1] = mlx_xpm_file_to_image(mlx_ptr, PL_PATH_2, &width, &height);
	pl_anim[2] = mlx_xpm_file_to_image(mlx_ptr, PL_PATH_3, &width, &height);
	pl_anim[3] = mlx_xpm_file_to_image(mlx_ptr, PL_PATH_4, &width, &height);
	pl_anim[4] = 0;
	return (pl_anim);
}
