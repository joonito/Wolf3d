/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:08:53 by julee             #+#    #+#             */
/*   Updated: 2020/02/09 18:24:11 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	reset_position(t_wf3d *wf3d)
{
	wf3d->my_pos = to_pointf(START_POS_X, START_POS_Y);
	wf3d->direction = to_pointf(DIR_VEC_X, DIR_VEC_Y);
	wf3d->camera_plane = to_pointf(CAM_VEC_X, CAM_VEC_Y);
	wf3d->speed = INIT_SPEED;
	wf3d->freeze = false;
	render(wf3d);
}
