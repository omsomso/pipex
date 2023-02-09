/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:08:06 by kpawlows          #+#    #+#             */
/*   Updated: 2023/01/25 18:50:38 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (n == 0)
		return (src_len);
	while (i < (n - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*int main(void)
{
	printf("\n");
	char dest[100] = "aaa";
	char src[100] = "1234";
	printf("%d \n", ft_strlcpy(dest, src, 3));
	printf("%s\n", dest);

	printf("----------\n");

	char dest2[100] = "aaa";
	char src2[100] = "1234";
	printf("%lu \n", strlcpy(dest2, src2, 3));
	printf("%s\n", dest2);
	printf("\n");
	return (0);
}*/