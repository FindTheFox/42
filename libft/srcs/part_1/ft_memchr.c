void    *memchr(const void *s, int c, size_t n)
{
    size_t a;
    unsigned char *s2;
    unsigned char d;

    s2 = (unsigned char *)s;
    d = (unsigned char)c;
    a = 0;
    while (a < n)
    {
        if (s2[a] == d)
            return(&(s2[a]));
        a++;
    }
    return (NULL);
}