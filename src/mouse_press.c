#include "../include/wolf3d.h"

int mouse_press(int button, int x, int y, void *param)
{
    x = 0;
    y = 0;
    param = 0; // erase
    ft_printf("button == %d\n", button);
    return (0);
}