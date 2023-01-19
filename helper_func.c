/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 09:08:50 by mel-yous          #+#    #+#             */
/*   Updated: 2023/01/18 19:31:47 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_player_pos(const char **map, char xy)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' && xy == 'x')
				return (j);
			else if (map[i][j] == 'P' && xy == 'y')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_search_tab(const char **tab, char c)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_tab_size(const char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_show_error(const char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd((char *)msg, 2);
	exit(1);
}

void	ft_struct_initializer(t_gameinfo *g_data)
{
	int	wh;

	wh = 64;
	g_data->map_w = ft_strlen_pro(g_data->map[0], '\n') * 64;
	g_data->map_h = ft_tab_size((const char **)g_data->map) * 64;
	g_data->wh = wh;
	g_data->mlx_p = mlx_init();
	if (!g_data->mlx_p)
		ft_show_error("mlx_init function fails!");
	g_data->mlx_w = ft_new_window(g_data);
	g_data->player_side = 'L';
	g_data->nb_collec = ft_count_collect((const char **)g_data->map);
	g_data->px = ft_player_pos((const char **)g_data->map, 'x');
	g_data->py = ft_player_pos((const char **)g_data->map, 'y');
	g_data->moves_counter = 0;
	ft_load_images(g_data);
}
