/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:15:20 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/20 19:00:15 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
	free_pointer_array(data->env);
	free_pointer_array(data->arg1);
	free_pointer_array(data->arg2);
	free(data->cmd1);
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
		if (access(path, F_OK) == 0)
			return (path);
		i++;
		free(path);
	}
	return (NULL);
}

int	init_data(t_data *data, char **args, char *env)
{
	char	**tmp1;
	char	**tmp2;

	data->f1 = open(args[0], O_RDWR);
	data->f2 = open(args[3], O_RDWR | O_CREAT);
	if (data->f1 < 0 || data->f2 < 0)
	{
		ft_putendl_fd("Error : couldn't open the infile or the outfile", 2);
		return (1);
	}
	data->env = ft_split(&env[5], ':');
	tmp1 = ft_split(args[1], ' ');
	data->cmd1 = get_command_path(data->env, ft_strjoin("/", tmp1[0]));
	data->arg1 = tmp1++;
	tmp2 = ft_split(args[2], ' ');
	data->cmd2 = get_command_path(data->env, ft_strjoin("/", tmp2[0]));
	data->arg2 = tmp2++;
	if (data->cmd1 == NULL || data->cmd2 == NULL)
	{
		ft_putendl_fd("Error : couldn't find one of the commands", 2);
		return (1);
	}
	return (0);
}

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
}
