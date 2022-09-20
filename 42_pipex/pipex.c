/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:45:15 by maperez-          #+#    #+#             */
/*   Updated: 2022/09/20 13:57:53 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child(int *end, char **argv, char **envp)
{
	int		fd_file;
	char	*path;
	char	**args_execve;

	close(end[0]);                     // Child closes cmd2 stdin,
		we don't need it.
	fd_file = open(argv[1], O_RDONLY); // Open infile (returns int).
	ft_check_end(fd_file);             // Check for error.
	dup2(fd_file, STDIN_FILENO);       // Duplicate infiles fd.
	close(fd_file);
	dup2(end[1], STDOUT_FILENO); // Duplicate cmd1 stdout.
	close(end[1]);
	args_execve = ft_split(argv[2], ' ');    
		// Save every cmd1 order in a list.
	path = ft_get_path(args_execve[0], envp); // Using environment PATHS,
		check which is correct.
	if (execve(path, args_execve, envp) == -1)
	{
		perror("Pipex: command not found");
		ft_free_paths(args_execve);
		free(path);
		exit(EXIT_FAILURE);
	}
}

void	ft_parent(int *end, char **argv, char **envp)
{
	int		fd_file;
	char	*path;
	char	**args_execve;

	close(end[1]); // Parent closes cmd1 stdout.
	fd_file = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	// Open outfile in read-only mode, if it already exists,
		resets it to 0 and if it doens't, create it (returns int).
	ft_check_end(fd_file);      // Check for error.
	dup2(end[1], STDIN_FILENO); // Duplicate cmd2 stdin.
	close(end[1]);
	dup2(fd_file, STDOUT_FILENO); // Duplicate outfiles fd.
	close(fd_file);
	args_execve = ft_split(argv[3], ' ');    
		// Save every cmd2 order in a list.
	path = ft_get_path(args_execve[0], envp); // Using environment PATHS,
		check which is correct.
	if (execve(path, args_execve, envp) == -1)
	{
		perror("Pipex: command not found");
		ft_free_paths(args_execve);
		free(path);
		exit(EXIT_FAILURE);
	}
}

void	pipex(char **argv, char **envp)
{
	int	pid;

	int end[2]; // Int array to save stdout/stdin.
	pipe(end);    // Link both ends.
	pid = fork(); // Create subprocesses, now we have parent AND child.
	if (pid < 0)  // When -1 is error.
		perror("Fork: ");
	else if (pid != 0)                  // When 0 is child process.
		child_process(end, argv, envp);
			// Defines what to do when in child process.
	else                                // When other number is parent process.
	{
		pid = fork();
		if (pid < 0)
			perror("Fork: ");
		else if (!pid)                      
			// This time we'll treat 0 as parent...
			parent_process(end, argv, envp);
				// Defines what to do when in parent process.
		else
		{ // ...so any other number is used to close the pipes.
			close(end[0]);
			close(end[1]);
		}
	}
	waitpid(pid, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5) // Check correct input.
		return (EXIT_FAILURE);
	pipex(argv, envp); // Function call.
	return (0);
}