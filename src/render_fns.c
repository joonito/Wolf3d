/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:11:50 by julee             #+#    #+#             */
/*   Updated: 2020/02/09 22:16:06 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	init_var(t_wf3d *wf3d, t_render *rd)
{
	rd->camera_x = (double)(2 * rd->x) / (double)WINDOW_WIDTH - 1;
	rd->ray_dir_x = wf3d->direction.x + wf3d->camera_plane.x * rd->camera_x;
	rd->ray_dir_y = wf3d->direction.y + wf3d->camera_plane.y * rd->camera_x;
	rd->map_x = wf3d->my_pos.x;
	rd->map_y = wf3d->my_pos.y;
	rd->delta_dist_x = abs_flt(1 / rd->ray_dir_x);
	rd->delta_dist_y = abs_flt(1 / rd->ray_dir_y);
	rd->step_x = 0;
	rd->step_y = 0;
	rd->hit = 0;
}

void	set_step(t_wf3d *wf3d, t_render *rd)
{
	if (rd->ray_dir_x < 0)
	{
		rd->step_x = -1;
		rd->side_dist_x = (wf3d->my_pos.x - rd->map_x) * rd->delta_dist_x;
	}
	else
	{
		rd->step_x = 1;
		rd->side_dist_x = (rd->map_x + 1.0 - wf3d->my_pos.x) * rd->delta_dist_x;
	}
	if (rd->ray_dir_y < 0)
	{
		rd->step_y = -1;
		rd->side_dist_y = (wf3d->my_pos.y - rd->map_y) * rd->delta_dist_y;
	}
	else
	{
		rd->step_y = 1;
		rd->side_dist_y = (rd->map_y + 1.0 - wf3d->my_pos.y) * rd->delta_dist_y;
	}
}

int		find_hit(t_wf3d *wf3d, t_render *rd)
{
	while (rd->hit == 0)
	{
		if (rd->side_dist_x < rd->side_dist_y)
		{
			rd->side_dist_x += rd->delta_dist_x;
			rd->map_x += rd->step_x;
			if (rd->map_x < 0 || rd->map_x >= (int)wf3d->map_width)
				return (false);
			rd->side = 0;
		}
		else
		{
			rd->side_dist_y += rd->delta_dist_y;
			rd->map_y += rd->step_y;
			if (rd->map_y < 0 || rd->map_y >= (int)wf3d->map_height)
				return (false);
			rd->side = 1;
		}
		if (wf3d->map[rd->map_y][rd->map_x] > 0)
			rd->hit = 1;
	}
	return (true);
}

void	color_picker(t_wf3d *wf3d, t_render *rd)
{
	int sd;
	int type;

	rd->side_dir = 0;
	if (rd->side == 0 && rd->map_x >= wf3d->my_pos.x)
		rd->side_dir = 0;
	else if (rd->side == 0 && rd->map_x < wf3d->my_pos.x)
		rd->side_dir = 1;
	else if (rd->side == 1 && rd->map_y >= wf3d->my_pos.y)
		rd->side_dir = 2;
	else if (rd->side == 1 && rd->map_y < wf3d->my_pos.y)
		rd->side_dir = 3;
	sd = rd->side_dir;
	if ((0 <= rd->map_y && rd->map_y < (int)wf3d->map_height)
	&& (0 <= rd->map_x && rd->map_x < (int)wf3d->map_width))
		type = wf3d->map[rd->map_y][rd->map_x];
	else
		type = 0;
	rd->color = wf3d->color_arr[(sd + type) % 5];
	if (rd->side == 1)
		rd->color = rd->color / 3 * 2;
}

void	calculate_distance(t_wf3d *wf3d, t_render *rd)
{
	if (rd->side == 0)
		rd->perp_wall_dist = (rd->map_x - wf3d->my_pos.x\
				+ (1 - rd->step_x) / 2) / rd->ray_dir_x;
	else
		rd->perp_wall_dist = (rd->map_y - wf3d->my_pos.y\
				+ (1 - rd->step_y) / 2) / rd->ray_dir_y;
	if (rd->perp_wall_dist == 0)
		rd->perp_wall_dist = 0.001;
	rd->line_height = (int)(WINDOW_HEIGHT / rd->perp_wall_dist) * WALL_HEIGHT;
	rd->draw_start = -rd->line_height / 2 + WINDOW_HEIGHT / 2;
	if (rd->draw_start < 0)
		rd->draw_start = 0;
	rd->draw_end = rd->line_height / 2 + WINDOW_HEIGHT / 2;
	if (rd->draw_end >= WINDOW_HEIGHT)
		rd->draw_end = WINDOW_HEIGHT - 1;
}
