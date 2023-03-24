/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:53:01 by gyroh             #+#    #+#             */
/*   Updated: 2023/03/24 21:07:31 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_img
{
	void	*img;
	char	*path;
	int		h;
	int		w;
	int		count;
}			t_img;

typedef struct s_info
{
	char	*file_name;
	char	**board;
	char	*s;
	int		s_size;
	int		board_h;
	int		board_w;
	int		move_cnt;
	void	*mlx;
	void	*win;
	int		y;
	int		x;
	int		win_h;
	int		win_w;
	t_img	background;
	t_img	player;
	t_img	wall;
	t_img	exit;
	t_img	collectible;
}			t_info;

# define EMPTY '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define DESTROY_NOTIFY 17

# define ERROR_EXTENSION "Error\nReason : extension Should be .ber"
# define ERROR_FD "Error\nReason : invalid file descriptor"
# define ERROR_MAP_SIZE "Error\nReason : invalid map size"
# define ERROR_MALLOC "Error\nReason : malloc error"
# define ERROR_WALL "Error\nReason : outside board must be wall"
# define ERROR_RECTANGLE "Error\nReason : board is not rectangle"
# define ERROR_INVALID_CHAR "Error\nReason : invalid character in board"
# define ERROR_NO_PLAYER "Error\nReason : no player on the board"
# define ERROR_NO_EXIT "Error\nReason : no exit on the board"
# define ERROR_NO_COLLECTIBLE "Error\nReason : there is no collectible on the board"
# define ERROR_CANT_CLEAR "Error\nReason : cant clear"
# define ERROR_DUPLICATE_PLAYER "Error\nReason : Duplicate Player"
# define dERROR_DUPLICATE_EXIT ="Error\nReason : Duplicate Exit"

# define PATH_BACKGROUND "./image/background.xpm"
# define PATH_PLAYER "./image/player.xpm"
# define PATH_WALL "./image/wall.xpm"
# define PATH_EXIT "./image/exit.xpm"
# define PATH_COLLECTIBLE "./image/collectible.xpm"

void	exit_so_long(t_info *info, char *s);

void	init_info(t_info *info, char *file_name);
void	init_mlx(t_info *info);

void	validate_extension(t_info *info);
void	validate_wall(t_info *info);
void	validate_invalid_char(t_info *info);
void	validate_board_data(t_info *info);
void	validate_clear(t_info *info);
void	check_table(char **table, t_info *info);
void	flow(char **table, t_info *info, int i, int j);
char	**ft_freeall(char **list);
char	*ft_strndup(const char *s, int n);

void	print_init_image(t_info *info);
void	print_player(t_info *info, int b_x, int b_y);

void	create_board(t_info *info);

void	set_board_data(t_info *info, const char c, int y, int x);
void	print_board(t_info *info);

int		key_hook(int key, t_info *info);
int		mouse_hook(t_info *info);

# define BUFFER_SIZE 1000000
#endif
