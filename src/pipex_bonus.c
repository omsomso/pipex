/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 07:09:03 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/24 10:07:33 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	child_1(t_data *data, int fd, char *cmd, char **cmd_args)
{
	dup2(fd, 0); // fd becomes input
	//close(data->tube[1]);

	close(fd);
	dup2(data->tube[1], 1); //cmd writes to pipe
	close(data->tube[1]);
	close(data->tube[0]);
	printf("im locked :(\n");
	if (execve(cmd, cmd_args, data->env) < 0)
		ft_putendl_fd("Error : execution of cmd1 failed", 2);
	exit(1);
}

int	child_2(t_data *data, char *cmd, char **cmd_args)
{
	int	tmp;
	
	dup2(data->tmp_fd, 0); // in becomes tmp_fd

	close(data->tube[1]);
	close(data->tube[0]);

	//tmp = open(data->tube[1], O_RDWR);
	if (data->iter < data->nb_cmd / 2)
		dup2(data->tube_bis[1], 1); //out becomes writing end of pipe

	ft_printf("where?\n");
	if (execve(cmd, cmd_args, data->env) < 0)
		ft_putendl_fd("Error : execution of cmd2 failed", 2);
	//ft_printf("i tried so hard and got so far\n");
	exit(1);
}

void	pipex(t_data *data, char *cmd, char **cmd_args)
{
	int	pid;
	int new_fd;
	char buf[1024];

	if (data->iter == 1)
		new_fd = data->f1;
	else
		dup2(new_fd, data->tube[0]);
	
	pid = fork();
	if (pid == 0)
		child_1(data, new_fd, cmd, cmd_args);
	close(new_fd);
	close(data->tube[1]);

	wait(NULL);	

	pid = fork();
	if (pid == 0)
		child_2(data, cmd, cmd_args);
	close(data->tube[0]);
	close(data->f1);

	wait(NULL);

	//reading back from pipe test
	read(data->tube[0], buf, 100);
	ft_printf("pipe out = %s, iter = %d\n", buf, data->iter);

	data->iter++;
	//pipe(data->tube);
}
