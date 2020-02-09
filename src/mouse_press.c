#include "../include/wolf3d.h"

int mouse_press(int button, int x, int y, void *param)
{
    x = 0;
    y = 0;
    t_wf3d *wf3d = param;
    t_pointf d_unit = to_unit_vec(wf3d->direction);
    if (button == SCROLL_UP)
    {
        wf3d->direction.x += d_unit.x;
        wf3d->direction.y += d_unit.y;
    }
    else if (button == SCROLL_DOWN)
    {
        if ((wf3d->direction.x >= 0 && wf3d->direction.x - d_unit.x >= 0)
        || (wf3d->direction.x < 0 && wf3d->direction.x - d_unit.x < 0))
            wf3d->direction.x -= d_unit.x;
        if ((wf3d->direction.y >= 0 && wf3d->direction.y - d_unit.y >= 0)
        || (wf3d->direction.y < 0 && wf3d->direction.y - d_unit.y < 0))
            wf3d->direction.y -= d_unit.y;
    }
    // printf("direction x y == %f %f\n", wf3d->direction.x, wf3d->direction.y);
    render(wf3d);
    // ft_printf("button == %d\n", button);
    return (0);
}