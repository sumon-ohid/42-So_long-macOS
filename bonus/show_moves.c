/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:11:55 by msumon            #+#    #+#             */
/*   Updated: 2023/11/29 16:16:37 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	bonus_draw_text(t_data *data)
{
	char	*moves;
	char	*text;
	int		i;
	int		j;

	i = 0;
	moves = ft_itoa(data->moves);
	text = ft_strjoin("MOVES : ", moves);
	while (i < 20)
	{
		j = 0;
		while (j < 100)
		{
			mlx_pixel_put(data->mlx, data->mlx_win, j + 4, i + 7, 0x808080);
			j++;
		}
		i++;
	}
	mlx_string_put(data->mlx, data->mlx_win, 10, 20, 0x000000, text);
	free(moves);
	free(text);
}
