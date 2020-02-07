
#include "../include/wolf3d.h"

void    render_partition(t_wf3d *wf3d, int start, int end)
{
    ft_putendl("render_partition is called");
    for (int x = start; x < end; x++)
    {
        double camera_x = (double)(2 * x) / (double)WINDOW_WIDTH - 1;
        double ray_dir_x = wf3d->direction.x + wf3d->camera_plane.x * camera_x;
        double ray_dir_y = wf3d->direction.y + wf3d->camera_plane.y * camera_x;

        int map_x = wf3d->my_pos.x;
        int map_y = wf3d->my_pos.y;

        double side_dist_x;
        double side_dist_y;

        double delta_dist_x = abs_flt(1 / ray_dir_x);
        double delta_dist_y = abs_flt(1 / ray_dir_y);
        double perp_wall_dist;

        int step_x;
        int step_y;

        int hit = 0;
        int side;

        if (ray_dir_x < 0)
        {
            step_x = -1;
            side_dist_x = (wf3d->my_pos.x - map_x) * delta_dist_x;
        }
        else
        {
            step_x = 1;
            side_dist_x = (map_x + 1.0 - wf3d->my_pos.x) * delta_dist_x;
        }
        if (ray_dir_y < 0)
        {
            step_y = -1;
            side_dist_y = (wf3d->my_pos.y - map_y) * delta_dist_y;
        }
        else
        {
            step_y = 1;
            side_dist_y = (map_y + 1.0 - wf3d->my_pos.y) * delta_dist_y;
        }
        while (hit == 0)
        {
            if (side_dist_y < side_dist_x)
            {
                side_dist_x += delta_dist_x;
                map_x += step_x;
                side = 0;
            }
            else
            {
                side_dist_y += delta_dist_y;
                map_y += step_y;
                side = 1;
            }
            if (wf3d->map[map_y][map_x] > 0)
                hit = 1;
        }
        if (side == 0)
            perp_wall_dist = abs_flt((map_x - wf3d->my_pos.x + (1 - step_x) / 2) / ray_dir_x);
        else
            perp_wall_dist = abs_flt((map_y - wf3d->my_pos.y + (1 - step_y) / 2) / ray_dir_y);
        int line_height = (int)(WINDOW_HEIGHT / perp_wall_dist);
        int draw_start = - line_height / 2 + WINDOW_HEIGHT / 2;
        if(draw_start < 0)
            draw_start = 0;
        int draw_end = line_height / 2 + WINDOW_HEIGHT / 2;
        if(draw_end >= WINDOW_HEIGHT)
            draw_end = WINDOW_HEIGHT - 1;
        int color;
        printf("draw_start draw_end == %d %d\n", draw_start, draw_end);
        switch(wf3d->map[map_y][map_x])
        {
          case 1:  color = RED;  break; //red
          case 2:  color = GREEN;  break; //green
          case 3:  color = BLUE;   break; //blue
          case 4:  color = WHITE;  break; //white
        }
        if (side == 1)
            color = color / 2;
        img_line_put(wf3d, to_point(x, draw_start), to_point(x, draw_end), color);
    }
}

void     *render_multi_1(void *param)
{
    render_partition(param, 0, WINDOW_WIDTH / 8);
    return 0;
}

void     *render_multi_2(void *param)
{
    render_partition(param, WINDOW_WIDTH / 8, WINDOW_WIDTH * 2 / 8);
    return 0;
}

void     *render_multi_3(void *param)
{
    render_partition(param, WINDOW_WIDTH * 2 / 8, WINDOW_WIDTH * 3 / 8);    
    return 0;
}

void     *render_multi_4(void *param)
{
    render_partition(param, WINDOW_WIDTH * 3 / 8, WINDOW_WIDTH * 4 / 8);
    return 0;
}

void     *render_multi_5(void *param)
{
    render_partition(param, WINDOW_WIDTH * 4 / 8, WINDOW_WIDTH * 5 / 8);
    return 0;
}

void     *render_multi_6(void *param)
{
    render_partition(param, WINDOW_WIDTH * 5 / 8, WINDOW_WIDTH * 6 / 8);
    return 0;
}

void     *render_multi_7(void *param)
{
    render_partition(param, WINDOW_WIDTH * 6 / 8, WINDOW_WIDTH * 7 / 8);
    return 0;
}

void     *render_multi_8(void *param)
{
    render_partition(param, WINDOW_WIDTH * 7 / 8, WINDOW_WIDTH / 8);
    return 0;
}

int     render(t_wf3d *wf3d)
{
    int     i;

    prepare_new_img(wf3d);
    i = 0;
    while (i < NUM_THREADS)
    {
        pthread_create(&(wf3d->threads[i]), NULL, wf3d->render_fn[i], wf3d);
        i++;
    }
    i = 0;
    while (i < NUM_THREADS)
    {
        pthread_join((wf3d->threads[i]), NULL);
        i++;
    }
	mlx_put_image_to_window(wf3d->mlx_ptr, wf3d->win_ptr, wf3d->img_ptr, 0, 0);
    return (NO_ERR);
}