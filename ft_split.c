/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeulema <nmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:01:14 by nmeulema          #+#    #+#             */
/*   Updated: 2023/10/30 02:01:16 by nmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_check_separator(char ch, const char *c)
{
	int i;

	i = 0;
	while (c[i] != '\0')
	{
		if (ch == c[i])
			return (1);
		i++;
	}
	return (0);
}

int ft_count_sings(const char *s, const char *c)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && ft_check_separator(s[i], c))
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && !ft_check_separator(s[i], c))
			i++;
	}
	return (count);
}

int ft_slen_sep(const char *s, const char *c)
{
	int i;

	i = 0;
	while (s[i] && !ft_check_separator(s[i], c))
		i++;
	return (i);
}

char *ft_word(const char *s, const char *c)
{
	int len_word;
	int i;
	char *word;

	i = 0;
	len_word = ft_slen_sep(s, c);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (word == NULL)
		return (NULL);
	while (i < len_word)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char **ft_split(char const *s, char c)
{
	int word_count;
	char **sings;
	int i;

	if (!s || !c)
		return (NULL);
	word_count = ft_count_sings(s, &c);
	sings = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!sings)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && ft_check_separator(*s, &c))
			s++;
		if (*s)
		{
			sings[i] = ft_word(s, &c);
			i++;
		}
		while (*s && !ft_check_separator(*s, &c))
			s++;
	}
	sings[i] = NULL;
	return (sings);
}
