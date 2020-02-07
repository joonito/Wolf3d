/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 22:22:49 by julee             #+#    #+#             */
/*   Updated: 2020/01/30 22:22:52 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static void set_hook(t_wf3d *wf3d)
{
	mlx_hook(wf3d->win_ptr, 2, 0, key_press, wf3d);
	mlx_hook(wf3d->win_ptr, 4, 0, mouse_press, wf3d);
	mlx_hook(wf3d->win_ptr, 6, 0, mouse_move, wf3d);
	mlx_hook(wf3d->win_ptr, 12, 0, refresh_img, wf3d);
	mlx_hook(wf3d->win_ptr, 17, 0, exit_by_red, wf3d);
	mlx_loop(wf3d->mlx_ptr);
}

static int	init_wolf3d(t_wf3d *wf3d)
{
	wf3d->mlx_ptr = mlx_init();
	wf3d->win_ptr = mlx_new_window(wf3d->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "wolf3d");
	wf3d->img_ptr = mlx_new_image(wf3d->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	wf3d->img_addr = mlx_get_data_addr(wf3d->img_ptr, &wf3d->bits_per_pixel, &wf3d->size_line, &wf3d->endian);

	if (START_POS_X < 0 || START_POS_X >= wf3d->map_width
	|| START_POS_Y < 0 || START_POS_Y >= wf3d->map_height)
		return (INVALID_STARTING);
	if (wf3d->map[START_POS_Y][START_POS_X] != 0)
		return (INVALID_STARTING);
	wf3d->my_pos = to_pointf(START_POS_X, START_POS_Y);	
	wf3d->direction = to_pointf(DIR_VEC_X, DIR_VEC_Y);
	wf3d->camera_plane = to_pointf(CAM_VEC_X, CAM_VEC_Y);
	wf3d->render_fn[0] = render_multi_1;
    wf3d->render_fn[1] = render_multi_2;
    wf3d->render_fn[2] = render_multi_3;
    wf3d->render_fn[3] = render_multi_4;
    wf3d->render_fn[4] = render_multi_5;
    wf3d->render_fn[5] = render_multi_6;
    wf3d->render_fn[6] = render_multi_7;
    wf3d->render_fn[7] = render_multi_8;
	return (NO_ERR);
}

static void	wolf3d(char *path)
{
	t_wf3d*	wf3d;
	
	wf3d = ft_memalloc(sizeof(t_wf3d));
	ft_putendl("point 0");
	if ((errno = map_extractor(path, wf3d)) != NO_ERR)
		mlx_del(wf3d);
	ft_putendl("point 1");
	if ((errno = init_wolf3d(wf3d)) != NO_ERR)
		mlx_del(wf3d);
	ft_putendl("point 2");
	if ((errno = render(wf3d)) != NO_ERR)
		mlx_del(wf3d);
	ft_putendl("point 3");
	set_hook(wf3d);
}

int			main(int ac, char ** av)
{	
	if (ac == 2)
		wolf3d(av[1]);
	else if (ac == 1)
		errno = NO_MAP;
	else
		errno = ARG_NOT_ONE;
	error_exit();
	return (0);
}
