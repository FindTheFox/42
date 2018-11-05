char	*ft_strnew(size_t size)
{
	char *str;
	int i;

	if (!(str = (char *)malloc(sizeof(size_t) * size)))
		return (NULL);
	i = 0;
	while (str[i])
		str[i++] = '\0';
	return (str);
}
