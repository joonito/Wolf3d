
#include "../include/wolf3d.h"

void    teleport(t_wf3d *wf3d)
{
    int x;
    int y;

    x = rand() % wf3d->map_width;
    y = rand() % wf3d->map_height;
    while (wf3d->map[y][x] != 0){
        x = rand() % wf3d->map_width;
        y = rand() % wf3d->map_height;
    }
    wf3d->my_pos = to_pointf(x, y);
    render(wf3d);
}