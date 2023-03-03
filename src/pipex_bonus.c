/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 07:09:03 by kpawlows          #+#    #+#             */
/*   Updated: 2023/03/03 16:41:55 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	child_1(t_data *data, int in, char *cmd, char **cmd_args)
{
	// take input from infile on 1st iteration
	if (data->iter == 0)
		dup2(data->f1, 0);
	else
	{
		dup2(data->pipe[data->iter][1], 0);		//in becomes read prev pipe
		close(data->pipe[data->iter][1]);		//close read prev pipe
	}

	// output to outfile on last iteration (after last cmd)
	if (data->iter == data->nb_cmd - 1)
	{
		dup2(data->f2, 1);
		close(data->pipe[data->iter][1]);
		close(data->pipe[data->iter][0]);
	}
	else
	{
		dup2(data->pipe[data->iter + 1][1], 1); 	//out becomes write next pipe
		close(data->pipe[data->iter + 1][1]); 		//close write next pipe
	}
	
	if (execve(cmd, cmd_args, data->env) < 0)
		ft_putendl_fd("Error : execution of cmd1 failed", 2);
	exit(1);
}

/*int	child_2(t_data *data, char *cmd, char **cmd_args)
{
	int	tmp;
	
	dup2(data->pipe[0], 0); // in becomes read pipe
	dup2(data->pipe_bis[1], 1); // out becomes write pipe2

	//dup2(data->pipe[1] , 1); // out becomes write pipe
	// but its the same write its reading from, this cant work, unless i close it?
	// but it cant read if i close it

	close(data->pipe[1]);
	close(data->pipe[0]);
	close(data->pipe_bis[1]);
	close(data->pipe_bis[0]);

	//close(data->pipe_bis[0]);
	//tmp = open(data->pipe[1], O_RDWR);
	//if (data->iter < data->nb_cmd / 2)
	//	dup2(data->pipe_bis[1], 1); //out becomes write pipe

	//ft_printf("i tried so hard and got so far\n");
	if (execve(cmd, cmd_args, data->env) < 0)
		ft_putendl_fd("Error : execution of cmd2 failed", 2);
	exit(1);
}*/

void	pipex(t_data *data, char *cmd, char **cmd_args)
{
	int	pid;
	int	i;
	int child_in;
	char buf[1024];

	// child will exec only once per iter, the next iter should wait until pipe is closed?
	// can i use an array of pipes, wont it block the execve cause wow some further pipes r open?
	// if so, i need to init a pipe a time... likely in 2 places
	// on 1st iteration, child_1 reads from infile

	ft_printf("iter = %d\n", data->iter);
	/*if (data->iter == 4)
	{
		read(data->pipe[(data->iter * 2)], buf, 21); //read next pipe
		buf[21] = '\0';
		ft_printf("pipe out = %s\n'", buf);
		exit(1);
	}*/
	//if (data->iter == 1)
	//	child_in = data->f1;

	// else child_1 reads from read pipe2
	/*else
	{
		dup2(data->pipe[data->iter * 2], child_in);
		close(data->pipe[data->iter * 2]);
	}*/
	pid = fork();
	if (pid == 0)
		child_1(data, child_in, cmd, cmd_args);
	close(data->pipe[data->iter][1]);
	close(data->pipe[data->iter + 1][1]);

	close(data->pipe[data->iter][0]);
	close(data->pipe[data->iter + 1][0]);

	//close parents in
	//close(data->pipe[(data->iter * 2) - 1]); //close write next pipe
	//close(data->pipe[(data->iter - 2) * 2]); //close read prev pipe
	//close(data->pipe_bis[0]);
	//close(child_in);

	//wait(NULL); //child 2 will auto wait until pipe gets the out of child 1
	
	/*pid = fork();
	if (pid == 0)
		child_2(data, cmd, cmd_args);*/

	//close(data->pipe_bis[1]);
	//close(data->pipe[0]);
	
	//close(data->pipe_bis[0]);
	//close(data->f1);

	wait(NULL);

	//reading back from pipe test


	data->iter++;
	//pipe(data->pipe);
}
