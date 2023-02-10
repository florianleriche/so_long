/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_water.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:01:50 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/08 20:54:33 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_watter1(t_prog *prog)
{
	int	i;
	int	i2;

	i = 0;
	while (i != prog->map_y)
	{
		i2 = 0;
		while (i2 != prog->map_x)
		{
			if ((prog->map[i][i2] == '1' && i == 0) || (prog->map[i][i2] == '1' && i == prog->map_y - 1)
			|| (prog->map[i][i2] == '1' && i2 == prog->map_x - 1)|| (prog->map[i][i2] == '1' && i2 == 0))
				mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_wall2, i2 * 32, i * 32);
			i2++;
		}
		i++;
	}
}

void	put_watter2(t_prog *prog)
{
	int	i;
	int	i2;

	i = 0;
	while (i != prog->map_y)
	{
		i2 = 0;
		while (i2 != prog->map_x)
		{
			if ((prog->map[i][i2] == '1' && i == 0) || (prog->map[i][i2] == '1' && i == prog->map_y - 1)
			|| (prog->map[i][i2] == '1' && i2 == prog->map_x - 1)|| (prog->map[i][i2] == '1' && i2 == 0))
				mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_wall3, i2 * 32, i * 32);
			i2++;
		}
		i++;
	}
}

int	ft_anim_watter(t_prog *prog)
{
    static int	frame;

	frame++;
	if (frame == 3000)
		put_watter1(prog);
	else if (frame >= 3000 * 2)
	{
		put_watter2(prog);
		frame = 0;
	}
    return (0);
}