/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:25:49 by kpawlows          #+#    #+#             */
/*   Updated: 2023/01/25 18:50:38 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isset(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	s1len;

	i = 0;
	s1len = ft_strlen(s1);
	while (ft_isset(set, s1[i]) == 1)
		i++;
	if (i == s1len)
		return (ft_substr(s1, 0, 0));
	while (s1len != 0 && ft_isset(set, s1[s1len - 1]) == 1)
		s1len--;
	return (ft_substr(s1, i, s1len - i));
}

/*int main(void)
{
	char	str1[] = "  \t \t \n   \n\n\n\t";
	char	str2[] = " \n\t";
	
	printf("%s\n", ft_strtrim(str1, str2));
//	printf("%s\n", ft_strtrim(str1, 3, 7));
//	printf("%s\n", strtrim(str1, 2, 2));
	return (0);
}*/