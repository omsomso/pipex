/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:16:01 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/09 13:14:43 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
	int		f1;
	int		f2;
} t_data;

void	free_pointer_array(char **s);
void	free_everything(t_data *data);
char	*get_command_path(char **env, char *cmd);
int	init_data(t_data *data, char **args, char *env);
int	child_one(t_data *data, int *tube);
int	child_two(t_data *data, int *tube);
void	pipex(t_data *data);
void	print_dbg_data(t_data *data);

#endif