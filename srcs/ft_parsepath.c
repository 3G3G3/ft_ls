#include "ft_ls.h"

int			ft_getindexfirstpath(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc && argv[i][0] == '-')
		i++;
	return (i);
}

DIR			*ft_opendir(char *path)
{
	DIR		*res;

	res = opendir(path);
	if (res == NULL)
	{
		ft_putendl("wrong directory");
		return (NULL);
	}
	return (res);
}

t_list		*ft_readpathinput(int argc, char **argv, char *opts)
{
	int			i;
	DIR			*fd_dir;
	t_list		*tmp;
	t_list		*res;

	opts = (void *)opts;
	i = ft_getindexfirstpath(argc, argv);
	if (i == argc)
	{
		fd_dir = ft_opendir("./");
		if (fd_dir == NULL)
			return (NULL);
		res = ft_lstnew(fd_dir, sizeof(DIR));
		if (res == NULL)
			return (NULL);
		return (res);
	}
	fd_dir = ft_opendir(argv[i]);
	if (fd_dir == NULL)
			return (NULL);
	res = ft_lstnew(fd_dir, sizeof(DIR));
		if (res == NULL)
			return (NULL);
	i++;
	while (i < argc)
	{
		fd_dir = ft_opendir(argv[i]);
		if (fd_dir == NULL)
				return (NULL);
		tmp = ft_lstnew(fd_dir, sizeof(DIR));
		if (tmp == NULL)
		{
//			free(res) et le contenu;
			return (NULL);
		}
//		ft_lstsortedadd(&res, tmp, opts);
		i++;
	}
	return (res);
}

/*
## creer une struture avec le fd le nom et la date de mofication, sur laquelle on opere le tri,
## on se complique la vie (a remonte dans l'arborescence) seulement si l'option -t est appelee
## on peut alors afficher le message d'rreur si le dossier ou le fichiern'existe pas
## on parcourt ensuite la liste de fd quel'on lit avec la structure du main.
*/

/*
## parser de path :
reperer les fichiers du repertoire courant des autres (. .. oup presence /)
chacun ont un traitement different: construction d'une liste qui remplace de readlvl0
les courant : lecture du repertoire courant et v2rification de la correspondance.
les autres: ont les lits directs, en s'y deplacant mainis s'arretant a l'avant dernier du chemin normalise./ (parcourt de la chaine de charactere par la fin)
on stocke les data de chaque fichiers dans une liste. 

## si pas de \ et diff2rent de ..: on est dans le repertoire courant
## sinon on se deplance
*/
