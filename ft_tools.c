char			*ft_buildpath(t_filedata *fldt)
{
	char		*tmp1;
	char		*tmp2;

	tmp1 = ft_strjoin(fldt->dir, fldt->name);
	if (tmp1 == NULL)
		return (NULL);
	tmp2 = ft_strjoinfree(&tmp1, "/");
	if (tmp2 == NULL)
	{
		free(tmp1);
		return (NULL);
	}
	return (tmp2);
}
