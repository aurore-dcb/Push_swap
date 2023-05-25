/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_fct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:46:38 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/25 18:26:34 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_swap(t_list **begin, char c)
{
	t_list	*tmp;

	if (*begin && (*begin)->next)
	{
		tmp = (*begin)->next;
		(*begin)->next = tmp->next;
		tmp->next = *begin;
		*begin = tmp;
	}
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	ft_push(t_list **begin_dst, t_list **begin_src, char c)
{
	t_list	*new_begin;
	t_list	*new_next;

	if (*begin_src != NULL)
	{
		new_begin = (*begin_src)->next;
		new_next = *begin_dst;
		*begin_dst = *begin_src;
		(*begin_dst)->next = new_next;
		*begin_src = new_begin;
	}
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}

void	ft_rotate(t_list **begin, char c)
{
	t_list	*tmp;

	if (*begin && (*begin)->next)
	{
		tmp = *begin;
		*begin = (*begin)->next;
		while ((*begin)->next)
			*begin = (*begin)->next;
		(*begin)->next = tmp;
		*begin = tmp->next;
		tmp->next = NULL;
	}
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	ft_rev_rotate(t_list **begin, char c)
{
	t_list	*new_tail;
	t_list	*tail;
	t_list	*before_tail;

	if (*begin && (*begin)->next)
	{
		tail = *begin;
		before_tail = NULL;
		while (tail->next)
		{
			before_tail = tail;
			tail = tail->next;
		}
		new_tail = before_tail;
		if (new_tail)
		{
			new_tail->next = NULL;
			tail->next = *begin;
			*begin = tail;
		}
	}
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}
