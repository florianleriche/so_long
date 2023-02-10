/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:28:56 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/07 20:53:51 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int ft_input(int key, t_prog *prog)
{
	verif_exit(prog);
	if (key == 2)
		move_right(prog);
	if (key == 0)
		move_left(prog);
	if (key == 13)
		move_up(prog);
	if (key == 1)
		move_down(prog);
	if (key == 53)
		exit(1);
	verif_end(prog);
	return (0);
}