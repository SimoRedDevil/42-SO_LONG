/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:58:11 by mel-yous          #+#    #+#             */
/*   Updated: 2023/01/16 14:59:20 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_moveleft(t_gameinfo *g_data)
{
	g_data->player_side = 'L';
	if (g_data->map[g_data->py][g_data->px - 1] == '0')
	{
		g_data->map[g_data->py][g_data->px] = '0';
		g_data->map[g_data->py][--g_data->px] = 'P';
		g_data->moves_counter++;
	}
	else if (g_data->map[g_data->py][g_data->px - 1] == 'C')
	{
		g_data->map[g_data->py][g_data->px] = '0';
		g_data->map[g_data->py][--g_data->px] = 'P';
		ft_collect(g_data);
	}
	else if (g_data->map[g_data->py][g_data->px - 1] == 'D')
	{
		g_data->attacked = 1;
		ft_finish_game(g_data);
	}
	else if (g_data->map[g_data->py][g_data->px - 1] == 'E')
		ft_finish_game(g_data);
}

static void	ft_moveright(t_gameinfo *g_data)
{
	g_data->player_side = 'R';
	if (g_data->map[g_data->py][g_data->px + 1] == '0')
	{
		g_data->map[g_data->py][g_data->px] = '0';
		g_data->map[g_data->py][++g_data->px] = 'P';
		g_data->moves_counter++;
	}
	else if (g_data->map[g_data->py][g_data->px + 1] == 'C')
	{
		g_data->map[g_data->py][g_data->px] = '0';
		g_data->map[g_data->py][++g_data->px] = 'P';
		ft_collect(g_data);
	}
	else if (g_data->map[g_data->py][g_data->px + 1] == 'D')
	{
		g_data->attacked = 1;
		ft_finish_game(g_data);
	}
	else if (g_data->map[g_data->py][g_data->px + 1] == 'E')
		ft_finish_game(g_data);
}

static void	ft_movedown(t_gameinfo *g_data)
{
	if (g_data->map[g_data->py + 1][g_data->px] == '0')
	{
		g_data->map[g_data->py][g_data->px] = '0';
		g_data->map[++g_data->py][g_data->px] = 'P';
		g_data->moves_counter++;
	}
	else if (g_data->map[g_data->py + 1][g_data->px] == 'C')
	{
		g_data->map[g_data->py][g_data->px] = '0';
		g_data->map[++g_data->py][g_data->px] = 'P';
		ft_collect(g_data);
	}
	else if (g_data->map[g_data->py + 1][g_data->px] == 'D')
	{
		g_data->attacked = 1;
		ft_finish_game(g_data);
	}
	else if (g_data->map[g_data->py + 1][g_data->px] == 'E')
		ft_finish_game(g_data);
}

static void	ft_moveup(t_gameinfo *g_data)
{
	if (g_data->map[g_data->py - 1][g_data->px] == '0')
	{
		g_data->map[g_data->py][g_data->px] = '0';
		g_data->map[--g_data->py][g_data->px] = 'P';
		g_data->moves_counter++;
	}
	else if (g_data->map[g_data->py - 1][g_data->px] == 'C')
	{
		g_data->map[g_data->py][g_data->px] = '0';
		g_data->map[--g_data->py][g_data->px] = 'P';
		ft_collect(g_data);
	}
	else if (g_data->map[g_data->py - 1][g_data->px] == 'D')
	{
		g_data->attacked = 1;
		ft_finish_game(g_data);
	}
	else if (g_data->map[g_data->py - 1][g_data->px] == 'E')
		ft_finish_game(g_data);
}

void	ft_move_player(int keycode, t_gameinfo *g_data)
{
	if (keycode == KEY_A || keycode == KEY_ARROW_LEFT)
		ft_moveleft(g_data);
	else if (keycode == KEY_D || keycode == KEY_ARROW_RIGHT)
		ft_moveright(g_data);
	else if (keycode == KEY_S || keycode == KEY_ARROW_DOWN)
		ft_movedown(g_data);
	else if (keycode == KEY_W || keycode == KEY_ARROW_UP)
		ft_moveup(g_data);
}
