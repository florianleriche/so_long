/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:16:44 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/10 10:27:24 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
void init_general(t_data *dta, t_prog *prog, int argc, char **argv)
{
	//verif nb arg
	if (argc != 2)
	{
		ft_printf("Error on the nbr arguments\n");
		exit(1);
	}
	read_map(argv[1], dta, prog);
	verif_map(dta);
	prog->nb_collectible = dta->nb_collectible;
	player_init(dta, prog);
	prog->map_x = dta->map_x;
	prog->map_y = dta->map_y; 
	prog->pnj_position_x = 11;
    prog->pnj_position_y = 2;
	prog->nb_mouv = 0;
}
int ft_close_game()
{
	exit(1);
}

int	main(int argc, char **argv)
{
	t_data dta;
	t_prog prog;

	init_general(&dta, &prog, argc, argv);
    prog.mlx_ptr = mlx_init();
	prog.win_ptr = mlx_new_window(prog.mlx_ptr, dta.map_x * 32 , dta.map_y * 32, "Florian's Game");
	img_init(&prog);
	change_map(&dta, &prog);
	render(&dta, &prog);
    mlx_key_hook(prog.win_ptr, ft_input, &prog);
	mlx_loop_hook(prog.mlx_ptr, ft_update, &prog);
	mlx_hook(prog.win_ptr, 17, 1L<<2, ft_close_game, &prog);
	mlx_loop(prog.mlx_ptr);
	exit(1);
}