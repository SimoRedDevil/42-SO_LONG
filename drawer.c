/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:01:14 by mel-yous          #+#    #+#             */
/*   Updated: 2023/01/15 22:02:49 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_characters(t_gameinfo *g_data)
{
	int	x;
	int	y;

	y = 0;
	while (g_data->map[y])
	{
		x = 0;
		while (g_data->map[y][x])
		{
			if (g_data->map[y][x] == '1')
				ft_put_image(g_data, g_data->wall, x * 64, y * 64);
			else if (g_data->map[y][x] == '0')
				ft_put_image(g_data, g_data->space, x * 64, y * 64);
			else if (g_data->map[y][x] == 'P')
				ft_put_image(g_data, g_data->player, x * 64, y * 64);
			else if (g_data->map[y][x] == 'C')
				ft_put_image(g_data, g_data->collec, x * 64, y * 64);
			else if (g_data->map[y][x] == 'E')
				ft_put_image(g_data, g_data->exit, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
