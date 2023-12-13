/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeulema <nmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:21:46 by nmeulema          #+#    #+#             */
/*   Updated: 2023/10/30 01:21:49 by nmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_neg_conv(char *str, int n, int len)
{
	str[0] = '-';
	while (n != 0)
	{
		str[len] = '0' - (n % 10);
		n /= 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_numlen(n);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	len--;
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
		str = ft_neg_conv(str, n, len);
	else
	{
		while (n != 0)
		{
			str[len] = '0' + (n % 10);
			n /= 10;
			len--;
		}
	}
	return (str);
}
