/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:25:49 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/10 11:01:00 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void	put_map(t_data *dta, t_prog *prog, char c_map)
{
	int	i;
	int	i2;

	i = 0;
	while (i != dta->map_y)
	{
		i2 = 0;
		while (i2 != dta->map_x)
		{
			if (prog->map[i][i2] == c_map)
				mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_ptr, i2 * 32, i * 32);
			i2++;
		}
		i++;
	}
}

void	put_wall(t_data *dta, t_prog *prog, char c_map)
{
	int	i;
	int	i2;

	i = 0;
	while (i != dta->map_y)
	{
		i2 = 0;
		while (i2 != dta->map_x)
		{
			if ((prog->map[i][i2] == c_map && i == 0) || (prog->map[i][i2] == c_map && i == dta->map_y - 1)
				|| (prog->map[i][i2] == c_map && i2 == dta->map_x - 1)|| (prog->map[i][i2] == c_map && i2 == 0))
				mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_ptr, i2 * 32, i * 32);
			i2++;
		}
		i++;
	}
}

void	init_img(t_data *dta, t_prog *prog, char *file, char c)
{
	prog->img_ptr = mlx_xpm_file_to_image(prog->mlx_ptr, file, &prog->img_width, &prog->img_height);
	put_map(dta, prog, c);
}

void	init_wall(t_data *dta, t_prog *prog, char *file, char c)
{
	prog->img_ptr = mlx_xpm_file_to_image(prog->mlx_ptr, file, &prog->img_width, &prog->img_height);
	put_wall(dta, prog, c);
}

void	render(t_data *dta, t_prog *prog)
{
	init_img(dta, prog, "sprites/floor.xpm", '0');
	init_img(dta, prog, "sprites/floor2.xpm", 'F');
	init_img(dta, prog, "sprites/floor.xpm", 'C');
	init_img(dta, prog, "sprites/floor.xpm", 'E');
	init_img(dta, prog, "sprites/exit_close.xpm", 'E');
	init_img(dta, prog, "sprites/floor.xpm", 'P');
	init_img(dta, prog, "sprites/floor.xpm", '1');
	init_img(dta, prog, "sprites/wall.xpm", '1');
	init_img(dta, prog, "sprites/collectible.xpm", 'C');
	init_img(dta, prog, "sprites/player_down.xpm", 'P');
	init_wall(dta, prog, "sprites/wall2.xpm", '1');
	mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_pnj, prog->pnj_position_x * 32, prog->pnj_position_y * 32);
}