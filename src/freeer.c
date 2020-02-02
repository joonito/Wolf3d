
#include "../include/wolf3d.h"

static void     map_del(t_deque *map)
{
    t_deque *map_line;

    while (!is_empty_deque(map))
    {
        map_line = deque_front(map);
        deque_pop_front(map);
        while (!is_empty_deque(map_line))
        {
            free(deque_front(map_line));
            deque_pop_front(map_line);
        }
        ft_memdel((void **)&map_line);
    }
    ft_memdel((void **)&map);
}

void            mlx_del(t_mlx *mlx)
{
    if (mlx->mlx_ptr != NULL)
        free(mlx->mlx_ptr);
    if (mlx->win_ptr != NULL)
        free(mlx->win_ptr);
    if (mlx->map != NULL)
        map_del(mlx->map);
    error_exit();
}