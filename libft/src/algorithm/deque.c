/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:26:35 by julee             #+#    #+#             */
/*   Updated: 2020/01/30 20:44:28 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_deque			*deque_init(void)
{
	return (ft_memalloc(sizeof(t_deque)));
}

void			deque_push_front(t_deque *deque, void *content)
{
	t_dlist	*node;

	if (content == NULL)
		return ;
	node = ft_memalloc(sizeof(t_dlist));
	node->content = content;
	if (is_empty_deque(deque))
		deque->last = node;
	else
	{
		deque->first->prev = node;
		node->next = deque->first;
	}
	deque->first = node;
	deque->size++;
}

void			deque_push_back(t_deque *deque, void *content)
{
	t_dlist	*node;

	if (content == NULL)
		return ;
	node = ft_memalloc(sizeof(t_dlist));
	node->content = content;
	if (is_empty_deque(deque))
		deque->first = node;
	else
	{
		deque->last->next = node;
		node->prev = deque->last;
	}
	deque->last = node;
	deque->size++;
}

void			deque_pop_front(t_deque *deque)
{
	t_dlist *node;

	if (is_empty_deque(deque))
		return ;
	node = deque->first;
	deque->first = node->next;
	deque->first->prev = NULL;
	free(node);
	deque->size--;
}

void			deque_pop_back(t_deque *deque)
{
	t_dlist *node;

	if (is_empty_deque(deque))
		return ;
	node = deque->last;
	deque->last = node->prev;
	deque->last->next = NULL;
	free(node);
	deque->size--;
}

void			*deque_front(t_deque *deque)
{
	if (is_empty_deque(deque))
		return (NULL);
	return (deque->first->content);
}

void			*deque_back(t_deque *deque)
{
	if (is_empty_deque(deque))
		return (NULL);
	return (deque->last->content);
}

int				is_empty_deque(t_deque *deque)
{
	if (deque->first == NULL)
		return (true);
	return (false);
}

void			*deque_at(t_deque *deque, size_t pos)
{
	size_t	i;
	t_dlist	*node;

	if (is_empty_deque(deque))
		return (0);
	if (deque->size <= pos)
		return (0);
	i = 0;
	node = deque->first;
	while (i != pos)
	{
		node = node->next;
		i++;
	}
	return (node);
}

void			deque_foreach(t_deque *deque, void (*f) (void *))
{
	size_t	i;
	t_dlist	*node;

	i = 0;
	node = deque->first;
	while (i != deque->size)
	{
		f(node->content);
		node = node->next;
		i++;
	}
}