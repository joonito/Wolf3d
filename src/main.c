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

static void	wolf3d(char *path)
{
	t_mlx*	mlx;
	
	mlx = ft_memalloc(sizeof(t_mlx));
	if ((errno = map_extractor(path, mlx)) != NO_ERR)
		mlx_del(mlx);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "wolf3d");
	mlx_hook(mlx->win_ptr, 2, 0, exit_by_esc, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, exit_by_red, mlx);
	mlx_loop(mlx->mlx_ptr);
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
