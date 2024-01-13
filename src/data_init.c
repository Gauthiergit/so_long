/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:58:45 by gpeyre            #+#    #+#             */
/*   Updated: 2024/01/13 11:16:20 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	**img_init(void *mlx_ptr, int width, int height);
t_cnt	content_init(char **map);

void	data_init(t_data *data)
{
	data->mlx = mlx_init();
	data->width = 64;
	data->height = 64;
	data->win = mlx_new_window(data->mlx,
			data->width * (ft_strlen(data->game.map[0]) - 1),
			data->height * count_line_tab(data->game.map),
			"so_long");
	data->img = img_init(data->mlx, data->width, data->height);
	data->anims.pf_anim = pf_init(data->mlx, data->width, data->height);
	data->anims.pr_anim = pr_init(data->mlx, data->width, data->height);
	data->anims.pb_anim = pb_init(data->mlx, data->width, data->height);
	data->anims.pl_anim = pl_init(data->mlx, data->width, data->height);
	data->anims.sf_anim = sf_init(data->mlx, data->width, data->height);
	data->anims.sb_anim = sb_init(data->mlx, data->width, data->height);
	data->anims.sr_anim = sr_init(data->mlx, data->width, data->height);
	data->anims.sl_anim = sl_init(data->mlx, data->width, data->height);
	data->count_mouv = 0;
	data->content = content_init(data->game.map);
	data->anim_clock = 0;
	data->cur_anim = 0;
	data->direction = 'f';
	data->strike = 0;
}

void	**img_init(void *mlx_ptr, int width, int height)
{
	void	**img;

	img = (void **)malloc(8 * sizeof(void *));
	if (!img)
		return (NULL);
	img[FLOOR] = mlx_xpm_file_to_image(mlx_ptr, FLOOR_PATH, &width, &height);
	img[WALL] = mlx_xpm_file_to_image(mlx_ptr, WALL_PATH, &width, &height);
	img[ENY] = mlx_xpm_file_to_image(mlx_ptr, ENY_PATH, &width, &height);
	img[EXITC] = mlx_xpm_file_to_image(mlx_ptr, EXITC_PATH, &width, &height);
	img[EXITO] = mlx_xpm_file_to_image(mlx_ptr, EXITO_PATH, &width, &height);
	img[CHESTC] = mlx_xpm_file_to_image(mlx_ptr, CHESTC_PATH, &width, &height);
	img[CHESTO] = mlx_xpm_file_to_image(mlx_ptr, CHESTO_PATH, &width, &height);
	img[7] = 0;
	return (img);
}

t_cnt	content_init(char **map)
{
	t_cnt	content;

	content.count_c = count_item(map, 'C');
	content.exit = 'E';
	content.player = 'P';
	content.floor = '0';
	content.wall = '1';
	content.chest = 'C';
	content.enemy = 'W';
	content.first_b = 1;
	content.first_f = 1;
	content.first_l = 1;
	content.first_r = 1;
	return (content);
}
