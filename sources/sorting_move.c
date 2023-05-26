/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:46:42 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/27 00:45:31 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../libft/libft.h"

void	move_stack_b(t_stack **begin_b, int index)
{
	if (index <= ft_list_size(*begin_b) / 2)
	{
		while (index > 0)
		{
			ft_rotate(begin_b, 'b');
			index--;
		}
	}
	else
	{
		while (index < ft_list_size(*begin_b))
		{
			ft_rev_rotate(begin_b, 'b');
			index++;
		}
	}
}

void	move_stack_a(t_stack **begin_a, int index_maj)
{
	if (index_maj <= ft_list_size(*begin_a) / 2)
	{
		while (index_maj > 0)
		{
			ft_rotate(begin_a, 'a');
			index_maj--;
		}
	}
	else
	{
		while (index_maj < ft_list_size(*begin_a))
		{
			ft_rev_rotate(begin_a, 'a');
			index_maj++;
		}
	}
}

void	move_elem(t_stack **begin_a, t_stack **begin_b, t_stock **list)
{
	int		nb_min;
	int		i;
	int		maj;
	t_stock	*begin;

	nb_min = (*list)->nb_move;
	i = (*list)->index;
	maj = (*list)->index_maj;
	begin = *list;
	while (begin)
	{
		if (begin->nb_move <= nb_min)
		{
			nb_min = begin->nb_move;
			i = begin->index;
			maj = begin->index_maj;
		}
		begin = begin->next;
	}
	move_stack_b(begin_b, i);
	move_stack_a(begin_a, maj);
}

int	index_in_list(t_stack **begin_list, int nb)
{
	int		i;
	t_stack	*list;

	i = 0;
	list = *begin_list;
	while (list)
	{
		if (list->i == nb)
			return (i);
		list = list->next;
		i++;
	}
	return (-1);
}

void	last_rotation(t_stack **begin_a)
{
	int		min;
	int		index;
	t_stack	*begin;

	min = (*begin_a)->i;
	begin = *begin_a;
	while (begin)
	{
		if (begin->i < min)
			min = begin->i;
		begin = begin->next;
	}
	index = index_in_list(begin_a, min);
	move_stack_a(begin_a, index);
}
