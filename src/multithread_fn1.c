/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread_fn1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:12:35 by julee             #+#    #+#             */
/*   Updated: 2020/02/09 22:13:16 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	*render_multi_1(void *param)
{
	render_partition(param, 0, WINDOW_WIDTH / 8);
	return (0);
}

void	*render_multi_2(void *param)
{
	render_partition(param, WINDOW_WIDTH / 8, WINDOW_WIDTH * 2 / 8);
	return (0);
}

void	*render_multi_3(void *param)
{
	render_partition(param, WINDOW_WIDTH * 2 / 8, WINDOW_WIDTH * 3 / 8);
	return (0);
}

void	*render_multi_4(void *param)
{
	render_partition(param, WINDOW_WIDTH * 3 / 8, WINDOW_WIDTH * 4 / 8);
	return (0);
}
