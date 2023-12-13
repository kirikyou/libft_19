/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeulema <nmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:59:41 by nmeulema          #+#    #+#             */
/*   Updated: 2023/10/18 18:14:13 by nmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	little_len = 0;
	while (little[little_len] != '\0')
		little_len++;
	i = 0;
	while (i < len && big[i] != '\0')
	{
		if (len - i < little_len)
			return (NULL);
		j = 0;
		while (j < little_len && big[i + j] == little[j] && big[i + j] != '\0')
			j++;
		if (j == little_len)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
