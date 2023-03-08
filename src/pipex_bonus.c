/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 07:09:03 by kpawlows          #+#    #+#             */
/*   Updated: 2023/03/08 19:41:38 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	close_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_cmd)
	{
		close(data->pipe[i][0]);
		close(data->pipe[i][1]);
		i++;
	}
	close(data->f1);
	close(data->f2);
}

void	child(t_data *data, char *cmd, char **cmd_args)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (data->iter == 0)
			dup2(data->f1, 0);
		else
			dup2(data->pipe[data->iter - 1][0], 0);
		if (data->iter == data->nb_cmd - 1)
			dup2(data->f2, 1);
		else
			dup2(data->pipe[data->iter][1], 1);
		close_pipes(data);
		if (execve(cmd, cmd_args, data->env) < 0)
		{
			data->failed_cmd = 1;
			free_commands(cmd, --cmd_args);
			write(2, "Error : execution of cmd failed\n", 33);
		}
		exit(1);
	}
}

int	pipex(t_data *data, char **argv)
{
	char	**tmp;
	char	*cmd;
	char	**cmd_args;

	while (data->iter < data->nb_cmd && data->failed_cmd == 0)
	{
		tmp = ft_split(argv[data->iter + 1], ' ');
		cmd = get_command_path(data->env, ft_strjoin("/", tmp[0]));
		if (cmd == NULL)
		{
			write(2, "Error : can't find command ", 28);
			ft_putendl_fd(tmp[0], 2);
			free_commands(cmd, tmp);
			return (1);
		}
		cmd_args = tmp++;
		child(data, cmd, cmd_args);
		free_commands(cmd, --tmp);
		data->iter++;
	}
	return (0);
}
