#include "../include/wolf3d.h"

#define UNIT_ANGLE (M_PI / 60)
#define LEFT_SIDE WINDOW_WIDTH / 3
#define RIGHT_SIDE LEFT_SIDE * 2

void    change_direction(t_wf3d *wf3d, int mouse_pos)
{
    float sin_theta = SIN_THETA;
    float cos_theta = COS_THETA;
    float x = wf3d->direction.x;
    float y = wf3d->direction.y;
    float cx = wf3d->camera_plane.x;
    float cy = wf3d->camera_plane.y;
    if (mouse_pos <= LEFT_SIDE)
    {
        wf3d->direction.x = x * cos_theta - y * sin_theta;
        wf3d->direction.y = x * sin_theta + y * cos_theta;
        wf3d->camera_plane.x = cx * cos_theta - cy * sin_theta;
        wf3d->camera_plane.y = cx * sin_theta + cy * cos_theta;
    }
    else if (RIGHT_SIDE <= mouse_pos)
    {
        wf3d->direction.x = x * cos_theta + y * sin_theta;
        wf3d->direction.y = -x * sin_theta + y * cos_theta;
        wf3d->camera_plane.x = cx * cos_theta + cy * sin_theta;
        wf3d->camera_plane.y = -cx * sin_theta + cy * cos_theta;
    }
    render(wf3d);
}