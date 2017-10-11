/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 01:01:32 by dpearson          #+#    #+#             */
/*   Updated: 2017/09/21 01:01:33 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "stdlib.h"

static int	ft_word_count(char *str, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if ((str[i] != c) && (i == 0 || str[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

static int	ft_word_size(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] == c)
		str++;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		word_count;
	int		words_entered;
	int		i;
	char	**words;

	if (!s)
		return (NULL);
	words_entered = 0;
	word_count = ft_word_count((char *)s, c);
	words = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	while (words_entered < word_count)
	{
		i = 0;
		words[words_entered] = (char *)malloc(sizeof(char)
			* (ft_word_size(s, c) + 1));
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
			words[words_entered][i++] = *s++;
		words[words_entered++][i] = '\0';
	}
	words[word_count] = 0;
	return (words);
}
