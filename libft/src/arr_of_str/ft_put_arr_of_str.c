
#include "../../includes/libft.h"

void			ft_put_arr_of_str(char ** arr)
{
    int i;

    i = 0;
    while (arr[i] != NULL)
        ft_putendl(arr[i++]);
}