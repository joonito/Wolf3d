
#include "../include/wolf3d.h"

t_point         to_point(int x, int y)
{
    t_point p;
    p.x = x;
    p.y = y;
    return (p);
}

t_pointf         to_pointf(float x, float y)
{
    t_pointf p;
    p.x = x;
    p.y = y;
    return (p);
}
