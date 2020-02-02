#include "../include/wolf3d.h"

int exit_by_red(void *param)
{
    t_mlx *mlx = param;
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	ft_printf("%s\n", "Program is closed");
    exit(EXIT_SUCCESS);
}

int	exit_by_esc(int keycode, void *param)
{
	if (keycode == 53)
	{
		t_mlx *mlx = param;
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_printf("%s\n", "Program is closed");
		exit(EXIT_SUCCESS);
	}
	return (0);
}