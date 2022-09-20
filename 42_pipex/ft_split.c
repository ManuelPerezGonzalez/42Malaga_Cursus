/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:45:02 by maperez-          #+#    #+#             */
/*   Updated: 2022/09/20 14:05:00 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_count_words(char const *s, char c)
{
	int	i;
	int	word_num;

	i = 0;
	while (s[i] && s[i] == c) // Ignore any "c" repeats at the beginning.
		i++;
	if (!s[i]) // Check if we're already at the end.
		return (0);
	word_num = 1; // Found first "word".
	while (s[i])
	{ // Eliminate every possible "c" character repetition between words...
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			word_num++; // ...while counting them.
		i++;
	}
	return (word_num);
}

void	ft_bzero(void *str, size_t size)
{ // Reset given string memory space with zeroes.
	size_t i;

	i = 0;
	while (i < size)
		((unsigned char *)str)[i++] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{ // "Clear" the specified amount of memory space.
	void *str;

	if (count + size < count || count + size < size)
		return (0); // Check if parameters are correct.
	str = malloc(count * size);
	if (!str) // Check memory space.
		return (0);
	ft_bzero(str, count * size);
	return (str);
}

char	*ft_malloc_str(const char *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
		i++; // Check how big the word is...
	word = (char *)ft_calloc((i + 1), sizeof(char));
	if (!word) // ...and if we have enough space.
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
	{ // Then, save and return it.
		word[i] = s[i];
		i++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int i;
	int word_num;
	char **strlist;

	if (!s) // Check correct input.
		return (0);
	word_num = ft_count_words(s, c); // Save words total.
	strlist = (char **)malloc(sizeof(char *) * (word_num + 1)); // Allocate memory...
	if (!strlist) // ...and check if there's enough.
		return (0);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			i++;
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