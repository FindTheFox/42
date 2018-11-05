void    *bzero(void *s, size_t n)
{
    size_t a;

    a = 0;
    while (a < n)
        s[a++] = '\0';
    return (a);
}