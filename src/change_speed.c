/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_speed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:17:35 by julee             #+#    #+#             */
/*   Updated: 2020/02/09 18:18:23 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	change_speed(t_wf3d *wf3d, int keycode)
{
	if (keycode == PLUS && wf3d->speed + 0.1 <= 1)
		wf3d->speed += 0.1;
	else if (keycode == MINUS && wf3d->speed - 0.1 >= 0.1)
		wf3d->speed -= 0.1;
}
