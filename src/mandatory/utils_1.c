
#include "../../includes/pipex.h"

#include <errno.h>

char	**get_bash_args(int argc, char **argv)
{
	char	**args;

	args = malloc(4 * sizeof(char *));
	args[0] = ft_strcpy2("bash");
	args[1] = ft_strcpy2("-c");
	args[2] = get_command(argc, argv);
	args[3] = NULL;
	return (args);
}

char	*read_file(int fd)
{
	int		len;
	int		count;
	int		n;
	char	*str;

	n = 0;
	len = 0;
	str = NULL;
	while (1)
	{
		if (n * BUFFER_SIZE == len)
		{
			str = ft_realloc(str, len, len + BUFFER_SIZE + 1);
			if (!str)
				return (NULL);
			n++;
		}
		count = read(fd, str + len, BUFFER_SIZE);
		if (count == -1)
			return (NULL);
		if (count == 0)
			break ;
		len += count;
	}
	return (str);
}

char	*ft_realloc(char *ptr, size_t old_size, size_t new_size)
{
	char	*new_ptr;
	size_t	i;
	size_t	copy_size;

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (ptr != NULL)
	{
		if (old_size < new_size)
			copy_size = old_size;
		else
			copy_size = new_size;
		i = 0;
		while (i < copy_size)
		{
			new_ptr[i] = ptr[i];
			i++;
		}
		new_ptr[i] = '\0';
		free(ptr);
	}
	return (new_ptr);
}
