/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpajuelo <jpajuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:35:21 by jpajuelo          #+#    #+#             */
/*   Updated: 2023/08/16 17:24:09 by jpajuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void	ft_children(char **argc, char **envp, int *fd, int *pipefd)
{
	pid_t	access;

	access = fork();
	if (access < 0)
		error();
	if (access == 0)
	{
		fd[0] = open(argc[1], O_RDONLY, 0777);
		if (fd[0] == -1)
			error();
		close(pipefd[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		execute(argc[2], envp);
	}
}

static	void	ft_children2(char **argc, char **envp, int *fd, int *pipefd)
{
	pid_t	access;

	access = fork();
	if (access < 0)
		error();
	if (access == 0)
	{
		fd[1] = open(argc[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd[1] == -1)
			error();
		close(pipefd[1]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		execute(argc[3], envp);
	}
}

int	main(int arc, char **argc, char **envp)
{
	int		fd[2];
	int		pipefd[2];
	int		result;

	if (arc == 5)
	{
		if (envp[0] == NULL && (argc[2][0] != '/' || argc[3][0] != '/'))
		{
			error();
		}
		if (pipe(pipefd) == -1)
			error();
		ft_children(argc, envp, fd, pipefd);
		ft_children2(argc, envp, fd, pipefd);
		close(pipefd[0]);
		close(pipefd[1]);
		waitpid(-1, &result, 0);
		waitpid(-1, &result, 0);
	}
	else
	{
		ft_putstr_fd("ERROR ARGUMENTS\n", 2);
		ft_putstr_fd("ex: ./pipex file1 <cmd1> <cmd2> file2 \n", 1);
	}
	return (0);
}
