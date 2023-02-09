/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:25:49 by kpawlows          #+#    #+#             */
/*   Updated: 2023/01/25 18:50:38 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1len;
	size_t	s2len;
	char	*join;

	i = -1;
	j = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	join = malloc(sizeof(char) * (s1len + s2len) + 1);
	if (join == NULL)
		return (NULL);
	while (++i < s1len)
		join[i] = s1[i];
	while (j < s2len)
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

/*int main(void)
{
	char	str1[] = "yay it ";
	char	str2[] = "kinda(?) works";

	if (ft_strjoin(str1, str2) != 0x00)
		printf("%s\n", ft_strjoin(str1, str2));
	if (ft_strjoin(str1, str2) == 0x00)
		printf("(null)\n");
//	printf("%s\n", ft_strjoin(str1, 3, 7));
//	printf("%s\n", strjoin(str1, 2, 2));
	return (0);
}*/