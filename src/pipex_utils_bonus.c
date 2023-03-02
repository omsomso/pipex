/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:15:20 by kpawlows          #+#    #+#             */
/*   Updated: 2023/03/02 21:22:40 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	free_pointer_array(char **s)
{
	int	i;

	i = -1;
	while (s[i++] != NULL)
		free(s[i]);
	if (s != NULL)
		free(s);
}

void	free_everything(t_data *data)
{
	if (data->env != NULL)
		free_pointer_array(data->env);
	if (data->arg1 != NULL)
		free_pointer_array(data->arg1);
	if (data->arg2 != NULL)
		free_pointer_array(data->arg2);
	if (data->cmd1 != NULL)
		free(data->cmd1);
	if (data->cmd2 != NULL)
		free(data->cmd2);
	if (data != NULL)
		free(data);
}

char	*get_command_path(char **env, char *cmd)
{
	char	*path;
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		path = ft_strjoin(env[i], cmd);
		//	printf("cmsd = %s\n", path);
		if (access(path, F_OK) == 0)
		{
			free(cmd);
			return (path);
		}
		i++;
		free(path);
	}
	free(cmd);
	return (NULL);
}

int	get_path(t_data *data, char **envp)
{
	int	i;

	i = -1;
	data->env = NULL;
	while (envp[++i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
	}
	data->env = ft_split(&envp[i][5], ':');
	if (data->env == NULL)
	{
		return (1);
	}
	data->cmd1 = NULL;
	data->cmd2 = NULL;
	data->arg1 = NULL;
	data->arg2 = NULL;
	data->end = 0;
	data->iter = 1;
	data->nb_cmd = 0;
	return (0);
}

int	init_data(t_data *data, char **argv)
{
	char	**tmp1;
	char	**tmp2;
	char	*cmd;
	char	**cmd_args;
	int		i;

	i = 0;
	data->f1 = open(argv[0], O_RDONLY);
	//data->f2 = open(argv[3], O_RDWR);
	/*if (data->f1 < 0 || data->f2 < 0)
	{
		ft_putendl_fd("Error : couldn't open the infile or outfile", 2);
		return (1);
	}*/
	while (argv[++i + 1] != NULL)
		data->nb_cmd++;
	i = 0;
		/*if (pipe(data->pipe) < 0)
		{
			ft_putendl_fd("Error : couldn't initialize pipe", 2);
			return (1);
		}
		pipe(data->pipe_bis);*/
	ft_printf("nb_cmd = %d\n", data->nb_cmd);
	i = 0;
	data->pipe = malloc((sizeof(int) * 2) * data->nb_cmd);
	i = 0;
	while (i < data->nb_cmd)
	{
		if (pipe(data->pipe + (i * 2)) < 0) // init a pipe [0][1] for every command
			return (1); //couldnt init pipe;
		i++;
	}
	i = 0;
	while (i < data->nb_cmd)
	{
		// find the command to execve on this iter
		tmp1 = ft_split(argv[i], ' ');
		cmd = get_command_path(data->env, ft_strjoin("/", tmp1[0]));
		cmd_args = tmp1++;

		//printf("cmd = %s\n", cmd);
		//printf("i = %d\n", i);
		pipex(data, cmd, cmd_args);
		i++;
	}
	//print_dbg_data(data);
	/*
	if (data->cmd1 == NULL || data->cmd2 == NULL)
	{
		ft_putendl_fd("Error : couldn't find one of the commands", 2);
		return (1);
	}*/
	//printf("%s, %s \n", WR_NEXT, RD_PREV);
	return (0);
}

/*int	init_data(t_data *data, char **args)
{
	char	**tmp1;
	char	**tmp2;

	data->f1 = open(args[0], O_RDONLY);
	//data->f2 = open(args[3], O_RDWR);
	if (data->f1 < 0 || data->f2 < 0)
	{
		ft_putendl_fd("Error : couldn't open the infile or outfile", 2);
		return (1);
	}
	tmp1 = ft_split(args[1], ' ');
	data->cmd1 = get_command_path(data->env, ft_strjoin("/", tmp1[0]));
	data->arg1 = tmp1++;
	tmp2 = ft_split(args[2], ' ');
	data->cmd2 = get_command_path(data->env, ft_strjoin("/", tmp2[0]));
	data->arg2 = tmp2++;
	//print_dbg_data(data);
	if (data->cmd1 == NULL || data->cmd2 == NULL)
	{
		ft_putendl_fd("Error : couldn't find one of the commands", 2);
		return (1);
	}
	return (0);
}*/

void	print_dbg_data(t_data *data)
{
	int	i;

	i = -1;
	ft_printf("cmd1 = %s\ncmd2 = %s\n", data->cmd1, data->cmd2);
	while (data->env[++i] != NULL)
		ft_printf("env[%d] = %s\n", i, data->env[i]);
	i = -1;
	while (data->arg1[++i] != NULL)
		ft_printf("arg1[%d] = %s\n", i, data->arg1[i]);
	i = -1;
	while (data->arg2[++i] != NULL)
		ft_printf("arg2[%d] = %s\n", i, data->arg2[i]);
	i = -1;
	//while (envp[++i] != NULL)
	//	printf("%s\n", envp[i]);
}
