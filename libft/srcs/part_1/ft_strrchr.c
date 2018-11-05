char    *ft_strrchr(const char *s, int c)
{
    char d;
    int i;
    int ad;

    ad = 0;
    d = (char)c;
    i = 0;
    while (s[i])
    {
        if (s[i] == d)
            ad = &(s[i]);
        i++;
    }
    return (ad);
}