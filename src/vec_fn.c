#include "../include/wolf3d.h"

long double get_magnitude(t_pointf p)
{
    return (sqrtl(powl(p.x, 2) + powl(p.y, 2)));
}

t_pointf    to_unit_vec(t_pointf p)
{
    long double m;
    
    m = get_magnitude(p);
    p.x = p.x / m;
    p.y = p.y / m;
    return (p);
}