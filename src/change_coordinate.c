#include "../include/wolf3d.h"

#define STEP 5

// void    *draw_line(void * param)
// {
//     t_wf3d *wf3d = param;

//     srand(time(NULL));

//     for (int i = 0; i < 100; i++)
//     {
//         int x0 = rand() % WINDOW_WIDTH;
//         int y0 = rand() % WINDOW_HEIGHT;
//         int x1 = rand() % WINDOW_WIDTH;
//         int y1 = rand() % WINDOW_HEIGHT;
//         img_line_put(wf3d, to_point(x0, y0), to_point(x1, y1), 0xFFFFFF);
//     }
//     return (0);
// }

void    change_coordinate(t_wf3d *wf3d, int keycode)
{
    if (keycode == LEFT_ARROW)
        wf3d->my_pos.x -= STEP;
    else if (keycode == RIGHT_ARROW)
        wf3d->my_pos.x += STEP;
    else if (keycode == DOWN_ARROW)
        wf3d->my_pos.y -= STEP;
    else if (keycode == UP_ARROW)
        wf3d->my_pos.y += STEP;
    // prepare_new_img(wf3d);
    // ft_printf("keycode == %d\n", keycode);
    // pthread_t threads[NUM_THREADS] = {0};
    // int rc;
    // for (int i = 0; i < NUM_THREADS; i++)
    // {   
    //     int *n = ft_memalloc(sizeof(int));
    //     *n = i;
    //     printf("main() : Thread created, %d\n", i);
    //     rc = pthread_create(&threads[i], NULL, draw_line, wf3d);
    //     if (rc != 0)
    //     {
    //         printf("Error:unable to create thread, %d\n", rc);
    //         exit(-1);
    //     }
    // }
    // wf3d->state_change = true;
    // refresh_img(wf3d);
}