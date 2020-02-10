/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread_fn2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:13:26 by julee             #+#    #+#             */
/*   Updated: 2020/02/09 22:16:32 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	*render_multi_5(void *param)
{
	render_partition(param, WINDOW_WIDTH * 4 / 8, WINDOW_WIDTH * 5 / 8);
	return (0);
}

void	*render_multi_6(void *param)
{
	render_partition(param, WINDOW_WIDTH * 5 / 8, WINDOW_WIDTH * 6 / 8);
	return (0);
}

void	*render_multi_7(void *param)
{
	render_partition(param, WINDOW_WIDTH * 6 / 8, WINDOW_WIDTH * 7 / 8);
	return (0);
}

void	*render_multi_8(void *param)
{
	render_partition(param, WINDOW_WIDTH * 7 / 8, WINDOW_WIDTH);
	return (0);
}
