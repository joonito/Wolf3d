/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:11:18 by julee             #+#    #+#             */
/*   Updated: 2020/02/09 23:11:58 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	render_partition(t_wf3d *wf3d, int start, int end)
{
	t_render *rd;

	rd = ft_memalloc(sizeof(t_render));
	rd->x = start;
	while (rd->x < end)
	{
		init_var(wf3d, rd);
		set_step(wf3d, rd);
		if (find_hit(wf3d, rd) == false)
			return ;
		calculate_distance(wf3d, rd);
		color_picker(wf3d, rd);
		img_line_put(wf3d, to_point(rd->x, 0), to_point(rd->x\
					, rd->draw_start), CEILING);
		img_line_put(wf3d, to_point(rd->x, rd->draw_start)\
				, to_point(rd->x, rd->draw_end), rd->color);
		img_line_put(wf3d, to_point(rd->x, rd->draw_end)\
				, to_point(rd->x, WINDOW_HEIGHT), FLOOR);
		rd->x++;
	}
	free(rd);
}

int		render(t_wf3d *wf3d)
{
	int	i;

	prepare_new_img(wf3d);
	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_create(&(wf3d->threads[i]), NULL, wf3d->render_fn[i], wf3d);
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_join((wf3d->threads[i]), NULL);
		i++;
	}
	mlx_put_image_to_window(wf3d->mlx_ptr, wf3d->win_ptr, wf3d->img_ptr, 0, 0);
	return (NO_ERR);
}
