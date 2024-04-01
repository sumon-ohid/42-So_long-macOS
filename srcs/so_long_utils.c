/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 06:40:10 by msumon            #+#    #+#             */
/*   Updated: 2023/11/29 08:40:52 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_event(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, close_window, data);
	mlx_loop(data->mlx);
	free_map(data->map);
	mlx_destroy_window(data->mlx, data->mlx_win);
}

void	print_error_and_exit(const char *error_message)
{
	ft_printf("Error\n%s\n", error_message);
	exit(EXIT_FAILURE);
}

int	height_count(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	so_long_welcome(void)
{
	ft_printf("\n");
	ft_printf(" █░█░█ █▀▀ █░░ █▀▀ █▀█ █▀▄▀█ █▀▀   ▀█▀ █▀█\n");
	ft_printf(" ▀▄▀▄▀ ██▄ █▄▄ █▄▄ █▄█ █░▀░█ ██▄   ░█░ █▄█\n");
	ft_printf("\n");
	ft_printf("███████╗ ██████╗     ██╗      ██████╗ ███╗   ██╗ ██████╗ \n");
	ft_printf("██╔════╝██╔═══██╗    ██║     ██╔═══██╗████╗  ██║██╔════╝ \n");
	ft_printf("███████╗██║   ██║    ██║     ██║   ██║██╔██╗ ██║██║  ███╗\n");
	ft_printf("╚════██║██║   ██║    ██║     ██║   ██║██║╚██╗██║██║   ██║\n");
	ft_printf("███████║╚██████╔╝    ███████╗╚██████╔╝██║ ╚████║╚██████╔╝\n");
	ft_printf("╚══════╝ ╚═════╝     ╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ \n");
	ft_printf("\n");
}

void	quit_game(t_data *data)
{
	int	moves;

	moves = data->moves;
	ft_printf("\n");
	ft_printf("██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗ ██████╗ ███╗   ██╗\n");
	ft_printf("╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ██║██╔═══██╗████╗  ██║\n");
	ft_printf(" ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ██║██║   ██║██╔██╗ ██║\n");
	ft_printf("  ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║██║   ██║██║╚██╗██║\n");
	ft_printf("   ██║   ╚██████╔╝╚██████╔╝    ╚███╔███╔╝╚██████╔╝██║ ╚████║\n");
	ft_printf("   ╚═╝    ╚═════╝  ╚═════╝      ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═══╝\n");
	ft_printf("\n");
	ft_printf("                 You used %d moves.\n", moves);
	close_window(data);
}
