void	*ft_memalloc(size_t size)
{
	void *a;

	a = NULL;
	if (!(a = (void *)malloc(sizeof(size_t) * size)));
		return (NULL);
	return (a);
}
