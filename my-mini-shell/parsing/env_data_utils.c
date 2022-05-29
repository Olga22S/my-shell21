/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_data_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiger Agda <tagda@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:31:22 by Tiger Agda        #+#    #+#             */
/*   Updated: 2022/05/29 16:31:38 by Tiger Agda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

static t_environment_var	*create_new_var(char *str)
{
	int					i;
	int					j;
	t_environment_var	*new_var;

	new_var = (t_environment_var *) malloc(sizeof(t_environment_var));
	if (new_var == NULL)
		ft_malloc_error();
	i = 0;
	while (str[i] != '=')
		i++;
	new_var->key = ft_substr(str, 0, i);
	if (new_var->key == NULL)
		ft_malloc_error();
	j = i + 1;
	while (str[j] != '\0' && str[j] != '\n')
		j++;
	new_var->value = ft_substr(str, i + 1, j - i);
	if (new_var->value == NULL)
		ft_malloc_error();
	return (new_var);
}

static t_env_vars	*create_envs_element(char *str)
{
	t_env_vars	*new_elem;

	new_elem = (t_env_vars *) malloc(sizeof(t_env_vars));
	if (new_elem == NULL)
		ft_malloc_error();
	new_elem->data = create_new_var(str);
	new_elem->next = NULL;
	return (new_elem);
}

void	ft_add_env_var(t_env_vars **envs, char *str)
{
	t_env_vars	*current;

	if (str == NULL)
		return ;
	if (*envs == NULL)
		*envs = create_envs_element(str);
	else
	{
		current = *envs;
		while (current->next)
			current = current->next;
		current->next = create_envs_element(str);
	}
}

static void	free_env_var(t_env_vars	*var)
{
	free(var->data->key);
	free(var->data->value);
	free(var->data);
	free(var);
}

void	ft_remove_env_var(t_env_vars **envs, char *key)
{
	t_env_vars	*current;
	t_env_vars	*tmp;

	if (envs == NULL || *envs == NULL || key == NULL)
		return ;
	current = *envs;
	if (ft_strncmp(current->data->key, key, ft_strlen(key)) == 0)
	{
		tmp = current->next;
		free_env_var(current);
		*envs = tmp;
	}
	while (current && current->next != NULL)
	{
		if (ft_strncmp(key, current->next->data->key,
				ft_strlen(key)) == 0)
		{
			tmp = current->next->next;
			free_env_var(current->next);
			current->next = tmp;
			return ;
		}
		current = current->next;
	}
	return ;
}
