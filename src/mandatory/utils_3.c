
#include "../../includes/pipex.h"

char	*get_redirect(char **argv, int i, char *str)
{
	char	*redirect;

	redirect = malloc(ft_strlen(argv[i]) + ft_strlen(str) + 1);
	if (!redirect)
		return (NULL);
	ft_strcpy(redirect, str);
	ft_strcpy(redirect + ft_strlen(str), argv[i]);
	return (redirect);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*join_cmds(char *in_redirect, char *in_between_cmds, char *out_redirect)
{
	char	*joined;
	int		in_redirect_len;
	int		in_between_cmds_len;
	int		out_redirect_len;

	in_redirect_len = ft_strlen(in_redirect);
	in_between_cmds_len = ft_strlen(in_between_cmds);
	out_redirect_len = ft_strlen(out_redirect);

	joined = malloc(in_redirect_len + in_between_cmds_len
			+ out_redirect_len + 2);
	if (!joined)
		return (NULL);
	ft_strcat(joined, in_redirect);
	joined[in_redirect_len] = ' ';
	ft_strcat(joined + in_redirect_len + 1, in_between_cmds);
	ft_strcat(joined + in_redirect_len + 1 + in_between_cmds_len, out_redirect);
	return (joined);
}
