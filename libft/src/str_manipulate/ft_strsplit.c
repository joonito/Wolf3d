/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:59:23 by julee             #+#    #+#             */
/*   Updated: 2019/01/06 00:48:35 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char		*ft_strchr_rev(const char *s, int c)
{
	int		i;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	str = (char *)s;
	while (str[i] == c)
		i++;
	if (str[i] == '\0')
		return (NULL);
	return (&(str[i]));
}

char			**ft_strsplit(char const *s, char c)
{
	int		wd_count;
	char	*pos_start;
	char	*pos_end;
	char	**arr;

	if (s == NULL)
		return (NULL);
	wd_count = 0;
	pos_end = (char *)s;
	while ((pos_start = ft_strchr_rev(pos_end, c)) != NULL)
	{
		pos_end = ft_strchr(pos_start, c);	
		wd_count++;
	}
	if (!(arr = ft_memalloc(sizeof(char *) * (wd_count + 1))))
		return (NULL);
	wd_count = 0;
	pos_end = (char *)s;
	while ((pos_start = ft_strchr_rev(pos_end, c)) != NULL)
	{
		pos_end = ft_strchr(pos_start, c);
		if (pos_end == NULL)
			pos_end = (char *)&(s[ft_strlen(s)]);
		if (!(arr[wd_count++] = ft_strndup(pos_start, pos_end - pos_start))) {
			arr_of_strdel(arr);
			return (NULL);
		}
	}
	return (arr);
}