/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:27:10 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/09 10:19:35 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 15000
# endif

typedef struct s_data {
	char	**map;
	char	*map_str;
	char	**map_buf;
	int		map_x;
	int		map_y;
	int		nb_collectible;
	int		nb_exit;
	int		img_x;
	int		img_y;
	int		p_y;
	int		p_x;
} t_data;

typedef struct s_prog {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*img_player;
	void	*img_collectible;
	void	*img_floor;
	void	*img_floor2;
	void	*img_exit;
	void	*img_wall;
	void	*img_player_up;
	void	*img_player_right;
	void	*img_player_left;
	void	*img_exit_open;
	void	*img_pnj;
	void	*img_pnj_left;
	void	*img_pnj_right;
	void	*img_wall3;
	void	*img_wall2;
	int		img_width;
	int		img_height;
	char	**map;
	int		map_x;
	int		map_y;
	int		nb_collectible;
	int		nb_exit;
	int		nb_mouv;
	int		x;
	int		y;
	int		right;
	int		player_position_x;
	int		player_position_y;
	int		pnj_position_x;
	int		pnj_position_y;
	int		exit_position_x;
	int		exit_position_y;
} t_prog;

void	read_map(char *map, t_data *dta, t_prog *prog);
void	verif_map(t_data *dta);
int		len_map_x(t_data *dta,char **map, int x);
int		len_map_y(t_data *dta,char **map);
int		nb_char_in_map(char *map_str, char c);
char	**map_p(t_data *dta, char **map);
void	render();
void	player_init(t_data *dta, t_prog *prog);
int		ft_input(int key, t_prog *prog);
void	init_map(t_data *dta, t_prog *prog);
int		move_right(t_prog *prog);
int		move_left(t_prog *prog);
int		move_up(t_prog *prog);
int		move_down(t_prog *prog);
void    img_init(t_prog *prog);
int		verif_exit(t_prog *prog);
int		verif_end(t_prog *prog);
void	change_map(t_data *dta, t_prog *prog);
int		ft_update(t_prog *prog);
int		ft_anim_collectible(t_prog *prog);
int		ft_anim_watter(t_prog *prog);
void	lose();

#endif
