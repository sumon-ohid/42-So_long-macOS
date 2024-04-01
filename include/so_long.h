/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:12:47 by msumon            #+#    #+#             */
/*   Updated: 2024/04/01 15:59:16 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>

# define CELL_SIZE 32
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	int		total_coins;
	int		coins_collected;
	int		moves;
	int		map_height;
	int		map_width;
	int		exitcheck;
	char	**map;
	char	*map_path;
	char	*wall_path;
	char	*bg_path;
	char	*coin_path;
	char	*player_path;
	char	*exit_path;
	t_img	bg_img;
	t_img	wall_img;
	t_img	coin_img;
	t_img	player_img;
	t_img	exit_img;
}			t_data;

void		draw_elements(t_data *data);
char		**load_map(char *map_path);
void		free_map(char **map);
void		do_the_move(int keycode, t_data *data);
void		get_current_position(char **map, int *x, int *y);
t_img		load_image(void *mlx, char *file);
int			key_hook(int keycode, t_data *data);
void		quit_game(t_data *data);
void		draw_game(t_data *data);
void		set_event(t_data *data);
void		load_resources(t_data *data);
void		print_error_and_exit(const char *error_message);
int			height_count(char **map);
void		so_long_welcome(void);
int			ft_strlen_sl(char *str);
void		initialize_mlx(t_data *data);
int			close_window(t_data *data);
int			map_height(char *str);
int			map_width(char *map_path);
int			is_valid_map(t_data *data);
int			is_rectangular(t_data *data);
int			has_wall_around(t_data *data);
int			has_valid_char(t_data *data);
int			valid_path_check(t_data *data);
void		bonus_draw_text(t_data *data);
int			count_coins(t_data *data);

#endif
