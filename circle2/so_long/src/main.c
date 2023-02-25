/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:51:44 by gyroh             #+#    #+#             */
/*   Updated: 2023/02/25 15:51:47 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 2)
	{
		init_info(&info, argv[1]);
		validate_extension(&info);
		create_board(&info);
		print_board(&info);
		init_mlx(&info);
		print_init_image(&info);
		mlx_hook(info.win, DESTROY_NOTIFY, 0, mouse_hook, &info);
		mlx_key_hook(info.win, key_hook, &info);
		mlx_loop(info.mlx);
	}
	return (0);
}
