/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:07:20 by julee             #+#    #+#             */
/*   Updated: 2020/02/09 18:23:49 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int	mouse_press(int button, int x, int y, void *param)
{
	t_wf3d		*wf3d;
	t_pointf	d_unit;

	x = 0;
	y = 0;
	wf3d = param;
	d_unit = to_unit_vec(wf3d->direction);
	if (button == SCROLL_UP)
	{
		wf3d->direction.x += d_unit.x;
		wf3d->direction.y += d_unit.y;
	}
	else if (button == SCROLL_DOWN)
	{
		if ((wf3d->direction.x >= 0 && wf3d->direction.x - d_unit.x > 0)
		|| (wf3d->direction.x < 0 && wf3d->direction.x - d_unit.x < 0))
			wf3d->direction.x -= d_unit.x;
		if ((wf3d->direction.y >= 0 && wf3d->direction.y - d_unit.y > 0)
		|| (wf3d->direction.y < 0 && wf3d->direction.y - d_unit.y < 0))
			wf3d->direction.y -= d_unit.y;
	}
	else if (button == LEFT_CLICK)
		wf3d->freeze = (wf3d->freeze == false) ? true : false;
	render(wf3d);
	return (0);
}
