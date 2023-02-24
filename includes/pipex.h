
#ifndef PIPEX_H
# define PIPEX_H

# define BUFFER_SIZE 128

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

#include <stdio.h>
#include <assert.h>
#include <string.h>


char	*ft_realloc(char *ptr, size_t old_size, size_t new_size);
char	*read_file(int fd);
char	**get_bash_args(int argc, char **argv);
char	*get_command(int argc, char **argv);
size_t	ft_strlen(char *str);
char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_strcpy2(char *src);
char	*ft_strcpy(char *s1, char *s2);
char	*get_redirect(char **argv, int i, char *str);
char	*join_cmds(char *in_redirect, char *in_between_cmds,
			char *out_redirect);

#endif