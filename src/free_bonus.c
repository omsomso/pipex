/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:57:02 by kpawlows          #+#    #+#             */
/*   Updated: 2023/03/09 09:47:13 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	free_pointer_array(char **s)
{
	int	i;

	i = -1;
	while (s[++i] != NULL)
		free(s[i]);
	if (s != NULL)
		free(s);
}

void	free_commands(char *cmd, char **tmp)
{
	if (cmd != NULL)
		free(cmd);
	free_pointer_array(tmp);
}

void	free_pipes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_cmd)
		free(data->pipe[i]);
	free(data->pipe);
}

void	free_everything(t_data *data)
{
	if (data->env != NULL)
		free_pointer_array(data->env);
	if (data->pipe != NULL)
		free_pipes(data);
	if (data != NULL)
		free(data);
}
