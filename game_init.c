#include "so_long.h"

void	init_place(t_place **itemlist, t_game **game, char **map);
char	**extract_map(char *map);
int		count_lines(char *map);
t_place	*init_size(char **map);

t_game	*game_init(char *param)
{
	t_game	*game;
	t_place	*itemlist;

	itemlist = NULL;
	game = (t_game *)malloc(sizeof(*game));
	if (!game)
		return (NULL);
	game->map = extract_map(param); 
	init_place(&itemlist, &game, game->map);
	game->item = itemlist;
	game->size = init_size(game->map);
	return (game);
}

char	**extract_map(char *map)
{
	char	 **extract;
	int		line_nb;
	int		i;
	int		fd;
	char	*line;

	line_nb = count_lines(map);
	extract = (char **)malloc((line_nb + 1) * sizeof(char *));
	fd = open(map, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		extract[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(fd);
	extract[i] = 0;
	return (extract);
}

int	count_lines(char *map)
{
	int		fd;
	int		line_nb;
	char	*line;

	fd = open(map, O_RDONLY);
	line_nb = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		line_nb++;
		free(line);
	}
	close(fd);
	return (line_nb);
}

void	init_place(t_place **itemlist, t_game **game, char **map)
{
	size_t	y;
	size_t	x;
	t_place *item;

	y = 0;
	item = NULL;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				(*game)->perso = newplace(x, y);
			else if (map[y][x] == 'E')
				(*game)->exit = newplace(x, y);
			else if (map[y][x] == 'C')
			{
				item = newplace(x, y);
				add_place(itemlist, item);
			}
			x++;
		}
		y++;
	}
}

t_place	*init_size(char **map)
{
	size_t	y;
	size_t	x;
	t_place *size;

	x = ft_strlen(*map) - 3;
	y = count_line_tab(map) - 2;
	size = newplace(x, y);
	return (size);
}
