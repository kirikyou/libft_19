/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeulema <nmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:51:32 by nmeulema          #+#    #+#             */
/*   Updated: 2023/10/23 17:51:44 by nmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_const(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char		*destination;
	const char	*source;

	destination = dest;
	source = src;
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen_const(s1);
	s2_len = ft_strlen_const(s2);
	total_len = s1_len + s2_len;
	result = (char *)malloc(total_len + 1);
	if (result != NULL)
	{
		ft_strcpy(result, s1);
		ft_strcpy(result + s1_len, s2);
	}
	return (result);
}
