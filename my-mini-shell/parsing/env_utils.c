#include "../header/header.h"

char	*ft_search_env_var(t_env_vars **envs, char *key)
{
	t_env_vars	*current;

	if (envs == NULL || *envs == NULL || key == NULL)
		return (NULL);
	current = *envs;
	while (current)
	{
		if (ft_strncmp(current->data->key, key,
				ft_strlen(current->data->key)) == 0)
			return (current->data->value);
		current = current->next;
	}
	return (NULL);
}

// void	ft_update_shlvl(t_shell *shell, t_token *token, t_env_vars **env)
// {
// 	char	*line;
// 	char	*lvl;

// 	if (ft_strnstr(token->str, "minishell", ft_strlen(token->str)) != NULL)
// 	{
// 		shell->shell_level++;
// 		lvl = ft_itoa(shell->shell_level);
// 		if (lvl == NULL)
// 			ft_malloc_error();
// 		line = ft_strjoin("SHLVL=", ft_itoa(shell->shell_level));
// 		if (line == NULL)
// 			ft_malloc_error();
// 		ft_remove_env_var(env, "SHLVL");
// 		ft_add_env_var(env, line);
// 		free(line);
// 		free(lvl);
// 	}
// }

void	ft_free_envs_vars(t_env_vars **envs)
{
	t_env_vars	*tmp;

	while (envs && *envs)
	{
		tmp = (*envs)->next;
		ft_remove_env_var(envs, (*envs)->data->key);
		*envs = tmp;
	}
}
