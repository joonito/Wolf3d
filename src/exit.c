#include "../include/wolf3d.h"

int exit_by_red(void *param)
{
    t_wf3d *wf3d = param;
	mlx_destroy_image(wf3d->mlx_ptr, wf3d->img_ptr);
	mlx_clear_window(wf3d->mlx_ptr, wf3d->win_ptr);
	mlx_destroy_window(wf3d->mlx_ptr, wf3d->win_ptr);
	ft_printf("%s\n", "Program is closed");
    exit(EXIT_SUCCESS);
}

int exit_by_esc(t_wf3d *wf3d)
{
	mlx_clear_window(wf3d->mlx_ptr, wf3d->win_ptr);
	mlx_destroy_window(wf3d->mlx_ptr, wf3d->win_ptr);
	ft_printf("%s\n", "Program is closed");
	exit(EXIT_SUCCESS);
}