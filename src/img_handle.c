#include "../include/wolf3d.h"

int     prepare_new_img(void *param)
{
    t_wf3d *wf3d = param;
    if (wf3d->img_ptr != NULL)
    {
        mlx_destroy_image(wf3d->mlx_ptr, wf3d->img_ptr);
        wf3d->img_ptr = mlx_new_image(wf3d->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
        wf3d->img_addr = mlx_get_data_addr(wf3d->img_ptr, &wf3d->bits_per_pixel, &wf3d->size_line, &wf3d->endian);
    }
    return (0);
}

int     refresh_img(void *param)
{
    t_wf3d *wf3d = param;
    if (wf3d->state_change == true) {
        mlx_put_image_to_window(wf3d->mlx_ptr, wf3d->win_ptr, wf3d->img_ptr, 0, 0);
        wf3d->state_change = false;
    }
    return (0);
}
