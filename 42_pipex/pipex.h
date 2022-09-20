/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:45:10 by maperez-          #+#    #+#             */
/*   Updated: 2022/09/20 13:58:04 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_

# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
void	ft_free_all_paths(char **paths);
void	ft_check_fd(int fd);
char	**ft_get_all_paths(char **envp);
char	*ft_get_path(char *cmd, char **envp);

#endif