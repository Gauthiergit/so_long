/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:48:31 by gpeyre            #+#    #+#             */
/*   Updated: 2024/01/15 09:42:22 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <fcntl.h>

# define BUFFER_SIZE 40
# define FLOOR_PATH "./still_img/floor.xpm"
# define EXITC_PATH "./still_img/exit_c.xpm"
# define EXITO_PATH "./still_img/exit_o.xpm"
# define ENY_PATH "./still_img/enemy.xpm"
# define WALL_PATH "./still_img/wall.xpm"
# define CHESTC_PATH "./still_img/chest_c.xpm"
# define CHESTO_PATH "./still_img/chest_o.xpm"

# define PF_PATH_1 "./player_anim/player_face_1.xpm"
# define PF_PATH_2 "./player_anim/player_face_2.xpm"
# define PF_PATH_3 "./player_anim/player_face_3.xpm"
# define PF_PATH_4 "./player_anim/player_face_4.xpm"

# define PB_PATH_1 "./player_anim/player_back_1.xpm"
# define PB_PATH_2 "./player_anim/player_back_2.xpm"
# define PB_PATH_3 "./player_anim/player_back_3.xpm"
# define PB_PATH_4 "./player_anim/player_back_4.xpm"

# define PR_PATH_1 "./player_anim/player_right_1.xpm"
# define PR_PATH_2 "./player_anim/player_right_2.xpm"
# define PR_PATH_3 "./player_anim/player_right_3.xpm"
# define PR_PATH_4 "./player_anim/player_right_4.xpm"

# define PL_PATH_1 "./player_anim/player_left_1.xpm"
# define PL_PATH_2 "./player_anim/player_left_2.xpm"
# define PL_PATH_3 "./player_anim/player_left_3.xpm"
# define PL_PATH_4 "./player_anim/player_left_4.xpm"

# define SF_PATH_1 "./strike_anim/strike_front_1.xpm"
# define SF_PATH_2 "./strike_anim/strike_front_2.xpm"
# define SF_PATH_3 "./strike_anim/strike_front_3.xpm"
# define SF_PATH_4 "./strike_anim/strike_front_4.xpm"

# define SB_PATH_1 "./strike_anim/strike_back_1.xpm"
# define SB_PATH_2 "./strike_anim/strike_back_2.xpm"
# define SB_PATH_3 "./strike_anim/strike_back_3.xpm"
# define SB_PATH_4 "./strike_anim/strike_back_4.xpm"

# define SR_PATH_1 "./strike_anim/strike_right_1.xpm"
# define SR_PATH_2 "./strike_anim/strike_right_2.xpm"
# define SR_PATH_3 "./strike_anim/strike_right_3.xpm"
# define SR_PATH_4 "./strike_anim/strike_right_4.xpm"

# define SL_PATH_1 "./strike_anim/strike_left_1.xpm"
# define SL_PATH_2 "./strike_anim/strike_left_2.xpm"
# define SL_PATH_3 "./strike_anim/strike_left_3.xpm"
# define SL_PATH_4 "./strike_anim/strike_left_4.xpm"

# define FLOOR 0
# define WALL 1
# define ENY 2
# define EXITC 3
# define EXITO 4
# define CHESTC 5
# define CHESTO 6
# define FRONT 'f'
# define BACK 'b'
# define RIGHT 'r'
# define LEFT 'l'

// Structure for item position on map
typedef struct s_place
{
	size_t			x;
	size_t			y;
	struct s_place	*next;
}					t_place;

// Structure for game content and useful for check errors
typedef struct s_game
{
	char		**map;
	t_place		*player;
	t_place		*exit;
	t_place		*chest;
	t_place		*size;
}					t_game;

// Structure for map elements
typedef struct s_cnt
{
	char	exit;
	char	floor;
	char	player;
	char	chest;
	char	enemy;
	char	wall;
	int		count_c;
	int		first_f;
	int		first_b;
	int		first_r;
	int		first_l;
}				t_cnt;

//Structure to manage animations
typedef struct s_anim
{
	void	**pf_anim;
	void	**pb_anim;
	void	**pr_anim;
	void	**pl_anim;
	void	**sf_anim;
	void	**sb_anim;
	void	**sr_anim;
	void	**sl_anim;
}				t_anim;

// Structure to manage easily all data of the game
typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	**img;
	t_anim	anims;
	int		count_mouv;
	t_game	game;
	t_cnt	content;
	int		width;
	int		height;
	int		anim_clock;
	int		cur_anim;
	char	direction;
	int		strike;
}				t_data;

/* Fonction to check errors
- error.c
- error_2.c */
int		check_error_map(char **argv, t_game *game);
void	check_error_file(int argc, char **argv);
int		is_valid_cara(char **map);

/* Fonctions to help initialisate the map
- get_next_line.c
- game_init.c */
char	*get_next_line(int fd);
void	game_init(t_game *game, char *param);
char	**extract_map(char *map);

/* Useful fonctions for check error and so_long
- so_long_utils.c*/
void	clear_tab(char **tab);
size_t	count_line_tab(char **tab);
int		count_item(char **map, char c);
void	clear_all_img(t_data *data);

/* Useful fonction for list management
- list_utils.c */
void	clear_game(t_game *game);
void	clear_list(t_place *itemlist);
void	add_place(t_place **itemlist, t_place *newitem);
t_place	*newplace(int x, int y);

/* Fonction to initialisate data
- data_init.c
- anim_init.c
- anim_init_2.c */
void	data_init(t_data *data);
void	**pf_init(void *mlx_ptr, int width, int height);
void	**pr_init(void *mlx_ptr, int width, int height);
void	**pb_init(void *mlx_ptr, int width, int height);
void	**pl_init(void *mlx_ptr, int width, int height);
void	**sf_init(void *mlx_ptr, int width, int height);
void	**sb_init(void *mlx_ptr, int width, int height);
void	**sr_init(void *mlx_ptr, int width, int height);
void	**sl_init(void *mlx_ptr, int width, int height);

/* Fonction to display the game and manage event
- game_display.c */
void	game_display(t_data *data);
int		close_window(t_data *data);
int		key_hook(int keycode, t_data *data);
void	print_texture(t_data *data, void *texture, int x, int y);

/* Foncton to display counter and kill
- game_display_2.c */
int		print_frame(t_data *data);
void	print_counter(t_data *data);
void	check_kill(t_data *data);

/* Fonction for animation
- game_display_3.c */
int		player_clock(t_data *data);

/* Fonction to move on game
- move.c */
void	move_top(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

#endif