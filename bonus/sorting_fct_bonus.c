/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_fct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurore <aurore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:17:00 by aurore            #+#    #+#             */
/*   Updated: 2023/05/19 21:05:13 by aurore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/push_swap_bonus.h"

void	ft_swap_bonus(t_list **begin1, t_list **begin2)
{
	t_list	*tmp;

    (void)begin2;
	if (*begin1 && (*begin1)->next)
	{
		tmp = (*begin1)->next;
		(*begin1)->next = tmp->next;
		tmp->next = *begin1;
		*begin1 = tmp;
	}
}

void	ft_push_bonus(t_list **begin_dst, t_list **begin_src)
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
}

void	ft_rotate_bonus(t_list **begin1, t_list **begin2)
{
	t_list	*tmp;

    (void)begin2;
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

void	ft_rev_rotate_bonus(t_list **begin1, t_list **begin2)
{
	t_list	*new_tail;
	t_list	*tail;
	t_list	*before_tail;

    (void)begin2;
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

void ft_sswap_bonus(t_list **begin_a, t_list **begin_b)
{
	ft_swap(begin_a, 's');
	ft_swap(begin_b, 's');
}

void ft_rrotate_bonus(t_list **begin_a, t_list **begin_b)
{
	ft_rotate(begin_a, 'r');
	ft_rotate(begin_b, 'r');
}

void ft_rrev_rotate_bonus(t_list **begin_a, t_list **begin_b)
{
	ft_rev_rotate(begin_a, 'r');
	ft_rev_rotate(begin_b, 'r');
}