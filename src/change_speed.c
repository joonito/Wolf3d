
#include "../include/wolf3d.h"

void    change_speed(t_wf3d *wf3d, int keycode)
{
    if (keycode == PLUS && wf3d->speed + 0.1 <= 1)
        wf3d->speed += 0.1;
    else if (keycode == MINUS && wf3d->speed - 0.1 >= 0.1)
        wf3d->speed -= 0.1;
}