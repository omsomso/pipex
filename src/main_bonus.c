/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:15:36 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/21 21:45:46 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	/*if (argc != 5)
	{
		ft_putendl_fd("Error : pipex bonus takes 4+ arguments :", 2);
		ft_putendl_fd("[infile] [cmd1 -arg1] [cmdn -argn] [outfile]", 1);
		free(data);
		return (0);
	}*/
	if (get_path(data, envp) == 1 || init_data(data, ++argv) == 1)
	{
		ft_printf("data init problem\n");
		free_everything(data);
		return (0);
	}
	//pipex(data);
	//free_everything(data);
	return (0);
}
