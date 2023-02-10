/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:13:22 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/10 10:47:26 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void verif_die(t_prog *prog)
{
    if (prog->x == prog->pnj_position_x && prog->y == prog->pnj_position_y)
        lose();
}

int turn_right(t_prog *prog)
{
	prog->pnj_position_x += 1;
    
	
	mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_pnj_right, prog->pnj_position_x * 32, prog->pnj_position_y * 32);
    if (prog->map[prog->pnj_position_y][prog->pnj_position_x - 1] == 'F')
        mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_floor2, (prog->pnj_position_x - 1) * 32, prog->pnj_position_y * 32);
    else
        mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_floor, (prog->pnj_position_x - 1) * 32, prog->pnj_position_y * 32);

	return (0);
}

int turn_left(t_prog *prog)
{
	prog->pnj_position_x -= 1;
	
	mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_pnj_left, prog->pnj_position_x * 32, prog->pnj_position_y * 32);
    if (prog->map[prog->pnj_position_y][prog->pnj_position_x + 1] == 'F')
        mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_floor2, (prog->pnj_position_x + 1) * 32, prog->pnj_position_y * 32);
    else
        mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_floor, (prog->pnj_position_x + 1) * 32, prog->pnj_position_y * 32);

	return (0);
}

int	ft_update (t_prog *prog)
{
	static int	frame;
    static int buff;

	frame++;
    if (!prog->map[prog->pnj_position_y][prog->pnj_position_x])
        return(0);
    if (prog->map[prog->pnj_position_y][prog->pnj_position_x + 1] == '1')
        buff = 1;
    if (prog->map[prog->pnj_position_y][prog->pnj_position_x - 1] == '1')
        buff = 0;
    if (buff == 0 && frame >= ANIMATION_FRAMES)
    {
        turn_right(prog);
        frame = 0;
    }  
    else if(buff == 1 && frame >= ANIMATION_FRAMES)
    {
        turn_left(prog);
        frame = 0;
    }
    ft_anim_collectible(prog);
    ft_anim_watter(prog);
    verif_die(prog);
    return(0);
}