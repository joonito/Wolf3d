#include "../include/wolf3d.h"

void	change_direction(t_wf3d *wf3d, int mouse_pos)
{
	float x;
	float y;
	float cx;
	float cy;
	
	x = wf3d->direction.x;
	y = wf3d->direction.y;
	cx = wf3d->camera_plane.x;
	cy = wf3d->camera_plane.y;
	if (mouse_pos <= LEFT_SIDE && wf3d->freeze == false)
	{
		wf3d->direction.x = x * COS_THETA - y * SIN_THETA;
		wf3d->direction.y = x * SIN_THETA + y * COS_THETA;
		wf3d->camera_plane.x = cx * COS_THETA - cy * SIN_THETA;
		wf3d->camera_plane.y = cx * SIN_THETA + cy * COS_THETA;
	}
	else if (RIGHT_SIDE <= mouse_pos && wf3d->freeze == false)
	{
		wf3d->direction.x = x * COS_THETA + y * SIN_THETA;
		wf3d->direction.y = -x * SIN_THETA + y * COS_THETA;
		wf3d->camera_plane.x = cx * COS_THETA + cy * SIN_THETA;
		wf3d->camera_plane.y = -cx * SIN_THETA + cy * COS_THETA;
	}
	render(wf3d);
}
