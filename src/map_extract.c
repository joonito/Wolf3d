#include "../include/wolf3d.h"

static void	store_line(t_mlx *mlx, char **arr_of_str)
{
	int	*n;

	while (*arr_of_str != NULL)
	{
		n = ft_memalloc(sizeof(int));
		*n = ft_atoi(*arr_of_str);
		deque_push_back(mlx->map, n);
		arr_of_str++;
	}
	return ;
}

int			map_extractor(const char *path, t_mlx *mlx)
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
	mlx->map = deque_init();
	while (get_next_line(fd, &line) > 0)
	{
		if (!is_valid_line(line))
			return (INVALID_INPUT);
		if ((arr_of_str = ft_strsplit(line, ' ')) == NULL)
			return (ALLOCATION_ERR);
		prev = (prev == 0) ? arr_of_strlen(arr_of_str) : prev;
		if (arr_of_strlen(arr_of_str) != (size_t)prev)
			return (INVALID_MAP);
		store_line(mlx, arr_of_str);
		ft_strdel(&line);
	}
	mlx->map_width = prev;
	return ((mlx->map_width == 0) ? EMPTY_MAP : NO_ERR);
}