/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:29:08 by mel-yous          #+#    #+#             */
/*   Updated: 2023/01/18 18:49:32 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_put_image(t_gameinfo *g_data, void *img, int x, int y)
{
	void	*mp;
	void	*wp;

	mp = g_data->mlx_p;
	wp = g_data->mlx_w;
	return (mlx_put_image_to_window(mp, wp, img, x, y));
}

void	*ft_xpm2image(void *mlx_p, char *xpm)
{
	int		wh;
	void	*ptr;

	wh = 64;
	ptr = mlx_xpm_file_to_image(mlx_p, xpm, &wh, &wh);
	if (!ptr)
		ft_show_error("mlx_xpm_file_to_image function fails!");
	return (ptr);
}

void	*ft_new_window(t_gameinfo *g_data)
{
	int		w;
	int		h;
	void	*ptr;

	w = g_data->map_w;
	h = g_data->map_h;
	ptr = mlx_new_window(g_data->mlx_p, w, h, T);
	if (!ptr)
		ft_show_error("mlx_new_window function fails!");
	return (ptr);
}
