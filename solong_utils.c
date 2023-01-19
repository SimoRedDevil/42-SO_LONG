/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:45:36 by mel-yous          #+#    #+#             */
/*   Updated: 2023/01/18 20:14:59 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_collect(const char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_destory_images(t_gameinfo *g_data)
{
	mlx_destroy_image(g_data->mlx_p, g_data->wall);
	mlx_destroy_image(g_data->mlx_p, g_data->space);
	mlx_destroy_image(g_data->mlx_p, g_data->player);
	mlx_destroy_image(g_data->mlx_p, g_data->collec);
	mlx_destroy_image(g_data->mlx_p, g_data->exit);
}

void	ft_load_images(t_gameinfo *g_data)
{
	g_data->wall = ft_xpm2image(g_data->mlx_p, WL);
	g_data->space = ft_xpm2image(g_data->mlx_p, SP);
	if (g_data->player_side == 'L')
		g_data->player = ft_xpm2image(g_data->mlx_p, PL);
	else
		g_data->player = ft_xpm2image(g_data->mlx_p, PR);
	g_data->collec = ft_xpm2image(g_data->mlx_p, CO);
	if (g_data->nb_collec == 0)
		g_data->exit = ft_xpm2image(g_data->mlx_p, OP);
	else if (g_data->nb_collec > 0)
		g_data->exit = ft_xpm2image(g_data->mlx_p, EX);
}

void	ft_collect(t_gameinfo *g_data)
{
	g_data->nb_collec--;
	ft_printf("Move Number: %d\n", ++g_data->moves_counter);
	ft_printf("Collected!\n");
}

void	ft_finish_game(t_gameinfo *g_data)
{
	if (g_data->nb_collec == 0)
	{
		mlx_destroy_window(g_data->mlx_p, g_data->mlx_w);
		ft_printf("The game is finished, you win!");
		exit(0);
	}
}
