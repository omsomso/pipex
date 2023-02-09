/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:15:36 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/09 13:12:53 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (argc < 2 || argc > 5)
	{
		ft_putendl_fd("Error : wrong number of arguments", 2);
		return (0);
	}
	if (init_data(data, ++argv, envp[1]) == 1)
		return (1);
	pipex(data);
	free(data);
	return (0);
}
