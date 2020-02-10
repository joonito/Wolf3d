/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:00:42 by julee             #+#    #+#             */
/*   Updated: 2020/02/09 18:20:42 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		prepare_new_img(void *param)
{
	t_wf3d *wf3d;

	wf3d = param;
	if (wf3d->img_ptr != NULL)
	{
		mlx_destroy_image(wf3d->mlx_ptr, wf3d->img_ptr);
		wf3d->img_ptr = mlx_new_image(wf3d->mlx_ptr
				, WINDOW_WIDTH, WINDOW_HEIGHT);
		wf3d->img_addr = mlx_get_data_addr(wf3d->img_ptr
				, &wf3d->bits_per_pixel, &wf3d->size_line, &wf3d->endian);
	}
	return (0);
}
