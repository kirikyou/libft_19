/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeulema <nmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:32:10 by nmeulema          #+#    #+#             */
/*   Updated: 2023/10/23 18:32:15 by nmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		end;
	const char	*s;
	char		*result;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	end = 0;
	s = s1;
	while (*s)
	{
		if (!ft_strchr(set, *s))
			end = s - s1 + 1;
		s++;
	}
	result = (char *)malloc(end + 1);
	if (!result)
		return (NULL);
	result[end] = '\0';
	while (end--)
		result[end] = s1[end];
	return (result);
}
