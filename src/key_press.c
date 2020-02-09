
#include "../include/wolf3d.h"

int key_press(int keycode, void *param)
{
	if (keycode == ESC)
        exit_by_esc(param);
    else if ((LEFT_ARROW <= keycode && keycode <= UP_ARROW)
    || (keycode == KEY_A || keycode == KEY_D
    || keycode == KEY_S || keycode == KEY_W))
        key_press_move(param, keycode);
    else if (keycode == KEY_R)
        reset_position(param);
    else if (keycode == KEY_T)
        teleport(param);
    else if (keycode == PLUS || keycode == MINUS)
        change_speed(param, keycode);
	return (0);
}