/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:44:20 by kpawlows          #+#    #+#             */
/*   Updated: 2023/01/25 18:50:38 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	llen;

	i = 0;
	llen = ft_strlen(little);
	if (!*little)
		return ((char *) big);
	if (len == 0)
		return (NULL);
	if (len < llen)
		return (NULL);
	len -= llen;
	while (big[i] != '\0' && i <= len)
	{
		if (ft_strncmp(little, &big[i], llen) == 0)
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	str1[] = "abcdefgh";
	char	str2[] = "de";
	int		n = 4;
	
	printf("%s\n", ft_strnstr(str1, str2, n));
	printf("%s\n", strnstr(str1, str2, n));
	return (0);
}*/