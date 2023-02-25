/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:51:23 by gyroh             #+#    #+#             */
/*   Updated: 2023/02/25 15:51:27 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "so_long.h"
#include "mlx.h"

static void	set_image(void *mlx, char *path, t_img *image)
{
	image->img = mlx_xpm_file_to_image(mlx, path, &image->w, &image->h);
}

void	init_mlx(t_info *info)
{
	info->mlx = mlx_init();
	set_image(info->mlx, PATH_BACKGROUND, &info->background);
	set_image(info->mlx, PATH_PLAYER, &info->player);
	set_image(info->mlx, PATH_WALL, &info->wall);
	set_image(info->mlx, PATH_EXIT, &info->exit);
	set_image(info->mlx, PATH_COLLECTIBLE, &info->collectible);
	info->win_w = info->board_w * info->background.w;
	info->win_h = info->board_h * info->background.h;
}

void	init_info(t_info *info, char *file_name)
{
	info->file_name = file_name;
	info->board = NULL;
	info->s = NULL;
	info->board_h = 0;
	info->board_w = 0;
	info->collectible.count = 0;
	info->exit.count = 0;
	info->player.count = 0;
	info->move_cnt = 0;
	info->y = -1;
	info->x = -1;
	info->mlx = NULL;
	info->win = NULL;
}
