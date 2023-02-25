/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:34:09 by gyroh             #+#    #+#             */
/*   Updated: 2023/02/25 15:34:19 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	set_board_data(t_info *info, const char c, int y, int x)
{
	if (c == PLAYER)
	{
		info->player.count++;
		info->y = y;
		info->x = x;
	}
	else if (c == COLLECTIBLE)
		info->collectible.count++;
	else if (c == EXIT)
		info->exit.count++;
}

void	print_board(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->board_h)
	{
		j = -1;
		while (++j < info->board_w)
			write(1, &info->board[i][j], 1);
		write(1, "\n", 1);
	}
}
