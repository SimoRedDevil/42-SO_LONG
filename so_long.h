/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:40:52 by mel-yous          #+#    #+#             */
/*   Updated: 2023/02/02 18:49:22 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# include <mlx.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

# define KEYPRESS 2
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_RIGHT 124
# define KEY_ARROW_DOWN 125
# define KEY_ARROW_UP 126

# define CO "textures/collec.xpm"
# define EX "textures/exit.xpm"
# define PL "textures/p_left.xpm"
# define PR "textures/p_right.xpm"
# define SP "textures/space.xpm"
# define WL "textures/wall.xpm"
# define OP "textures/opendoor.xpm"
# define T "so_long"

typedef struct s_gameinfo
{
	char	**map;
	int		map_w;
	int		map_h;
	int		wh;

	void	*mlx_p;
	void	*mlx_w;

	void	*wall;
	void	*space;
	void	*player;
	void	*collec;
	void	*exit;

	int		px;
	int		py;
	char	player_side;
	int		moves_counter;
	int		nb_collec;
}	t_gameinfo;

int		ft_put_image(t_gameinfo *g_data, void *img, int x, int y);
void	*ft_xpm2image(void *mlx_p, char *xpm);
void	*ft_new_window(t_gameinfo *g_data);
char	**ft_read_map(const char *path);
int		ft_count_collect(const char **map);
void	ft_map_validator(const char **map);
void	ft_show_error(const char *msg);
void	ft_destory_images(t_gameinfo *g_data);
void	ft_load_images(t_gameinfo *g_data);
void	ft_struct_initializer(t_gameinfo *g_data);
int		ft_search_tab(const char **tab, char c);
int		ft_tab_size(const char **tab);
void	ft_draw_characters(t_gameinfo *g_data);
void	ft_move_player(int keycode, t_gameinfo *g_data);
void	ft_collect(t_gameinfo *g_data);
void	ft_finish_game(t_gameinfo *g_data);
void	ft_flood_fill(char **map, int x, int y);
void	ft_check_validpath(const char **map);
char	**ft_create_fakemap(const char **map);
int		*ft_choose_xy(const char **map);

#endif