/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeulema <nmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:12:21 by nmeulema          #+#    #+#             */
/*   Updated: 2023/10/20 23:12:26 by nmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*us = (const unsigned char *)s;

	while (n > 0)
	{
		if (*us == (unsigned char)c)
			return ((void *)us);
		us++;
		n--;
	}
	return (NULL);
}
