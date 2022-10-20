/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:36:02 by maperez-          #+#    #+#             */
/*   Updated: 2022/10/19 13:27:50 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Ignore any "c" repeats at the beginning.
// Check if we'r e already at the end.
// Found first "word".
// Eliminate every possible "c" character repetition between words
// While counting them.
// Check how big the word is, and if we have enough space.
// Then, save and return it.
// Check correct input.
// Save words total.
// Allocate memory and check if there's enough.
int	ft_count_words(char const *s, char c)
{
	int	i;
	int	word_num;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	if (!s[i])
		return (0);
	word_num = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			word_num++;
		i++;
	}
	return (word_num);
}

char	*ft_malloc_str(const char *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)ft_calloc((i + 1), sizeof(char));
	if (!word)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word_num;
	char	**strlist;

	if (!s)
		return (0);
	word_num = ft_count_words(s, c);
	strlist = (char **)malloc(sizeof(char *) * (word_num + 1));
	if (!strlist)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			strlist[i] = ft_malloc_str(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	strlist[i] = 0;
	return (strlist);
}
