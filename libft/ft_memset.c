/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:15:46 by fleriche          #+#    #+#             */
/*   Updated: 2022/11/09 14:50:29 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = b;
	while (len != 0)
	{
		ptr[i] = c;
		i++;
		len--;
	}
	return (b);
}