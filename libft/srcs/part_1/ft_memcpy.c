void    *memcpy(void *dest, const void *src, size_t n)
{
    size_t a;

    a = 0;
    while (a < n)
    {
        dest[a] = src[a];
        a++;
    }
    return (dest);
}