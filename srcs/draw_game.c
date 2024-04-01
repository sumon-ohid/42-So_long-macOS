/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 06:41:27 by msumon            #+#    #+#             */
/*   Updated: 2023/11/29 08:38:58 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_resources(t_data *data)
{
	data->wall_img = load_image(data->mlx, data->wall_path);
	data->bg_img = load_image(data->mlx, data->bg_path);
	data->coin_img = load_image(data->mlx, data->coin_path);
	data->player_img = load_image(data->mlx, data->player_path);
	data->exit_img = load_image(data->mlx, data->exit_path);
	if (!data->wall_img.img || !data->bg_img.img || !data->coin_img.img
		|| !data->player_img.img || !data->exit_img.img)
	{
		print_error_and_exit("Failed to load textures");
	}
}

t_img	load_image(void *mlx, char *file)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx, file, &img.width, &img.height);
	if (img.img == NULL)
	{
		print_error_and_exit("Error loading texture");
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	return (img);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		close_window(data);
	}
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
	{
		do_the_move(keycode, data);
	}
	return (0);
}
