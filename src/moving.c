#include "../include/wolf3d.h"

#define STEP 0.1

void    key_press_move(t_wf3d *wf3d, int keycode)
{
    prepare_new_img(wf3d);
    if (keycode == LEFT_ARROW)
        wf3d->direction.x -= STEP;
    else if (keycode == RIGHT_ARROW)
        wf3d->direction.x += STEP;
    else if (keycode == DOWN_ARROW)
        wf3d->direction.y -= STEP;
    else if (keycode == UP_ARROW)
        wf3d->direction.y += STEP;
    printf("x y == %f %f\n", wf3d->my_pos.x, wf3d->my_pos.y);
    render(wf3d);
}