/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:05:21 by julee             #+#    #+#             */
/*   Updated: 2020/02/02 18:05:23 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void        img_pixel_put(t_wf3d *wf3d, int x, int y, int color)
{
    char    *addr;
    
    if (x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT || x < 0 || y < 0)
    {
        ft_putendl_fd("pixel out of range", 2);
        return ;
    }
    addr = wf3d->img_addr;
    addr +=  (4 * x) + wf3d->size_line * y;
    *addr++ = color & 0xFF;
    *addr++ = (color & 0xFF00) >> 8;
    *addr = (color & 0xFF0000) >> 16;
}

static void img_line_low(t_wf3d *wf3d, t_point p1, t_point p2, int color)
{
    int     y_step;
    int     diff;
    t_point delta;
    t_point coor;

    delta = to_point(p2.x - p1.x, p2.y - p1.y);
    y_step = (delta.y > 0) ? 1 : -1;
    delta.y = (delta.y > 0) ? delta.y : -delta.y;
    diff = 2 * delta.y - delta.x;
    coor = to_point(p1.x, p1.y);
    while (coor.x < p2.x)
    {
        img_pixel_put(wf3d, coor.x++, coor.y, color);
        if (diff > 0)
        {
            coor.y += y_step;
            diff += - 2 * delta.x;
        }
        diff += 2 * delta.y;
    }
}

static void img_line_high(t_wf3d *wf3d, t_point p1, t_point p2, int color)
{
    int     x_step;
    int     diff;
    t_point delta;
    t_point coor;

    delta = to_point(p2.x - p1.x, p2.y - p1.y);
    x_step = (delta.x > 0) ? 1 : -1;
    delta.x = (delta.x > 0) ? delta.x : -delta.x;
    diff = 2 * delta.x - delta.y;
    coor = to_point(p1.x, p1.y);
    while (coor.y < p2.y)
    {
        img_pixel_put(wf3d, coor.x, coor.y++, color);
        if (diff > 0)
        {
            coor.x += x_step;
            diff += - 2 * delta.y;
        }
        diff += 2 * delta.x;
    }
}

void        img_line_put(t_wf3d *wf3d, t_point p1, t_point p2, int color)
{
    if (abs_int(p2.y - p1.y) < abs_int(p2.x - p1.x))
    {
        if (p1.x > p2.x)
            img_line_low(wf3d, p2, p1, color);
        else
            img_line_low(wf3d, p1, p2, color);
    }
    else
    {
        if (p1.y > p2.y)
            img_line_high(wf3d, p2, p1, color);
        else
            img_line_high(wf3d, p1, p2, color);
    }
}