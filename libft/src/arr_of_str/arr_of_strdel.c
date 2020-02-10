
#include "../../includes/libft.h"

void	arr_of_strdel(char **arr)
{
    int i;

    i = 0;
    if (arr == NULL)
        return ;
    while (arr[i] != NULL)
        ft_memdel((void **)&(arr[i++]));
    ft_memdel((void **)&(arr[i]));
    ft_memdel((void **)&arr);
}