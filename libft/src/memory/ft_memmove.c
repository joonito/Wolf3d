/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:54:22 by julee             #+#    #+#             */
/*   Updated: 2018/10/30 21:25:46 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*srcc;
	unsigned char	*dstc;

	srcc = (unsigned char *)src;
	dstc = (unsigned char *)dst;
	i = -1;
	if (srcc < dstc)
		while ((int)(--len) >= 0)
			dstc[len] = srcc[len];
	else
		while (++i < len)
			dstc[i] = srcc[i];
	return (dstc);
}
