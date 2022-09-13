#ifndef PIPEX_

# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcnt1.h>

char    **ft_split(char const *s, char c);
char    *ft_strchr(const char *str, int c);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strjoin(const char *s1, const char *s2);
void    ft_free_all_paths(char **paths);
void    ft_check_fd(int fd);
char    **ft_get_all_paths(char **envp);
char    *ft_get_path(char *cmd, char **envp);

#endif