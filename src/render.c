
#include "../include/wolf3d.h"

void    render_partition(t_wf3d *wf3d, int start, int end)
{
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

        int step_x = 0;
        int step_y = 0;

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
            if (side_dist_x < side_dist_y)
            {
                side_dist_x += delta_dist_x;
                map_x += step_x;
                if (map_x < 0 || map_x >= (int)wf3d->map_width)
                    return ;
                side = 0;
            }
            else
            {
                side_dist_y += delta_dist_y;
                map_y += step_y;
                if (map_y < 0 || map_y >= (int)wf3d->map_height)
                    return ;
                side = 1;
            }
            if (wf3d->map[map_y][map_x] > 0)
                hit = 1;
        }
        if (side == 0)
            perp_wall_dist = (map_x - wf3d->my_pos.x + (1 - step_x) / 2) / ray_dir_x;
        else
            perp_wall_dist = (map_y - wf3d->my_pos.y + (1 - step_y) / 2) / ray_dir_y;
        if (perp_wall_dist == 0)
            perp_wall_dist = 0.001;
        int line_height = (int)(WINDOW_HEIGHT / perp_wall_dist) * WALL_HEIGHT;
        int draw_start = - line_height / 2 + WINDOW_HEIGHT / 2;
        if(draw_start < 0)
            draw_start = 0;
        int draw_end = line_height / 2 + WINDOW_HEIGHT / 2;
        if(draw_end >= WINDOW_HEIGHT)
            draw_end = WINDOW_HEIGHT - 1;
        int color = 0;
        int side_dir = 0;
        if (side == 0 && map_x >= wf3d->my_pos.x)
            side_dir = 0;
        else if (side == 0 && map_x < wf3d->my_pos.x)
            side_dir = 1;
        else if (side == 1 && map_y >= wf3d->my_pos.y)
            side_dir = 2;
        else if (side == 1 && map_y < wf3d->my_pos.y)
            side_dir = 3;
        if (side_dir == 0)
            switch (wf3d->map[map_y][map_x])
            {
              case 1:  color = RED;  break;
              case 2:  color = GREEN;  break;
              case 3:  color = BLUE;   break;
              case 4:  color = WHITE;  break;
              default: color = YELLOW; break;
            }
        else if (side_dir == 1)
            switch (wf3d->map[map_y][map_x])
            {
              case 1: color = YELLOW; break;
              case 2:  color = RED;  break;
              case 3:  color = GREEN;  break;
              case 4:  color = BLUE;   break;
              default:  color = WHITE;  break;
            }
        else if (side_dir == 2)
            switch (wf3d->map[map_y][map_x])
            {
              case 1:  color = WHITE;  break;
              case 2: color = YELLOW; break;
              case 3:  color = RED;  break;
              case 4:  color = GREEN;  break;
              default :  color = BLUE;   break;
            }
        else if (side_dir == 3)
            switch (wf3d->map[map_y][map_x])
            {
              case 1:  color = BLUE;   break;
              case 2:  color = WHITE;  break;
              case 3: color = YELLOW; break;
              case 4:  color = RED;  break;
              default :  color = GREEN;  break;
            }
        // if (side == 1)
        //     color = color / 3 * 4;
        img_line_put(wf3d, to_point(x, 0), to_point(x, draw_start), SKYBLUE);
        img_line_put(wf3d, to_point(x, draw_start), to_point(x, draw_end), color);
        img_line_put(wf3d, to_point(x, draw_end), to_point(x, WINDOW_HEIGHT), BROWN);
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
    render_partition(param, WINDOW_WIDTH * 7 / 8, WINDOW_WIDTH);
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