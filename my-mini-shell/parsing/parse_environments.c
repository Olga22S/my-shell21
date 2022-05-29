/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_environments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiger Agda <tagda@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:31:50 by Tiger Agda        #+#    #+#             */
/*   Updated: 2022/05/29 16:31:59 by Tiger Agda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void	ft_parse_env_vars(t_env_vars **env_vars, char **env)
{
	int	i;

	if (env == NULL)
		return ;
	i = 0;
	while (env[i])
		ft_add_env_var(env_vars, env[i++]);
}
