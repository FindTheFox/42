int     memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        while (s1[i] == s2[i])
            i++;
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}