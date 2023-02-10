/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:29:09 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/08 21:07:53 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_player_position(t_data *dta, t_prog *prog)
{
	int	i;
	int	i2;

	i = 0;
	while (i != dta->map_y)
	{
		i2 = 0;
		while (i2 != dta->map_x)
		{
			if (dta->map[i][i2] == 'P')
			{
				prog->y = i;
				prog->x = i2;
				dta->p_y = i;
				dta->p_x = i2;
			}
			i2++;
		}
		i++;
	}
}

void	init_exit_position(t_data *dta, t_prog *prog)
{
	int	i;
	int	i2;

	i = 0;
	while (i != dta->map_y)
	{
		i2 = 0;
		while (i2 != dta->map_x)
		{
			if (dta->map[i][i2] == 'E')
			{
				prog->exit_position_y = i;
				prog->exit_position_x = i2;
				dta->p_y = i;
				dta->p_x = i2;
			}
			i2++;
		}
		i++;
	}
}


void	player_init(t_data *dta, t_prog *prog)
{
	init_player_position(dta, prog);
	init_exit_position(dta, prog);
}
