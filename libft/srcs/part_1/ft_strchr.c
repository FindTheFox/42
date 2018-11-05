char  *ft_strchr(const char *s, int c)
{
    char d;
    int i;

    d = (char)c;
    i = 0;
    while (s[i])
    {
        if (s[i] == d)
            return (&(str[i]));
        i++;
    }
    return (0);
}