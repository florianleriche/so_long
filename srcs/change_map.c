/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:04:11 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/07 14:12:20 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	change_map(t_data *dta, t_prog *prog)
{
	int	i;
	int	i2;
    int i3;
    
	i = 0;
    i3 = 0;
	while (i != dta->map_y)
	{
		i2 = 0;
		while (i2 != dta->map_x)
		{
			if (prog->map[i][i2] == '0' && i3 > 3)
			{
                prog->map[i][i2] = 'F';
                i3 = 1;
            }
            i3++;
            i2++;
        }
        i++;
    }
}