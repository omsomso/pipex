/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:24:14 by kpawlows          #+#    #+#             */
/*   Updated: 2023/01/25 18:50:38 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst2;
	const char	*src2;

	i = -1;
	dst2 = dst;
	src2 = src;
	if (!dst && !src)
		return (NULL);
	if (dst2 < src2)
	{
		while (++i < n)
			dst2[i] = src2[i];
	}
	else
	{
		while (n-- > 0)
			dst2[n] = src2[n];
	}
	return (dst);
}

/*int	main(void)
{
	char str1[] = "abcdefgh";
	char str2[20] = "abcdefgh";
	//char str3[20] = "abcdefgh";

	ft_memmove(&str1[1], &str1[2], 4);
	memmove(&str2[1], &str2[2], 4);
	printf("%s\n", str1);
	printf("%s\n", str2);
	return (0);
}*/