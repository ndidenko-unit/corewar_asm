#include "asm.h"

char	*ft_strstr_d(char *str, char *to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[0] == '\0' || to_find[0] == '#')
		return (str);
	while (str[i] != '\0' && str[i] != '#')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0' || to_find[j] == '#')
				return (str + i);
		}
		i++;
	}
	return (0);
}

void	ft_putstr_d(char const *s)
{
	if (s != NULL)
	{
		while (*s && *s != '#')
			ft_putchar(*s++);
	}
}

char	*ft_strjoin_n(char *line, char *line2, int flag)
{
	char	*line3;
	char	*line4;

	if (!line2 || !line)
		return (NULL);
	line3 = ft_strdup(line);
    line4 = ft_strdup(line2);
	ft_strdel(&line);
	line = ft_strjoin(line3, line4);
	if (flag == 1)
		ft_strdel(&line2);
	ft_strdel(&line3);
	line3 = ft_strdup(line);
	ft_strdel(&line);
	line = ft_strjoin(line3, "\n");
	ft_strdel(&line3);
	ft_strdel(&line4);
	return (line);
}

char	*ft_strdup_d(const char *string, char d)
{
	char	*strcopy;
	size_t	i;

	i = 0;
	strcopy = (char*)malloc(sizeof(char) * ft_strlen(string) + 1);
	if (strcopy == 0)
		return (0);
	while (string[i] && string[i] != d)
	{
		strcopy[i] = string[i];
		i++;
	}
	strcopy[i] = '\0';
	return (strcopy);
}
