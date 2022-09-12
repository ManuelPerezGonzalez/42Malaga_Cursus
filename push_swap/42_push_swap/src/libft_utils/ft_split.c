#include "push_swap.h"

int ft_count_words(char const *s, char c)
{
    int i;
    int word_num;

    i = 0;
    while (s[i] && s[i] == c) // Ignore any "c" repeats at the beginning. 
        i++;
    if (!s[i]) // Check if we're already at the end.
        return (0);
    word_num = 1; // Found first "word".
    while (s[i])
    { // Eliminate every possible "c" character repetition between words...
        if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
            word_num++; // ...while counting them.
        i++;
    }
    return (word_num);
}

char    *ft_malloc_str(const char *s, char c)
{
    int i;
    char    *word;

    i = 0;
    while (s[i] && s[i] != c)
        i++; // Check how big the word is...
    word = (char *)ft_calloc((i + 1), sizeof(char));
    if (!word) // ...and if we have enough space.
        return (0);
    i = 0;
    while (s[i] && s[i] != c)
    { // Then, save and return it.
        word[i] = s[i];
        i++;
    }
    return (word);
}

char    **ft_split(char const *s, char c)
{
    int i;
    int word_num;
    char    **strlist;

    if (!s) // Check correct input.
        return (0);
    word_num = ft_count_words(s, c); // Save words total.
    strlist = (char **)malloc(sizeof(char *) * (word_num + 1)); // Allocate memory...
    if (!strlist) // ...and check if there's enough.
        return (0);
    i = 0;
    while (*s)
    {
        while (*s && *s == c)
            s++;
        if (*s && *s != c)
        {
            strlist[i] = ft_malloc_str(s, c);
            i++;
            while (*s && *s != c)
                s++;
        }
    }
    strlist[i] = 0;
    return (strlist);
}