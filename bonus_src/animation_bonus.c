/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:16:37 by mel-yous          #+#    #+#             */
/*   Updated: 2023/01/17 23:53:07 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_frame1to4(t_gameinfo *g_data, int i, int j, int t)
{
	if (g_data->map[i][j] == 'D' && t == 1000)
	{
		mlx_destroy_image(g_data->mlx_p, g_data->devil);
		g_data->devil = ft_xpm2image(g_data->mlx_p, DV1);
		ft_put_image(g_data, g_data->devil, j * 64, i * 64);
	}
	else if (g_data->map[i][j] == 'D' && t == 1000 * 2)
	{
		mlx_destroy_image(g_data->mlx_p, g_data->devil);
		g_data->devil = ft_xpm2image(g_data->mlx_p, DV2);
		ft_put_image(g_data, g_data->devil, j * 64, i * 64);
	}
	else if (g_data->map[i][j] == 'D' && t == 1000 * 3)
	{
		mlx_destroy_image(g_data->mlx_p, g_data->devil);
		g_data->devil = ft_xpm2image(g_data->mlx_p, DV3);
		ft_put_image(g_data, g_data->devil, j * 64, i * 64);
	}
	else if (g_data->map[i][j] == 'D' && t == 1000 * 4)
	{
		mlx_destroy_image(g_data->mlx_p, g_data->devil);
		g_data->devil = ft_xpm2image(g_data->mlx_p, DV4);
		ft_put_image(g_data, g_data->devil, j * 64, i * 64);
	}
}

static void	ft_frame5to8(t_gameinfo *g_data, int i, int j, int t)
{
	if (g_data->map[i][j] == 'D' && t == 1000 * 5)
	{
		mlx_destroy_image(g_data->mlx_p, g_data->devil);
		g_data->devil = ft_xpm2image(g_data->mlx_p, DV5);
		ft_put_image(g_data, g_data->devil, j * 64, i * 64);
	}
	else if (g_data->map[i][j] == 'D' && t == 1000 * 6)
	{
		mlx_destroy_image(g_data->mlx_p, g_data->devil);
		g_data->devil = ft_xpm2image(g_data->mlx_p, DV6);
		ft_put_image(g_data, g_data->devil, j * 64, i * 64);
	}
	else if (g_data->map[i][j] == 'D' && t == 1000 * 7)
	{
		mlx_destroy_image(g_data->mlx_p, g_data->devil);
		g_data->devil = ft_xpm2image(g_data->mlx_p, DV7);
		ft_put_image(g_data, g_data->devil, j * 64, i * 64);
	}
	else if (g_data->map[i][j] == 'D' && t == 1000 * 8)
	{
		mlx_destroy_image(g_data->mlx_p, g_data->devil);
		g_data->devil = ft_xpm2image(g_data->mlx_p, DV8);
		ft_put_image(g_data, g_data->devil, j * 64, i * 64);
	}
}

static void	ft_frame9to11(t_gameinfo *g_data, int i, int j, int t)
{
	if (g_data->map[i][j] == 'D' && t == 1000 * 9)
	{
		mlx_destroy_image(g_data->mlx_p, g_data->devil);
		g_data->devil = ft_xpm2image(g_data->mlx_p, DV9);
		ft_put_image(g_data, g_data->devil, j * 64, i * 64);
	}
	else if (g_data->map[i][j] == 'D' && t == 1000 * 10)
	{
		mlx_destroy_image(g_data->mlx_p, g_data->devil);
		g_data->devil = ft_xpm2image(g_data->mlx_p, DV10);
		ft_put_image(g_data, g_data->devil, j * 64, i * 64);
	}
	else if (g_data->map[i][j] == 'D' && t == 1000 * 11)
	{
		mlx_destroy_image(g_data->mlx_p, g_data->devil);
		g_data->devil = ft_xpm2image(g_data->mlx_p, DV11);
		ft_put_image(g_data, g_data->devil, j * 64, i * 64);
	}
}

int	ft_render_enemy(t_gameinfo *g_data)
{
	static int	timer;
	int			i;
	int			j;

	i = 0;
	if (timer > 1000 * 11)
		timer = 0;
	while (g_data->map[i])
	{
		j = 0;
		while (g_data->map[i][j])
		{
			ft_frame1to4(g_data, i, j, timer);
			ft_frame5to8(g_data, i, j, timer);
			ft_frame9to11(g_data, i, j, timer);
			j++;
		}
		i++;
	}
	timer++;
	return (1);
}
