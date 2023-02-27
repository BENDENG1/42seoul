/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:50:09 by gyroh             #+#    #+#             */
/*   Updated: 2023/02/27 19:48:01 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

static void	free_struct(t_info *info)
{
	int	idx;

	if (info->board == NULL)
		return ;
	idx = 0;
	while (idx < info->board_h)
	{
		if (info->board[idx])
			free(info->board[idx]);
		info->board[idx++] = NULL;
	}
	if (info->board)
	{
		free(info->board);
		info->board = NULL;
	}
}

static void	destroy_image(t_info *info)
{
	if (info->background.img != NULL)
		mlx_destroy_image(info->mlx, info->background.img);
	if (info->player.img != NULL)
		mlx_destroy_image(info->mlx, info->player.img);
	if (info->collectible.img != NULL)
		mlx_destroy_image(info->mlx, info->collectible.img);
	if (info->exit.img != NULL)
		mlx_destroy_image(info->mlx, info->exit.img);
	if (info->wall.img != NULL)
		mlx_destroy_image(info->mlx, info->wall.img);
	if (info->win != NULL)
		mlx_destroy_window(info->mlx, info->win);
}

void	exit_so_long(t_info *info, char *s)
{
	if (!info)
	{
		ft_putstr_fd(s, 1);
		exit(1);
	}
	if (info->s != NULL)
		free(info->s);
	if (info->board != NULL)
		free_struct(info);
	if (info->win != NULL)
		destroy_image(info);
	if (s != NULL)
		ft_putstr_fd(s, 1);
	exit(1);
}
