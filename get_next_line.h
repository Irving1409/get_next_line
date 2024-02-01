/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ircaetan <ircaetan@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:45:27 by ircaetan          #+#    #+#             */
/*   Updated: 2024/01/31 22:35:04 by ircaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif 

# include <unistd.h>
# include <stdlib.h>

int		find_n(char *line);
char	*ft_strjoin(char *buffer, char *line);
char	*gnl_second_part_of(char *buffer);
char	*gnl_first_part_of(char *buffer);
char	*get_next_line(int fd);

#endif
