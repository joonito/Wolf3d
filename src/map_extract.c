/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:08:32 by julee             #+#    #+#             */
/*   Updated: 2020/02/09 19:48:33 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static int	*copy_arr(t_wf3d *wf3d, char **arr_of_str)
{
	int	i;
	int	*int_arr;

	int_arr = ft_memalloc(wf3d->map_width * sizeof(int));
	i = 0;
	while (arr_of_str[i] != NULL)
	{
		int_arr[i] = ft_atoi(arr_of_str[i]);
		i++;
	}
	return (int_arr);
}

static void	arr_free(char **arr_of_str)
{
	int	i;
	int arr_len;

	arr_len = arr_of_strlen(arr_of_str);
	i = 0;
	while (i <= arr_len)
		ft_memdel((void **)&(arr_of_str[i++]));
	ft_memdel((void **)&arr_of_str);
}

static void	reallocate_mem(t_wf3d *wf3d)
{
	int		i;
	int		**tmp;

	tmp = wf3d->map;
	wf3d->map_capacity *= 2;
	wf3d->map = ft_memalloc(sizeof(int *) * wf3d->map_capacity);
	i = 0;
	while ((size_t)i < wf3d->map_height)
	{
		wf3d->map[i] = tmp[i];
		i++;
	}
	ft_memdel((void **)&tmp);
	wf3d->map_height = i;
}

static void	store_line(t_wf3d *wf3d, char **arr_of_str)
{
	int	*int_arr;

	int_arr = copy_arr(wf3d, arr_of_str);
	arr_free(arr_of_str);
	if (wf3d->map == NULL)
	{
		wf3d->map = ft_memalloc(sizeof(int *));
		wf3d->map_capacity = 1;
	}
	else if (wf3d->map_height == wf3d->map_capacity)
		reallocate_mem(wf3d);
	wf3d->map[wf3d->map_height++] = int_arr;
	return ;
}

int			map_extractor(const char *path, t_wf3d *wf3d)
{
	int		fd;
	int		prev;
	char	*line;
	char	**arr_of_str;

	if (!is_valid_path(path))
		return (INVALID_INPUT);
	if ((fd = open(path, O_RDONLY)) < 0)
		return (OPEN_FAILURE);
	prev = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!is_valid_line(line))
			return (INVALID_INPUT);
		if ((arr_of_str = ft_strsplit(line, ' ')) == NULL)
			return (ALLOCATION_ERR);
		prev = (prev == 0) ? arr_of_strlen(arr_of_str) : prev;
		if ((wf3d->map_width = arr_of_strlen(arr_of_str)) != (size_t)prev)
			return (INVALID_MAP);
		store_line(wf3d, arr_of_str);
		ft_strdel(&line);
	}
	close(fd);
	return ((wf3d->map_width == 0) ? EMPTY_MAP : NO_ERR);
}
