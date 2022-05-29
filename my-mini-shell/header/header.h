/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiger Agda <tagda@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:32:08 by Tiger Agda        #+#    #+#             */
/*   Updated: 2022/05/29 16:41:32 by Tiger Agda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/syslimits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>

# include "../libft/libft.h"

typedef struct s_environment_var
{
	char	*key;
	char	*value;
}	t_environment_var;

typedef struct s_env_vars
{
	t_environment_var		*data;
	struct s_env_vars		*next;
}	t_env_vars;

typedef struct s_shell
{
	pid_t	pid;
	int		std_in;
	int		std_out;
	int		f_in;
	int		f_out;
	int		process_level;
	int		exit_status;
	char	*tmpfile;
	int		shell_level;
	bool	executed;
	bool	is_running;
}	t_shell;

void	ft_parse_env_vars(t_env_vars **env_vars, char **env);
void	ft_add_env_var(t_env_vars **envs, char *str);
void	ft_remove_env_var(t_env_vars **envs, char *key);

#endif