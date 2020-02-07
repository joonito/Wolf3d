
#include "../include/wolf3d.h"

int mouse_move(int x, int y, void *param)
{
    y = 0;
    change_direction(param, x);
    return (0);
}