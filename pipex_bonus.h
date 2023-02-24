/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:16:01 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/24 09:45:11 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "src/ft_printf/ft_printf.h"

# define PIPE_WRITE 1
# define PIPE_READ 0

typedef struct s_data
{
	char	*cmd1;
	char	*cmd2;
	char	**arg1;
	char	**arg2;
	char	**env;
	char	*buf;
	int		tmp_fd;
	int		end;
	int		iter;
	int		f1;
	int		f2;
	int		tube[2];
	int		tube_bis[2];
	int		nb_cmd;
}	t_data;

void	free_pointer_array(char **s);
void	free_everything(t_data *data);
char	*get_command_path(char **env, char *cmd);
int		init_data(t_data *data, char **args);
int		get_path(t_data *data, char **envp);
int		child_one(t_data *data, int *tube);
int		child_two(t_data *data, int *tube);
void	pipex(t_data *data, char *cmd, char **cmd_args);
void	print_dbg_data(t_data *data);

#endif