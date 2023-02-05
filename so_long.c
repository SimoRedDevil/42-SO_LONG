/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:15:19 by mel-yous          #+#    #+#             */
/*   Updated: 2023/02/03 14:26:23 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_ber_checker(const char *map_path)
{
	int	i;

	i = 0;
	while (map_path[i])
	{
		if (map_path[i] == '.' && map_path[i - 1] && map_path[i + 1] == 'b'
			&& map_path[i + 2] == 'e' && map_path[i + 3] == 'r'
			&& map_path[i + 4] == '\0')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_close_game(t_gameinfo *g_data)
{
	mlx_destroy_window(g_data->mlx_p, g_data->mlx_w);
	exit(0);
}

static int	ft_hook_handler(int keycode, t_gameinfo *g_data)
{
	if (keycode == 53)
		ft_close_game(g_data);
	if (keycode == KEY_A || keycode == KEY_ARROW_LEFT
		|| keycode == KEY_D || keycode == KEY_ARROW_RIGHT
		|| keycode == KEY_S || keycode == KEY_ARROW_DOWN
		|| keycode == KEY_W || keycode == KEY_ARROW_UP)
	{
		ft_destory_images(g_data);
		ft_move_player(keycode, g_data);
		ft_load_images(g_data);
		ft_draw_characters(g_data);
	}
	return (1);
}

static void	ft_run_solong(const char *map_path)
{
	char		**map;
	char		**fake_map;
	t_gameinfo	g_data;
	int			*xy;

	if (ft_ber_checker(map_path) == 0)
		ft_show_error("The map extension is not valid!");
	map = ft_read_map(map_path);
	ft_map_validator((const char **)map);
	fake_map = ft_create_fakemap((const char **)map);
	xy = ft_choose_xy((const char **)fake_map);
	ft_flood_fill(fake_map, xy[0], xy[1]);
	ft_check_validpath((const char **)fake_map);
	g_data.map = map;
	ft_struct_initializer(&g_data);
	ft_draw_characters(&g_data);
	mlx_hook(g_data.mlx_w, KEYPRESS, 0, ft_hook_handler, &g_data);
	mlx_hook(g_data.mlx_w, 17, 0, ft_close_game, &g_data);
	mlx_loop(g_data.mlx_p);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_run_solong(argv[1]);
	else
		ft_show_error("The number of args is not valid!");
}
