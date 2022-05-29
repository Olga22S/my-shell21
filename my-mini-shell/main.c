/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiger Agda <tagda@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:34:09 by Tiger Agda        #+#    #+#             */
/*   Updated: 2022/05/29 23:38:29 by Tiger Agda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

int	main(int argc, char **argv, char **env)
{
	t_shell		shell;
	t_env_vars	*env_vars;

	(void) argc;
	(void) argv;
	env_vars = NULL;
	ft_parse_env_vars(&env_vars, env);
	if (ft_search_env_var(&env_vars, "SHLVL"))
		shell.shell_level = ft_atoi(ft_search_env_var(&env_vars, "SHLVL"));
	else
		shell.shell_level = SHLVL_DEFAULT;
	shell.tmpfile = ft_strjoin(TMP_PATH, TMP_FILE);
	if (shell.tmpfile == NULL)
		ft_malloc_error();
	shell.std_in = dup(0);
	shell.std_out = dup(1);
	if (shell.std_in == -1 || shell.std_out == -1)
		exit(ER_DUP);
}
