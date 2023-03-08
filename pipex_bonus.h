/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:16:01 by kpawlows          #+#    #+#             */
/*   Updated: 2023/03/08 19:39:20 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "src/libft/libft.h"

typedef struct s_data
{
	char	**env;
	char	*buf;
	int		failed_cmd;
	int		iter;
	int		f1;
	int		f2;
	int		**pipe;
	int		nb_cmd;
}	t_data;

void	free_pointer_array(char **s);
void	free_everything(t_data *data);
char	*get_command_path(char **env, char *cmd);
int		init_data(t_data *data, char **args);
int		init_data_add(t_data *data, char **argv);
int		get_path(t_data *data, char **envp);
void	child(t_data *data, char *cmd, char **cmd_args);
int		pipex(t_data *data, char **argv);
void	close_pipes(t_data *data);
void	free_pipes(t_data *data);
void	free_commands(char *cmd, char **tmp);
void	print_dbg_data(char *cmd, char **cmd_args, t_data *data);

#endif