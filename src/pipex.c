/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 07:09:03 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/09 13:12:50 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	child_one(t_data *data, int *tube)
{
	dup2(data->f1, STDIN_FILENO);
	dup2(tube[PIPE_WRITE], STDOUT_FILENO);
	close(tube[PIPE_READ]);
	close(tube[PIPE_WRITE]);
	close(data->f1);
	execve(data->cmd1, data->arg1, data->env);
	ft_putendl_fd("Error : execution of cmd1 failed", 2);
	exit(1);
}

int	child_two(t_data *data, int *tube)
{
	dup2(tube[PIPE_READ], STDIN_FILENO);
	dup2(data->f2, STDOUT_FILENO);
	close(tube[PIPE_READ]);
	close(tube[PIPE_WRITE]);
	close(data->f2);
	execve(data->cmd2, data->arg2, data->env);
	ft_putendl_fd("Error : execution of cmd2 failed", 2);
	exit(1);
}

void	pipex(t_data *data)
{
	int	pid;
	int	pid_2;
	int	child_success;
	int	tube[2];

	if (pipe(tube) < 0)
	{
		ft_putendl_fd("Error : couldn't initialize pipe", 2);
		return ;
	}
	pid = fork();
	if (pid == 0)
		child_success = child_one(data, tube);
	if (child_success == 1)
		return ;
	wait(NULL);
	pid = fork();
	if (pid == 0)
		child_success = child_two(data, tube);
	if (child_success == 1)
		return ;
	close(tube[PIPE_WRITE]);
	close(tube[PIPE_READ]);
	wait(NULL);
}
