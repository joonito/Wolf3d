/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:09:52 by julee             #+#    #+#             */
/*   Updated: 2020/02/09 18:10:20 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

t_point		to_point(int x, int y)
{
	t_point p;
	p.x = x;
	p.y = y;
	return (p);
}

t_pointf	to_pointf(float x, float y)
{
	t_pointf p;
	p.x = x;
	p.y = y;
	return (p);
}
