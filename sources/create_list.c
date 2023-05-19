/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurore <aurore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:46:47 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/19 10:08:28 by aurore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_stock	*ft_create_elem_stock(int i, int maj, int move)
{
	t_stock	*elem;

	elem = malloc(sizeof(t_stock));
	if (!elem)
		return (NULL);
	elem->index = i;
	elem->index_maj = maj;
	elem->nb_move = move;
	elem->next = NULL;
	return (elem);
}

int	ft_list_push_back_stock(t_stock **begin_list, int i, int maj, int move)
{
	t_stock	*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem_stock(i, maj, move);
		if (!(list->next))
			return (0);
	}
	else
	{
		*begin_list = ft_create_elem_stock(i, maj, move);
		if (!(*begin_list))
			return (0);
	}
	return (1);
}

int	index_maj(t_list **begin_a, int nb, int max)
{
	t_list	*begin;
	int		index;
	int		maj;

	begin = *begin_a;
	maj = max;
	while (begin)
	{
		if (begin->i > nb && begin->i < maj)
			maj = begin->i;
		begin = begin->next;
	}
	index = 0;
	begin = *begin_a;
	while (begin)
	{
		if (begin->i == maj)
			return (index);
		begin = begin->next;
		index++;
	}
	return (index);
}

int	count_move(t_list **begin_a, t_list **begin_b, int index, int maj)
{
	int	nb;

	nb = 0;
	if (index > ft_list_size(*begin_b) / 2)
		nb += ft_list_size(*begin_b) - index;
	else
		nb += index;
	if (maj > ft_list_size(*begin_a) / 2)
		nb += ft_list_size(*begin_a) - maj;
	else
		nb += maj;
	return (nb);
}

int	create_list(t_list **begin_a, t_list **begin_b, t_stock **list, int max)
{
	int		index;
	int		maj;
	int		move;
	t_list	*begin;

	begin = *begin_b;
	index = 0;
	while (begin)
	{
		maj = index_maj(begin_a, begin->i, max);
		move = count_move(begin_a, begin_b, index, maj);
		if (!(ft_list_push_back_stock(list, index, maj, move)))
		{
			free_list(list);
			return (0);
		}
		begin = begin->next;
		index++;
	}
	return (1);
}
