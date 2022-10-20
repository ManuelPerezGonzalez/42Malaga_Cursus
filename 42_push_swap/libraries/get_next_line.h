/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:37:10 by maperez-          #+#    #+#             */
/*   Updated: 2022/10/19 15:50:48 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 20
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_cut_line(char *memom);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		ft_is_line(char *memom, int n);
char	*ft_strjoin(char *memom, char *buff, int n);
int		ft_line_len(char *memom);
char	*ft_get_line(char *memom);

#endif