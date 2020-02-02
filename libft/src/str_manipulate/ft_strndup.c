
#include "../../includes/libft.h"

char			*ft_strndup(const char *s, size_t n)
{
    int     i;
    char    *src;
    char    *dup;

    if (!(dup = ft_strnew(n)))
        return (NULL);
    src = (char *)s;
    i = 0;
    while (n && *src != '\0')
    {
        dup[i++] = *src++;
        n--;
    }
    // ft_putendl(s);
    return (dup);
}