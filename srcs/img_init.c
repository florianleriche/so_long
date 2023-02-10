/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:20:26 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/08 19:05:22 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    img_init(t_prog *prog)
{
    prog->img_floor = mlx_xpm_file_to_image(prog->mlx_ptr, "sprites/floor.xpm", &prog->img_width, &prog->img_height);
    prog->img_floor2 = mlx_xpm_file_to_image(prog->mlx_ptr, "sprites/floor2.xpm", &prog->img_width, &prog->img_height);
    prog->img_player = mlx_xpm_file_to_image(prog->mlx_ptr, "sprites/player_down.xpm", &prog->img_width, &prog->img_height);
    prog->img_wall = mlx_xpm_file_to_image(prog->mlx_ptr, "sprites/wall.xpm", &prog->img_width, &prog->img_height);
    prog->img_collectible = mlx_xpm_file_to_image(prog->mlx_ptr, "sprites/collectible.xpm", &prog->img_width, &prog->img_height);
    prog->img_player_up = mlx_xpm_file_to_image(prog->mlx_ptr, "sprites/player_up.xpm", &prog->img_width, &prog->img_height);
    prog->img_player_right = mlx_xpm_file_to_image(prog->mlx_ptr, "sprites/player_right.xpm", &prog->img_width, &prog->img_height);
    prog->img_player_left = mlx_xpm_file_to_image(prog->mlx_ptr, "sprites/player_left.xpm", &prog->img_width, &prog->img_height);
    prog->img_exit_open = mlx_xpm_file_to_image(prog->mlx_ptr, "sprites/exit_open.xpm", &prog->img_width, &prog->img_height);
    prog->img_pnj_left = mlx_xpm_file_to_image(prog->mlx_ptr, "sprites/pnj_left.xpm", &prog->img_width, &prog->img_height);
    prog->img_pnj_right = mlx_xpm_file_to_image(prog->mlx_ptr, "sprites/pnj_right.xpm", &prog->img_width, &prog->img_height);
    prog->img_pnj = mlx_xpm_file_to_image(prog->mlx_ptr, "sprites/pnj_down.xpm", &prog->img_width, &prog->img_height);
    prog->img_wall2 = mlx_xpm_file_to_image(prog->mlx_ptr, "sprites/wall2.xpm", &prog->img_width, &prog->img_height);
    prog->img_wall3 = mlx_xpm_file_to_image(prog->mlx_ptr, "sprites/wall3.xpm", &prog->img_width, &prog->img_height);
}