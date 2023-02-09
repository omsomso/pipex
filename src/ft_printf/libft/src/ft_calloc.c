/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:58:02 by kpawlows          #+#    #+#             */
/*   Updated: 2023/01/25 18:50:50 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*coc;

	i = 0;
	coc = malloc(nmemb * size);
	if (coc == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		coc[i] = '\0';
		i++;
	}
	return ((void *) coc);
}

/*int	main(void)
{
	char	*pizza;
	char	*pasta;

	basta = ft_calloc(10, 1);
	pasta = calloc(10, 1);
	printf("%s\n%s\n", pizza, pasta);
	return (0);
}*/