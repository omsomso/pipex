/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:15:20 by kpawlows          #+#    #+#             */
/*   Updated: 2023/03/08 19:43:20 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

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
		write(2, "Error : couldn't init PATH\n", 28);
		return (1);
	}
	return (0);
}

char	*get_command_path(char **env, char *cmd)
{
	char	*path;
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		path = ft_strjoin(env[i], cmd);
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

int	init_data_add(t_data *data, char **argv)
{
	data->f1 = open(argv[0], O_RDONLY);
	if (data->f1 < 0)
	{
		ft_putendl_fd("Error : couldn't open the infile", 2);
		return (1);
	}
	data->f2 = open(argv[data->nb_cmd + 1], O_RDWR | O_CREAT, 0777);
	if (data->f2 < 0)
	{
		ft_putendl_fd("Error : couldn't open or create the outfile", 2);
		return (1);
	}
	return (0);
}

int	init_data(t_data *data, char **argv)
{
	int		i;

	i = 0;
	data->failed_cmd = 0;
	data->iter = 0;
	data->nb_cmd = 0;
	while (argv[++i + 1] != NULL)
		data->nb_cmd++;
	data->pipe = malloc(((sizeof(int **)) * (data->nb_cmd)));
	i = -1;
	while (++i < data->nb_cmd)
		data->pipe[i] = malloc((sizeof(int)) * 2);
	i = -1;
	while (++i < data->nb_cmd)
	{
		if (pipe(data->pipe[i]) < 0)
		{
			ft_putendl_fd("Error : couldn't initialize pipe", 2);
			return (1);
		}
	}
	return (init_data_add(data, argv));
}

/*void	print_dbg_data(char *cmd, char **cmd_args, t_data *data)
{
	int	i;

	i = -1;
	ft_printf("iter = %d\n", data->iter);
	ft_printf("cmd = %s\n", cmd);
	while (data->env[++i] != NULL)
		ft_printf("env[%d] =\t%s\n", i, data->env[i]);
	i = -1;
	while (cmd_args[++i] != NULL)
		ft_printf("arg1[%d] =\t%s\n", i, cmd_args[i]);
	if (data->iter == 0)
		ft_printf("in  =\tf1\n");
	else
		ft_printf("in  =\tdata->pipe[%d][0]\n", data->iter - 1);
	ft_printf("out =\tdata->pipe[%d][1]\n", data->iter);
	if (data->iter == data->nb_cmd)
		ft_printf("out =\tout\n");
	//	print_dbg_data(cmd, cmd_args, data);
}*/
