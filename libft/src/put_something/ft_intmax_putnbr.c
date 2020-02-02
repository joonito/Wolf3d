/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmax_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 21:05:17 by julee             #+#    #+#             */
/*   Updated: 2018/09/16 21:07:01 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_intmax_putnbr(intmax_t nbr)
{
	int		i;
	int		sign;
	char	s[50];

	i = 49;
	sign = 1;
	s[i--] = '\0';
	if (nbr < 0)
		sign = -1;
	if (nbr == 0)
		s[i--] = '0';
	while (nbr)
	{
		s[i--] = (sign == 1) ? nbr % 10 + '0' : -(nbr % 10) + '0';
		nbr /= 10;
	}
	if (sign == -1)
		s[i--] = '-';
	ft_putstr(&s[++i]);
}
