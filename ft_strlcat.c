/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeulema <nmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:59:47 by nmeulema          #+#    #+#             */
/*   Updated: 2023/10/18 17:08:05 by nmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_s;
	size_t	len_d;
	size_t	di;
	size_t	si;

	si = ft_strlen(src);
	if (!dest && size == 0)
		return (si);
	len_d = ft_strlen(dest);
	di = len_d;
	if (size <= di)
		return (size + si);
	len_s = 0;
	while (src[len_s] && len_d + 1 < size)
	{
		dest[len_d] = src[len_s];
		len_s++;
		len_d++;
	}
	dest[len_d] = 0;
	return (di + si);
}
