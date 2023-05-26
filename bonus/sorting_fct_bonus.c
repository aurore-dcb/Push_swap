/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_fct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:17:00 by aurore            #+#    #+#             */
/*   Updated: 2023/05/27 00:23:38 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/push_swap_bonus.h"
#include "../libft/libft.h"

void	ft_swap_bonus(t_stack **begin1)
{
	t_stack	*tmp;

	if (*begin1 && (*begin1)->next)
	{
		tmp = (*begin1)->next;
		(*begin1)->next = tmp->next;
		tmp->next = *begin1;
		*begin1 = tmp;
	}
}

void	ft_push_bonus(t_stack **begin_dst, t_stack **begin_src)
{
	t_stack	*new_begin;
	t_stack	*new_next;

	if (*begin_src != NULL)
	{
		new_begin = (*begin_src)->next;
		new_next = *begin_dst;
		*begin_dst = *begin_src;
		(*begin_dst)->next = new_next;
		*begin_src = new_begin;
	}
}

void	ft_rotate_bonus(t_stack **begin1)
{
	t_stack	*tmp;

	if (*begin1 && (*begin1)->next)
	{
		tmp = *begin1;
		*begin1 = (*begin1)->next;
		while ((*begin1)->next)
			*begin1 = (*begin1)->next;
		(*begin1)->next = tmp;
		*begin1 = tmp->next;
		tmp->next = NULL;
	}
}

void	ft_rev_rotate_bonus(t_stack **begin1)
{
	t_stack	*new_tail;
	t_stack	*tail;
	t_stack	*before_tail;

	if (*begin1 && (*begin1)->next)
	{
		tail = *begin1;
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
			tail->next = *begin1;
			*begin1 = tail;
		}
	}
}
