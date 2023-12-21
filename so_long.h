#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <fcntl.h>
# define BUFFER_SIZE 100

// Structure for item position on map
typedef struct s_place
{
	size_t			x;
	size_t			y;
	struct s_place	*next;
}					t_place;

// Structure for game components
typedef struct s_game
{
	char		**map;
	t_place		*perso;
	t_place		*exit;
	t_place		*item;
	t_place		*size;
}					t_game;

/* Fonctions to check errors
- error.c */
int		check_error(int argc, char **argv, t_game *game);

/* Fonctions to help initialisate the map
- get_next_line.c
- game_init.c */
char	*get_next_line(int fd);
t_game	*game_init(char *param);
char	**extract_map(char *map);

/* Useful fonctions for check error and so_long
- so_long_utils.c*/
void	clear_tab(char **tab);
size_t	count_line_tab(char **tab);
int 	count_item(char **map, char c);

/* Useful fonction for list management
- list_utils.c */
void	clear_game(t_game *game);
void	clear_list(t_place **itemlist);
void	add_place(t_place **itemlist, t_place *newitem);
t_place	*newplace(int x, int y);

#endif