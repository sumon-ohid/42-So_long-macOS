/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:19:18 by msumon            #+#    #+#             */
/*   Updated: 2024/03/31 21:54:15 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(t_data *data)
{
	free_map(data->map);
	mlx_destroy_image(data->mlx, data->exit_img.img);
	mlx_destroy_image(data->mlx, data->bg_img.img);
	mlx_destroy_image(data->mlx, data->coin_img.img);
	mlx_destroy_image(data->mlx, data->player_img.img);
	mlx_destroy_image(data->mlx, data->wall_img.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	//mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_printf("Window closed. Exiting...\n");
	exit(0);
	return (0);
}

void	initialize_mlx(t_data *data)
{
	int	win_height;
	int	win_width;

	win_height = data->map_height * CELL_SIZE;
	win_width = data->map_width * CELL_SIZE;
	if (win_height <= 1080 && win_width <= 1920)
	{
		data->mlx_win = mlx_new_window(data->mlx, win_width, win_height,
				"So_long");
		if (!data->mlx_win)
		{
			print_error_and_exit("Failed to create window");
		}
	}
	else
	{
		//mlx_destroy_display(data->mlx);
		free(data->mlx);
		free_map(data->map);
		print_error_and_exit("Map is bigger than Screen size.");
	}
}

void	game_start(t_data *data)
{
	if (is_valid_map(data) == 1)
	{
		initialize_mlx(data);
		load_resources(data);
		draw_game(data);
		set_event(data);
	}
	else
	{
		//mlx_destroy_display(data->mlx);
		free(data->mlx);
		free_map(data->map);
		print_error_and_exit("Map is not valid !!");
	}
}

void	value_assign(t_data *data)
{
	data->moves = 0;
	data->wall_path = "./textures/wall.xpm";
	data->bg_path = "./textures/bg1.xpm";
	data->coin_path = "./textures/coin.xpm";
	data->player_path = "./textures/mushroom.xpm";
	data->exit_path = "./textures/exit.xpm";
	data->map_height = map_height(data->map_path);
	data->map_width = map_width(data->map_path);
}

int	main(int argc, char **argv)
{
	t_data		data;
	size_t		map_name_length;
	const char	*ber_ext = ".ber";

	if (argc != 2)
		print_error_and_exit("Invalid Argument");
	map_name_length = ft_strlen(argv[1]);
	if (map_name_length < 4 || ft_strncmp(argv[1] + map_name_length - 4,
			ber_ext, 4) != 0)
		print_error_and_exit("Map name must end with '.ber'");
	data.map_path = argv[1];
	value_assign(&data);
	data.map = load_map(data.map_path);
	if (!(data.map))
	{
		free_map(data.map);
		print_error_and_exit("Invalid map");
	}
	data.mlx = mlx_init();
	if (!data.mlx)
		print_error_and_exit("Failed to initialize mlx");
	game_start(&data);
	return (0);
}
