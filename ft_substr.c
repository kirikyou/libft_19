/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeulema <nmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:53:50 by nmeulema          #+#    #+#             */
/*   Updated: 2023/10/23 16:53:59 by nmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substring;
	size_t	finish;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	finish = 0;
	if (start < s_len)
		finish = s_len - start;
	if (finish > len)
		finish = len;
	substring =(char *)malloc(sizeof(char) * (finish + 1));
	if (!substring)
		return (0) ;
		
	ft_strlcpy(substring, s + start, finish + 1);
	return (substring);
}
