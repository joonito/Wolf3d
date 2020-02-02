/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 11:32:30 by julee             #+#    #+#             */
/*   Updated: 2019/01/10 00:06:09 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	if (!(copy = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1))))
		return (NULL);
	ft_strcpy(copy, s1);
	return (copy);
}
