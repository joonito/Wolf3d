
#include "../include/wolf3d.h"

static void     map_del(t_wf3d *wf3d)
{
    int **map = wf3d->map;
    int i = 0;

    while ((size_t)i < wf3d->map_height)
        ft_memdel((void **)&map[i++]);
    ft_memdel((void **)&map);
}

void            mlx_del(t_wf3d *wf3d)
{
    if (wf3d->mlx_ptr != NULL)
        free(wf3d->mlx_ptr);
    if (wf3d->win_ptr != NULL)
        free(wf3d->win_ptr);
    if (wf3d->map != NULL)
        map_del(wf3d);
    error_exit();
}