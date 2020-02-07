#include "../include/wolf3d.h"

void		int_arr_print(t_wf3d *wf3d)
{
	int **arr = wf3d->map;
	if (arr == NULL)
		return ;
	int w = wf3d->map_width;
	int h = wf3d->map_height;
	printf("map w == %d\n", w);
	printf("map h == %d\n", h);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

static void	store_line(t_wf3d *wf3d, char **arr_of_str)
{
	int	*int_arr;
	int	i;
	int **tmp = NULL;

	i = 0;
	printf("map_height0 == %zu\n", wf3d->map_height);
	printf("map_capacity == %zu\n", wf3d->map_capacity);
	int_arr = ft_memalloc(wf3d->map_width * sizeof(int));
	printf("arr of str len == %zu\n", arr_of_strlen(arr_of_str));
	while (arr_of_str[i] != NULL)
	{
		int_arr[i] = ft_atoi(arr_of_str[i]);
		i++;
	}
	printf(" i == %d\n", i);
	if (wf3d->map == NULL)
	{
		wf3d->map = ft_memalloc(sizeof(int *));
		wf3d->map_capacity = 1;
	}
	if (wf3d->map_height == wf3d->map_capacity)
	{
		tmp = wf3d->map;
		ft_putendl("point 4");
		wf3d->map_capacity *= 2;
		wf3d->map = ft_memalloc(sizeof(int *) * wf3d->map_capacity);
		for (i = 0; (size_t)i < wf3d->map_height; i++)
			wf3d->map[i] = tmp[i];
		free(tmp);
		wf3d->map_height = i;
	}
	wf3d->map[wf3d->map_height++] = int_arr;
	// printf("map_height1 == %zu\n", wf3d->map_height);
	// printf("map_height2 == %zu\n", wf3d->map_height);
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
	int_arr_print(wf3d);
	return ((wf3d->map_width == 0) ? EMPTY_MAP : NO_ERR);
}