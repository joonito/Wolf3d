/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 21:34:41 by julee             #+#    #+#             */
/*   Updated: 2020/01/31 13:37:23 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
#define WOLF3D_H

#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include "../minilibx_macos/mlx.h"

#include <math.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <sys/stat.h>
#include <time.h>
#include <pthread.h>

//thread size
#define NUM_THREADS 8

//window size
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 900

//starting value
#define START_POS_X 1
#define START_POS_Y 1
#define DIR_VEC_X 0
#define DIR_VEC_Y 1
#define CAM_VEC_X 0.66
#define CAM_VEC_Y 0
#define INIT_SPEED 0.1

//wall hieght
#define WALL_HEIGHT 1

//pre-computed value
#define SIN_THETA 0.017452
#define COS_THETA 0.999847

//error mangement
#define ERR_STR_COUNT 9
#define NO_ERR 0
#define NO_MAP 103
#define ARG_NOT_ONE 104
#define OPEN_FAILURE 105
#define INVALID_MAP 106
#define INVALID_INPUT 107
#define ALLOCATION_ERR 108
#define EMPTY_MAP 109
#define INVALID_STARTING 110
#define INVALID_ACCESS_TO_MAP 111

//key code
#define ESC 53
#define LEFT_ARROW 123
#define RIGHT_ARROW 124
#define DOWN_ARROW 125
#define UP_ARROW 126
#define KEY_A 0
#define KEY_D 2
#define KEY_S 1
#define KEY_W 13
#define KEY_R 15
#define KEY_T 17
#define PLUS 24
#define MINUS 27

//mouse code
#define LEFT_CLICK 1
#define RIGHT_CLICK 2
#define MID_BUTTON 3
#define SCROLL_DOWN 4
#define SCROLL_UP 5
#define SCROLL_LEFT 6
#define SCROLL_RIGHT 7

//color code
#define WHITE 0xFFFFFF
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define YELLOW 0xFFFF00
#define CYAN 0x00FFFF
#define PURPLE 0xFF00FF
#define BROWN 0x964B00
#define SKYBLUE 0x00CCFF

typedef struct      s_wf3d t_wf3d;
typedef struct      s_pointf t_pointf;
typedef void *(* render_fp)(void *);
typedef void (*move_fp)(t_wf3d *, t_pointf, t_pointf);

typedef struct      s_point
{
    int             x;
    int             y;
}                   t_point;

typedef struct      s_pointf
{
    float           x;
    float           y;
}                   t_pointf;

typedef struct      s_wf3d
{
    void            *mlx_ptr;
    void            *win_ptr;
    void            *img_ptr;
    int             bits_per_pixel;
    int             size_line;
    int             endian;
    char            *img_addr;

    int             **map;
    size_t          map_width;
    size_t          map_height;
    size_t          map_capacity;
    
    t_pointf        my_pos;
    t_pointf        direction;
    t_pointf        camera_plane;
    pthread_t       threads[NUM_THREADS];
    render_fp       render_fn[NUM_THREADS];
    move_fp         move_fn[4];
    float           speed;
    t_boolean       state_change;
}                   t_wf3d;

void                error_exit(void);
void                mlx_del(t_wf3d *wf3d);
int                 map_extractor(const char *path, t_wf3d *wf3d);
int                 exit_by_red(void *param);
int                 exit_by_esc(t_wf3d *wf3d);
t_boolean           is_valid_path(const char *path);
t_boolean           is_valid_line(const char *str);
void                img_pixel_put(t_wf3d *wf3d, int x, int y, int color);
void                img_line_put(t_wf3d *wf3d, t_point p1, t_point p2, int color);
t_point             to_point(int x, int y);
t_pointf            to_pointf(float x, float y);
int                 key_press(int keycode, void *param);
int                 mouse_move(int x, int y, void *param);
int                 mouse_press(int button, int x, int y, void *param);
void                key_press_move(t_wf3d *wf3d, int keycode);
void                change_direction(t_wf3d *wf3d, int mouse_pos);
int                 prepare_new_img(void *param);
int                 refresh_img(void * param);
int                 render(t_wf3d *wf3d);
long double         get_magnitude(t_pointf p);
t_pointf            to_unit_vec(t_pointf p);
void                move_forward(t_wf3d *wf3d, t_pointf d_unit, t_pointf c_unit);
void                move_backward(t_wf3d *wf3d, t_pointf d_unit, t_pointf c_unit);
void                move_leftside(t_wf3d *wf3d, t_pointf d_unit, t_pointf c_unit);
void                move_rightside(t_wf3d *wf3d, t_pointf d_unit, t_pointf c_unit);
void                *render_multi_1(void *param);
void                *render_multi_2(void *param);
void                *render_multi_3(void *param);
void                *render_multi_4(void *param);
void                *render_multi_5(void *param);
void                *render_multi_6(void *param);
void                *render_multi_7(void *param);
void                *render_multi_8(void *param);
void                reset_position(t_wf3d *wf3d);
void                teleport(t_wf3d *wf3d);
void                change_speed(t_wf3d *wf3d, int keycode);

#endif