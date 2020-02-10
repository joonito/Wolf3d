/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:11:06 by julee             #+#    #+#             */
/*   Updated: 2020/02/09 18:11:12 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	move_forward(t_wf3d *wf3d, t_pointf d_unit, t_pointf c_unit)
{
	(void)c_unit;
	if ((int)(wf3d->my_pos.y + d_unit.y) < (int)wf3d->map_height
	&& (int)(wf3d->my_pos.x + d_unit.x) < (int)wf3d->map_width
	&& (wf3d->map[(int)(wf3d->my_pos.y + d_unit.y)][(int)(wf3d->my_pos.x + d_unit.x)] == 0))
	{
		wf3d->my_pos.x += d_unit.x * wf3d->speed;
		wf3d->my_pos.y += d_unit.y * wf3d->speed;
	}
}

void	move_backward(t_wf3d *wf3d, t_pointf d_unit, t_pointf c_unit)
{
	(void)c_unit;
	if ((int)(wf3d->my_pos.y + d_unit.y) < (int)wf3d->map_height
	&& (int)(wf3d->my_pos.x - d_unit.x) < (int)wf3d->map_width
	&& (wf3d->map[(int)(wf3d->my_pos.y - d_unit.y)][(int)(wf3d->my_pos.x - d_unit.x)] == 0))
	{
		wf3d->my_pos.x -= d_unit.x * wf3d->speed;
		wf3d->my_pos.y -= d_unit.y * wf3d->speed;
	}
}

void	move_leftside(t_wf3d *wf3d, t_pointf d_unit, t_pointf c_unit)
{
	(void)d_unit;
	if ((int)(wf3d->my_pos.y - c_unit.y) < (int)wf3d->map_height
	&& (int)(wf3d->my_pos.x - c_unit.x) < (int)wf3d->map_width
	&& (wf3d->map[(int)(wf3d->my_pos.y - c_unit.y)][(int)(wf3d->my_pos.x - c_unit.x)] == 0))
	{
		wf3d->my_pos.x -= c_unit.x * wf3d->speed;
		wf3d->my_pos.y -= c_unit.y * wf3d->speed;
	}
}

void	move_rightside(t_wf3d *wf3d, t_pointf d_unit, t_pointf c_unit)
{
	(void)d_unit;
	if ((int)(wf3d->my_pos.y + c_unit.y) < (int)wf3d->map_height
	&& (int)(wf3d->my_pos.x + c_unit.x) < (int)wf3d->map_width
	&& (wf3d->map[(int)(wf3d->my_pos.y + c_unit.y)][(int)(wf3d->my_pos.x + c_unit.x)] == 0))
	{
		wf3d->my_pos.x += c_unit.x * wf3d->speed;
		wf3d->my_pos.y += c_unit.y * wf3d->speed;
	}
}

void	key_press_move(t_wf3d *wf3d, int keycode)
{
	t_pointf d_unit = to_unit_vec(wf3d->direction);
	t_pointf c_unit = to_unit_vec(wf3d->camera_plane);
	if (keycode > 13)
		wf3d->move_fn[keycode % 123](wf3d, d_unit, c_unit);
	else if (keycode == KEY_A)
		move_leftside(wf3d, d_unit, c_unit);
	else if (keycode == KEY_D)
		move_rightside(wf3d, d_unit, c_unit);
	else if (keycode == KEY_S)
		move_backward(wf3d, d_unit, c_unit);
	else if (keycode == KEY_W)
		move_forward(wf3d, d_unit, c_unit);
	render(wf3d);
}
