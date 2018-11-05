void    *ft_memset(void *s, int i, size_t n)
{
    size_t a;

    a = 0;
    while (a < n)
        s[a++] = i;
    return (s);
}