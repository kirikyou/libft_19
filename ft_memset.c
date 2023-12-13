/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeulema <nmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:43:47 by nmeulema          #+#    #+#             */
/*   Updated: 2023/10/16 19:25:06 by nmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	size_t						i;
	unsigned char			*p;
	unsigned char			byte_value;

	i = 0;
	byte_value = (unsigned char)c;
	p = dest;
	while (i < count) 
	{
		p[i] = byte_value;
		i++;
	}
	return (dest);
}
