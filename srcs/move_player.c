/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:53:14 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/07 11:55:40 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	move_right(t_prog *prog)
{
	if (prog->map[prog->y][prog->x + 1] != '1')
	{
        if (prog->map[prog->y][prog->x + 1] == 'E')
            return (0);
        if (prog->map[prog->y][prog->x] == 'F')
            mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_floor2, prog->x * 32, prog->y *32);
        else
            mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_floor, prog->x * 32, prog->y *32);
        prog->x += 1;
        prog->nb_mouv += 1;
        ft_printf("Number of mouvements -> %d\n", prog->nb_mouv);
        if (prog->map[prog->y][prog->x] == 'C')
        {
            mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_floor, prog->x * 32, prog->y * 32);
            prog->map[prog->y][prog->x] = '0';
            prog->nb_collectible -= 1;
        }
        mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_player_right, prog->x * 32, prog->y *32);
	}
	return(0);
}

int	move_left(t_prog *prog)
{
	if (prog->map[prog->y][prog->x - 1] != '1')
	{
        if (prog->map[prog->y][prog->x - 1] == 'E')
            return (0);
        if (prog->map[prog->y][prog->x] == 'F')
            mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_floor2, prog->x * 32, prog->y *32);
        else
            mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_floor, prog->x * 32, prog->y *32);
		prog->x -= 1;
        prog->nb_mouv += 1;
        ft_printf("Number of mouvements -> %d\n", prog->nb_mouv);
        if (prog->map[prog->y][prog->x] == 'C')
        {
            mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_floor, prog->x * 32, prog->y * 32);
            prog->map[prog->y][prog->x] = '0';
            prog->nb_collectible -= 1;
        }
        mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_player_left, prog->x * 32, prog->y *32);
	}
	return(0);
}

int	move_up(t_prog *prog)
{
	if (prog->map[prog->y - 1][prog->x] != '1')
	{
        if (prog->map[prog->y - 1][prog->x] == 'E')
            return (0);
        if (prog->map[prog->y][prog->x] == 'F')
            mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_floor2, prog->x * 32, prog->y *32);
        else
            mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_floor, prog->x * 32, prog->y *32);
		prog->y -= 1;
        prog->nb_mouv += 1;
        ft_printf("Number of mouvements -> %d\n", prog->nb_mouv);
        if (prog->map[prog->y][prog->x] == 'C')
        {
            mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_floor, prog->x * 32, prog->y * 32);
            prog->map[prog->y][prog->x] = '0';
            prog->nb_collectible -= 1;
        }
        mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_player_up, prog->x * 32, prog->y *32);
	}
	return(0);
}

int	move_down(t_prog *prog)
{
	if (prog->map[prog->y + 1][prog->x] != '1')
	{
        if (prog->map[prog->y + 1][prog->x] == 'E')
            return (0);
        if (prog->map[prog->y][prog->x] == 'F')
            mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_floor2, prog->x * 32, prog->y *32);
        else
            mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_floor, prog->x * 32, prog->y *32);
		prog->y += 1;
        prog->nb_mouv += 1;
        ft_printf("Number of mouvements -> %d\n", prog->nb_mouv);
        if (prog->map[prog->y][prog->x] == 'C')
        {
            mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_floor, prog->x * 32, prog->y * 32);
            prog->map[prog->y][prog->x] = '0';
            prog->nb_collectible -= 1;
        }
        mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_player, prog->x * 32, prog->y *32);
	}
	return(0);
}

int verif_exit(t_prog *prog)
{
    (void)prog;
    if (prog->nb_collectible == 0)
    {
        mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_exit_open, prog->exit_position_x * 32, prog->exit_position_y * 32);
        prog->map[prog->exit_position_y][prog->exit_position_x] = 'O';
        return(0);
    }
    return(0);
}