#include "ft_ls.h"


// parcourir ligne par ligne tant que -
// si charactère pas une option, renvoyer usage et NULL

char	*ft_getopt(char input, char *buf)
{
	if (input == 'l')
		buf[0] = 'l';
	else if (input == 'R')
		buf[1] = 'R';
	else if (input == 'a')
		buf[2] = 'a';
	else if (input == 'r')
		buf[3] = 'r';
	else if (input == 't')
		buf[4] = 't';
	else
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

char	*ft_readopt(char *input, char *buf)
{
	int		i;

	i = 1;
	while (input[i])
	{
		buf = ft_getopt(input[i], buf);
		if (buf == NULL)
			return (NULL);
		i++;
	}
	return (buf);
}

// iteration sur les fonction plus hautes à partir de ce rang jusqu`à la fin du char**, les erreurs seront renvoyées dans ces fonction au moment de la lecture. attention, les erreurs de lecture sont renvoyées en première.

char		*ft_parseopts(int argc, char **argv)
{
	int		i;
	char	*opts;

	opts = (char *)ft_strnew(sizeof(char) * 5);
	opts = ft_memset(opts, '-', 5);
	if (opts == NULL)
		return (NULL);
	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		opts = ft_readopt(argv[i], opts);
		if (opts == NULL)
		{
//			write usage;
			return (NULL);
		}
		i++;
	}
	return (opts);
}

