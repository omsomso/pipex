/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:24:14 by kpawlows          #+#    #+#             */
/*   Updated: 2023/01/25 18:50:38 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*s1tmp;
	const char	*s2tmp;

	i = 0;
	s1tmp = s1;
	s2tmp = s2;
	if (n == 0)
		return (0);
	while (i < (n - 1) && s1tmp[i] == s2tmp[i])
		i++;
	if (s1tmp[i] != s2tmp[i])
		return ((unsigned char)s1tmp[i] - (unsigned char)s2tmp[i]);
	return (0);
}

/*int	main(void)
{
	char str1[] = "asdf";
	char str2[] = "asdf";

	printf("%d\n", ft_memcmp(str1, str2, 0));
	printf("%d\n", memcmp(str1, str2, 0));
	return (0);
}*/