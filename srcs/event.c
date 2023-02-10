/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:09:16 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/08 21:05:25 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    lose()
{
    ft_printf("You LOSE\n");
    exit(1);
}

int verif_end(t_prog *prog)
{
    if (prog->map[prog->y][prog->x] == 'O')
    {
        ft_printf("You WIN\n");
        exit(1);
    }
    return(0);
}