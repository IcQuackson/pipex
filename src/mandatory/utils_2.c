
#include "../../includes/pipex.h"

char	*get_command(int argc, char **argv)
{
	char	*in_between_cmds;
	char	*input_redirect;
	char	*output_redirect;
	char	*joined;

	(void) in_between_cmds;
	(void) output_redirect;
	(void) argc;

	input_redirect = get_redirect(argv, 1, "< ");
	if (!input_redirect)
		return (NULL);
	output_redirect = get_redirect(argv, argc - 1, " > ");
	if (!output_redirect)
		return (NULL);
	in_between_cmds = ft_strjoin(argc - 3, argv + 2, " | ");
	printf("%s\n", in_between_cmds);
	if (!in_between_cmds)
		return (NULL);
	joined = join_cmds(input_redirect, in_between_cmds, output_redirect);
	free(input_redirect);
	free(in_between_cmds);
	free(output_redirect);
	return (joined);
}

char	*ft_strcpy(char *s1, char *s2)
	{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = s2[i];
	return (s1);
}

char	*ft_strcpy2(char *src)
{
	int		i;
	char	*new;

	new = malloc(ft_strlen(src) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = src[i];
	return (new);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		i;
	int		j;
	int		c;

	s = malloc(sizeof(strs));
	i = 0;
	c = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			s[c++] = strs[i][j++];
		}
		j = 0;
		while (sep[j] != '\0' && i != size - 1)
		{
			s[c++] = sep[j++];
		}
		i++;
	}
	s[c] = '\0';
	return (s);
}
