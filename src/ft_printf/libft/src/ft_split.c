/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 08:15:36 by kpawlows          #+#    #+#             */
/*   Updated: 2023/01/25 18:50:38 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_issep(char const *s, char c, int i)
{
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

int	ft_isword(char const *s, char c, int i)
{
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		i = ft_issep(s, c, i);
		if (s[i] != c && s[i] != '\0')
			count++;
		i = ft_isword(s, c, i);
	}
	return (count);
}

char	**ft_split(char const *s, char const c)
{
	int		i;
	int		j;
	int		wc;
	char	**split;

	i = 0;
	j = 0;
	wc = ft_wordcount(s, c);
	split = malloc(sizeof(char *) * wc + sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (i < wc)
	{
		j = ft_issep(s, c, j);
		split[i] = malloc(sizeof(char) * ft_isword(s, c, j) - j + 1);
		ft_strlcpy(split[i], &s[j], ft_isword(s, c, j) - j + 1);
		j = ft_isword(s, c, j);
		i++;
	}
	split[i] = NULL;
	return (split);
}

/*int	main(int argc, char **argv)
{
	char	**split;

	if (argc != 2)
		return (0);
	split = ft_split(argv[1], ' ');
	int	i = 0, wc = ft_wordcount(argv[1], ' ');
	while (i <= wc)
	{
		printf("split[%d] = %s\n", i, split[i]);
		i++;
	}
	return (0);
}*/
