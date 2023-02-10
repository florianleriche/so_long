/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_collectible.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:27:13 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/08 20:56:00 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_up(t_prog *prog)
{
	int	i;
	int	i2;

	i = 0;
	while (i != prog->map_y)
	{
		i2 = 0;
		while (i2 != prog->map_x)
		{
			if (prog->map[i][i2] == 'C')
			{
                mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_floor, i2 * 32, i * 32);
				mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_collectible, i2 * 32, i * 32 - 5);
			}
			i2++;
		}
		i++;
	}
}

void	put_down(t_prog *prog)
{
	int	i;
	int	i2;

	i = 0;
	while (i != prog->map_y)
	{
		i2 = 0;
		while (i2 != prog->map_x)
		{
			if (prog->map[i][i2] == 'C')
			{
                mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_floor, i2 * 32, i * 32);
				mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_collectible, i2 * 32, i * 32);
			}
			i2++;
		}
		i++;
	}
}

int	ft_anim_collectible(t_prog *prog)
{
    static int	frame;

	frame++;
	if (frame == 6000)
		put_down(prog);
	else if (frame >= 6000 * 2)
	{
		put_up(prog);
		frame = 0;
	}
    return (0);
}