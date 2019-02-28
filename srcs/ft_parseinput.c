#include "ft_ls.h"


// parcourir ligne par ligne tant que -
// si charactère pas une option, renvoyer usage et NULL

// renvoyer en path le premier,
// iteration sur les fonction plus hautes à partir de ce rang jusqu`à la fin du char**, les erreurs seront renvoyées dans ces fonction au moment de la lecture. attention, les erreurs de lecture sont renvoyées en première.

char		**ft_parseinput(int argc, char **argv)
{
	int		i;
	char	**res;
	char	*otps;
	char	*path;

	res = (char **)ft_memalloc(sizeof(char *) * 3);
	if (res == NULL)
		return (NULL)
	opts = (char *)ft_strnew(sizeof(char) * 5);
	if (opts == NULL)
	{
		free(res);
		return (NULL);
	}
	i = 1;
	while(i < argc && argv[i][0] == '-')
	{

		i++;
	}
	return (res);
}
