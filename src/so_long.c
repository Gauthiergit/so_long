/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:45:38 by gpeyre            #+#    #+#             */
/*   Updated: 2024/01/13 11:34:57 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_game	game;

	check_error_file(argc, argv);
	game_init(&game, argv[1]);
	if (check_error_map(argv, &game))
		return (clear_game(&game), 1);
	data.game = game;
	data_init(&data);
	game_display(&data);
	mlx_loop_hook(data.mlx, &player_clock, &data);
	mlx_hook(data.win, 2, 1L << 0, &key_hook, &data);
	mlx_hook(data.win, 17, 1L << 17, &close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
