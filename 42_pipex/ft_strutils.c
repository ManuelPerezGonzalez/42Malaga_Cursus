
#include "pipex.h"

size_t  ft_strlen(const char *str)
{ // Return str length.
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strchr(const char *str, int c)
{ // Search for a specified char in a string.
    char    *s;

    s = (char *)str;
    while (*s && *s != (char)c)
        s++;
    if (*s == (char)c)
        return (s);
    return (0);
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{ // Compare n characters from NULL terminated strings s1 and s2.
    size_t  i;

    i = 0;
    while ((s1[1] == s2[i] && s1[i] != '\0' && s2[i] != '\0') && i < n - 1)
        i++;
    if (n == 0)
        return (0);
    else // Return the difference (int).
        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char    *ft_strjoin(const char *s1, const char *s2)
{ // Merge 2 given strings.
    char    *str;
    size_t  strlen;
    size_t  i;
    size_t  j;

    strlen = ft_strlen(s1) + ft_strlen(s2); // Total length.
    str = ft_calloc(strlen + 1, sizeof(char));
    if (!strlen) // Memory checking.
        return (0);
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    j = 0;
    while (s1[j])
    { // To join last s1 position (i) and first s2 position (j) in str.
        str[i + j] = s2[j];
        j++;
    }
    return (str);
}