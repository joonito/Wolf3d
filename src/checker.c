
#include "../include/wolf3d.h"

t_boolean   is_valid_path(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return (S_ISREG(path_stat.st_mode));
}

t_boolean   is_valid_line(const char *str)
{
    while (*str != '\0')
    {
        if (!ft_isdigit(*str) && !ft_isspace(*str))
            return (false);
        str++;
    }
    return (true);
}