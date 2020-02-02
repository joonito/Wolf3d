
#include "../../includes/libft.h"

size_t  arr_of_strlen(char **arr)
{
    size_t i;

    i = 0;
    while (arr[i] != NULL)
        i++;
    return (i);
}