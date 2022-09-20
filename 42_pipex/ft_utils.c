/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:45:21 by maperez-          #+#    #+#             */
/*   Updated: 2022/09/20 13:57:38 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_all_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

void	ft_check_fd(int fd)
{
	if (fd == -1)
		perror("Pipex: ");
}

char	**ft_get_all_paths(char **envp)
{
	int		i;
	char	*ensure_paths;
	char	**paths;

	i = 0; // Find which path we need.
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i]) // If we can't find it, the program will end.
		return (NULL);
	ensure_paths = ft_strchr(envp[i], '/'); // Find first folder.
	paths = ft_split(ensure_paths, ':');    // Save paths in a list.
	return (paths);
}

char	*ft_get_path(char *cmd, char **envp)
{
	char **all_paths;
	char *path;
	int i;
	int end;

	all_paths = ft_get_all_paths(envp);
	i = 0;
	while (all_paths[i])
	{ // First create the correct path and join the first cmd.
		path = ft_strjoin(ft_strjoin(all_paths[i], "/"), cmd);
		end = open(path, O_RDONLY);
		if (end >= 0)
		{                             // If we open that path and ends fine ...
			ft_free_paths(all_paths); // ... clear everything ...
			close(end);               // ... close its fd ...
			return (path);            // ... and return it.
		}
		free(path); // Only delete everything ...
		i++;
	}
	ft_free_paths(all_paths); // ... when we can't find the right path.
	return (NULL);
}