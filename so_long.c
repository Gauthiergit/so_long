#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;
	void	*kratos_img;
	void	*snow_img;
	void	*door_img;
	void	*werewolf_img;
	void	*wall_img;
	int 	width = 64;
	int		height = 64;
	int		i;
	int		j;
	int		x;
	int		y;
	char	**map;
	t_game	*game;

	game = game_init(argv[1]);

	if (check_error(argc, argv, game))
		return (clear_game(game), 1);

	data.mlx = mlx_init();

	data.win = mlx_new_window(data.mlx, (ft_strlen(game->map[0]) - 1) * width,
		height * count_line_tab(game->map), "so_long");

	kratos_img = mlx_xpm_file_to_image(data.mlx, "images/kratos.xpm", &width, &height);
	snow_img = mlx_xpm_file_to_image(data.mlx, "images/snow.xpm", &width, &height);
	door_img = mlx_xpm_file_to_image(data.mlx, "images/door.xpm", &width, &height);
	werewolf_img = mlx_xpm_file_to_image(data.mlx, "images/werewolf.xpm", &width, &height);
	wall_img = mlx_xpm_file_to_image(data.mlx, "images/rock.xpm", &width, &height);

	map = game->map;
	y = 0;
	i = 0;
	while (map[i])
	{
		x = 0;
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(data.mlx, data.win, wall_img, x, y);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(data.mlx, data.win, snow_img, x, y);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(data.mlx, data.win, kratos_img, x, y);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(data.mlx, data.win, door_img, x, y);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(data.mlx, data.win, werewolf_img, x, y);
			x += 64;
			j++;
		}
		i++;
		y += 64;
	}

	mlx_hook(data.win, 2, 1L<<0, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);

	mlx_loop(data.mlx);
	clear_game(game);
	return (0);
}
