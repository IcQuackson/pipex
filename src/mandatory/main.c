
#include "../../includes/pipex.h"

int	main(int argc, char **argv)
{
	int		fd_in;
	int		fd_out;
	char	*infile_contents;
	char	**args;
	pid_t	pid;

	if (argc < 5)
		return (0);
	args = get_bash_args(argc, argv);
	int i = 0;
	while (args[i] != NULL)
	{
		printf("args: %s\n",args[i]);
		i++;
	}
	//for (int i = 0;)
	//char *args[] = {"bash", "-c", "ls -l $(cat input.txt) | wc -l > output.txt", NULL};

	
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
	{
		printf("Failed to open file 1\n");
		return (0);
	}
	infile_contents = read_file(fd_in);
	if (infile_contents == NULL)
	{
		printf("Failed to read file 1 contents");
		return (0);
	}
	printf("%s\n", infile_contents);
	fd_out = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		execve("/bin/bash", args, NULL);
		perror("Failed to execute bash command");
		free(args);
		free(infile_contents);
		exit(1);
	}
	else if (pid < 0)
	{
		perror("Failed to fork");
		exit(1);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
		close(fd_in);
		close(fd_out);
	}
	free(args);
	free(infile_contents);
	return (0);
}

