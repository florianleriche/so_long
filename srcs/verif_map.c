/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:09:38 by fleriche          #+#    #+#             */
/*   Updated: 2023/02/10 10:31:54 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_alert(char *alert)
{
	ft_printf("Error\n");
	ft_printf("%s\n", alert);
	exit(1);
}

int	len_map_x(t_data *dta, char **map,int  x)
{
	int	i;

	i = 0;
	while (map[x][i])
		i++;
	if (x == 0)
		dta->map_x = i;
	return (i);
}

int	len_map_y(t_data *dta, char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	dta->map_y = i;
	return (i);
}

int	nb_char_in_map(char *map_str, char c)
{
	int	i;
	int result;

	i = 0;
	result = 0;
	while (map_str[i] != '\0')
	{
		if (map_str[i] == c)
			result++;
		i++;
	}
	return (result);
}


void map_0_to_P(int i,int i2, char **map)
{
	if (map[i][i2 - 1] == '0')
		map[i][i2 - 1] = 'P';
	if (map[i][i2 + 1] == '0')
		map[i][i2 + 1] = 'P';
	if (map[i - 1][i2] == '0')
		map[i - 1][i2] = 'P';
	if (map[i + 1][i2] == '0')
		map[i + 1][i2] = 'P';
}

void map_C_to_P(t_data *dta, int i, int i2, char **map)
{
	if (map[i][i2 - 1] == 'C')
	{
		map[i][i2 - 1] = 'P';
		dta->nb_collectible++;
	}
	if (map[i][i2 + 1] == 'C')
	{
		map[i][i2 + 1] = 'P';
		dta->nb_collectible++;
	}
	if (map[i - 1][i2] == 'C')
	{
		map[i - 1][i2] = 'P';
		dta->nb_collectible++;
	}
	if (map[i + 1][i2] == 'C')
	{
		map[i + 1][i2] = 'P';
		dta->nb_collectible++;
	}
}

void map_E_to_P(t_data *dta, int i, int i2, char **map)
{
	if (map[i][i2 - 1] == 'E')
	{
		map[i][i2 - 1] = 'P';
		dta->nb_exit++;
	}
	if (map[i][i2 + 1] == 'E')
	{
		map[i][i2 + 1] = 'P';
		dta->nb_exit++;
	}
	if (map[i - 1][i2] == 'E')
	{
		map[i - 1][i2] = 'P';
		dta->nb_exit++;
	}
	if (map[i + 1][i2] == 'E')
	{
		map[i + 1][i2] = 'P';
		dta->nb_exit++;
	}
}

char	**map_p(t_data *dta, char **map)
{
	int	i;
	int	i2;
	int	i3;

	i3 = -1;
	while (++i3 != dta->map_y * dta->map_x)
	{
		i = -1;
		while (++i != dta->map_y)
		{
			i2 = -1;
			while (++i2 != dta->map_x)
			{
				if (map[i][i2] == 'P')
				{
					map_0_to_P(i, i2, map);
					map_C_to_P(dta, i, i2, map);
					map_E_to_P(dta, i, i2, map);
				}
			}
		}
	}
	if (dta->nb_exit != 1)
		error_alert("Error on Exit");
	if (dta->nb_collectible != nb_char_in_map(dta->map_str, 'C'))
		error_alert("Error on Collectible");
	return (map);
}

void	verif_char(t_data *dta)
{
	int i;

	i = 0;
//Bon charactere
	while (dta->map_str[i] != '\0')
	{
		if (dta->map_str[i] != '0' && dta->map_str[i] != '1'
				&& dta->map_str[i] != 'E' && dta->map_str[i] != 'C'
				&& dta->map_str[i] != 'P' && dta->map_str[i] != '\n')
			error_alert("Error on char Map");
		i++;
	}
	//Bon nombre de characteres
	if (nb_char_in_map(dta->map_str, 'C') < 1
		|| nb_char_in_map(dta->map_str, 'E') != 1
		|| nb_char_in_map(dta->map_str, 'P') != 1)
		error_alert("Error on char Map");
}

void map_shape(t_data *dta)
{
	int	i;
	//forme rectangulaire
	i = 0;
	if (dta->map_y < 3)
		error_alert("Error size Map");
	while (i != dta->map_y)
	{
		if (len_map_x(dta, dta->map, i) != dta->map_x)
			error_alert("Error shape Map");
		i++;
	}
	//entoure de murs
	i = 0;
	while (i != dta->map_x)
	{
		if (dta->map[0][i] != '1' || dta->map[dta->map_y - 1][i] != '1')
			error_alert("Error on walls");
		i++;
	}
	i = 0;
	while (i != dta->map_y)
	{
		if (dta->map[i][0] != '1' || dta->map[i][dta->map_x - 1] != '1')
			error_alert("Error on walls");
		i++;
	}
}

void	verif_map(t_data *dta)
{
	dta->nb_exit = 0;
	dta->nb_collectible = 0;
	
	//initialisation du x y map
	len_map_x(dta, dta->map, 0);
	len_map_y(dta, dta->map);
	//map shape
	verif_char(dta);
	map_shape(dta);
	//map possible a finir
	map_p(dta, dta->map_buf);
}