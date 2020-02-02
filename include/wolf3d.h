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

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 500

#define ERR_STR_COUNT 7
#define NO_ERR 0

#define NO_MAP 103
#define ARG_NOT_ONE 104
#define OPEN_FAILURE 105
#define INVALID_MAP 106
#define INVALID_INPUT 107
#define ALLOCATION_ERR 108
#define EMPTY_MAP 109

typedef struct  s_mlx
{
    void        *mlx_ptr;
    void        *win_ptr;
    t_deque     *map;
    size_t      map_width;
    size_t      map_height;
}               t_mlx;

//error.c
void            error_exit(void);
//freer.c
void            mlx_del(t_mlx *mlx);
//map_extract.c
int             map_extractor(const char *path, t_mlx *mlx);
//exit.c
int             exit_by_red(void *param);
int	            exit_by_esc(int keycode, void *param);
//checker.c
t_boolean       is_valid_path(const char *path);
t_boolean       is_valid_line(const char *str);

#endif
