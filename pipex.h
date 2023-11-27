/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpajuelo <jpajuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:39:29 by jpajuelo          #+#    #+#             */
/*   Updated: 2023/08/16 17:07:04 by jpajuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include "libft/libft.h"

char	*find_path(char *cmd, char **envp);
void	execute(char *str, char **envp);
void	error(void);
void	ft_clean(int i, char **paths);

int		main(int arc, char **argc, char **envp);

#endif