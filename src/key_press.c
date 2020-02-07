
#include "../include/wolf3d.h"

int key_press(int keycode, void *param)
{
	if (keycode == 53)
        exit_by_esc(param);
    else if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
        key_press_move(param, keycode);
    else
    {
        
    }
	return (0);
}