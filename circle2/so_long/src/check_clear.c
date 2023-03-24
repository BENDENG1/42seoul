/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:32:47 by gyroh             #+#    #+#             */
/*   Updated: 2023/03/24 16:45:10 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	validate_exit_reachable(char **table, t_info *info, int i, int j)
{
	if (i - 1 >= 0 && table[i - 1][j] == '2')
		return ;
	if (i + 1 < info->board_h && table[i + 1][j] == '2')
		return ;
	if (j - 1 >= 0 && table[i][j - 1] == '2')
		return ;
	if (j + 1 < info->board_w && table[i][j + 1] == '2')
		return ;
	ft_freeall(table);
	exit_so_long(info, ERROR_CANT_CLEAR);
}

void	flow(char **table, t_info *info, int i, int j)
{
	table[i][j] = '2';
	if (i - 1 >= 0 && table[i - 1][j] != WALL
		&& table[i - 1][j] != '2' && table[i - 1][j] != EXIT)
		flow(table, info, i - 1, j);
	if (i + 1 < info->board_h && table[i + 1][j] != WALL
		&& table[i + 1][j] != '2' && table[i + 1][j] != EXIT)
		flow(table, info, i + 1, j);
	if (j - 1 >= 0 && table[i][j - 1] != WALL
		&& table[i][j - 1] != '2' && table[i][j - 1] != EXIT)
		flow(table, info, i, j - 1);
	if (j + 1 < info->board_w && table[i][j + 1] != WALL
		&& table[i][j + 1] != '2' && table[i][j + 1] != EXIT)
		flow(table, info, i, j + 1);
}

void	check_table(char **table, t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->board_h)
	{
		j = -1;
		while (++j < info->board_w)
		{
			if (table[i][j] == COLLECTIBLE)
			{
				table = ft_freeall(table);
				exit_so_long(info, ERROR_CANT_CLEAR);
			}
			if (table[i][j] == EXIT)
			{
				validate_exit_reachable(table, info, i, j);
			}
		}
	}
}

void	validate_clear(t_info *info)
{
	char	**table;
	int		i;

	i = -1;
	table = (char **)malloc(sizeof(char *) * (info->board_h + 1));
	if (table == NULL)
		exit_so_long(info, ERROR_MALLOC);
	while (++i < info->board_h)
	{
		table[i] = ft_strndup(info->board[i], info->board_w);
		if (table[i] == NULL)
		{
			table = ft_freeall(table);
			exit_so_long(info, ERROR_MALLOC);
		}
	}
	table[i] = NULL;
	flow(table, info, info->y, info->x);
	check_table(table, info);
	ft_freeall(table);
}
