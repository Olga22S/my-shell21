/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiger Agda <tagda@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:34:09 by Tiger Agda        #+#    #+#             */
/*   Updated: 2022/05/29 16:35:59 by Tiger Agda       ###   ########.fr       */
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
}
