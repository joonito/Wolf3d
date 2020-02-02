
#include "../include/wolf3d.h"

void    error_exit(void)
{
    char *arr_str[ERR_STR_COUNT];

    if (errno == NO_ERR)
        exit(EXIT_SUCCESS);
    arr_str[0] = "No map is given";
    arr_str[1] = "Too many arguments";
    arr_str[2] = "Failed to open file";
    arr_str[3] = "Map is of invalid format";
    arr_str[4] = "Input is invalid";
    arr_str[5] = "Allocation failed";
    arr_str[6] = "Map is empty";
    ft_putendl_fd(arr_str[errno % 103], 2);
	exit( EXIT_FAILURE );
}