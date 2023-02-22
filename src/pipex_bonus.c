/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 07:09:03 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/22 14:06:01 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	child_1(t_data *data, int fd, char *cmd, char **cmd_args)
{
	dup2(fd, 0); // fd becomes input
	//close(data->tube[1]);
	if (data->iter % 2 == 0)
	{
		close(data->tube[1]);
		close(data->tube[0]);
		//dup2(data->tube[1], 1);
	}
	dup2(data->tube[1], 1); //cmd writes to pipe
	//ft_printf("trying to reredirect pipe");
	close(data->tube[1]);
	close(data->tube[0]);
	close(fd);
	printf("im locked :(\n");
	if (execve(cmd, cmd_args, data->env) < 0)
		ft_putendl_fd("Error : execution of cmd1 failed", 2);
	exit(1);
}

int	child_2(t_data *data, char *cmd, char **cmd_args)
{
	int	tmp;
	
	dup2(data->tube[0], 0); // in becomes reading end of pipe

	close(data->tube[1]);
	close(data->tube[0]);

	//tmp = open(data->tube[1], O_RDWR);
	if (data->iter < data->nb_cmd)
		dup2(data->tube[1], 1); //out becomes writing end of pipe

	ft_printf("where?\n");
	if (execve(cmd, cmd_args, data->env) < 0)
		ft_putendl_fd("Error : execution of cmd2 failed", 2);
	//ft_printf("i tried so hard and got so far\n");
	exit(1);
}

/*int	child_one(t_data *data, int *tube)
{
	dup2(data->f1, STDIN_FILENO);
	//dup2(tube[PIPE_WRITE], STDOUT_FILENO);
	//close(tube[PIPE_READ]);
	//close(tube[PIPE_WRITE]);
	//close(data->f1);
	if (execve(data->cmd1, data->arg1, data->env) < 0)
		ft_putendl_fd("Error : execution of cmd1 failed", 2);
	exit(1);
}*/

int	child_two(t_data *data, int *tube)
{
	dup2(tube[PIPE_READ], STDIN_FILENO);
	//dup2(data->f2, STDOUT_FILENO);
	//close(tube[PIPE_READ]);
	//close(tube[PIPE_WRITE]);
	//close(data->f2);
	if (execve(data->cmd2, data->arg2, data->env) < 0)
		ft_putendl_fd("Error : execution of cmd2 failed", 2);
	exit(1);
}

void	pipex(t_data *data, char *cmd, char **cmd_args)
{
	int	pid;
	int tmp_fd;

	if (data->iter == 1)
		tmp_fd = data->f1;
	else
	{
		//dup2(tmp_fd, data->tube[0]);
		dup2(tmp_fd, data->tube[0]);
		//close(data->tube[0]);
		//close(data->tube[1]);
	}
	
	pid = fork();
	if (pid == 0)
		child_1(data, tmp_fd, cmd, cmd_args);
	close(data->tube[1]);
	close(tmp_fd);

	wait(NULL);	

	pid = fork();
	if (pid == 0)
		child_2(data, cmd, cmd_args);
	close(data->tube[0]);
	//close(data->tube[1]);
	close(data->f1);
	
	wait(NULL);

	data->iter++;
	//ft_printf("iter = %d\n", data->iter);
	//if (data->iter % 2 == 0)
	//{
		//printf("uo\n");
		//int	random_fd2;
		//random_fd2 = dup(data->tube[1]);
		//char buf[1024];
		//read(data->tube[0], buf, 100);
		//ft_printf("pipe out = %s, iter = %d\n", buf, data->iter);
		/*if (pipe(data->tube) < 0)
		{
			ft_putendl_fd("Error : couldn't initialize pipe", 2);
			return ;
		}*/
		//data->tube[1] = random_fd;
		//data->tube[0] = random_fd2;
		//close(random_fd2);
	//}
	/*pid = fork();
	if (pid == 0)
		child_two(data, tube);
	close(tube[PIPE_WRITE]);
	close(tube[PIPE_READ]);
	wait(NULL);*/
}
