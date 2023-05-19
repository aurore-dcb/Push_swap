/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurore <aurore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:00:02 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/19 10:09:01 by aurore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	match(t_list **begin_a, int a, int b, int c)
{
	if (*begin_a)
	{
		if ((*begin_a)->i != a)
			return (0);
		if ((*begin_a)->next->i != b)
			return (0);
		if ((*begin_a)->next->next->i != c)
			return (0);
		return (1);
	}
	return (0);
}

int	lst_min(t_list **begin_a)
{
	int		min;
	t_list	*list;

	list = *begin_a;
	min = 0;
	if (list)
	{
		min = list->i;
		while (list)
		{
			if (list->i < min)
				min = list->i;
			list = list->next;
		}
	}
	return (min);
}

int	lst_max(t_list **begin_a)
{
	int		max;
	t_list	*list;

	list = *begin_a;
	max = 0;
	if (list)
	{
		max = list->i;
		while (list)
		{
			if (list->i > max)
				max = list->i;
			list = list->next;
		}
	}
	return (max);
}

int	lst_med(t_list **begin_a, int min, int max)
{
	int		med;
	t_list	*list;

	med = 0;
	list = *begin_a;
	if (list)
	{
		while (list)
		{
			if (list->i != min && list->i != max)
				med = list->i;
			list = list->next;
		}
	}
	return (med);
}

void	taille_3(t_list **begin_a)
{
	int	min;
	int	med;
	int	max;

	min = lst_min(begin_a);
	max = lst_max(begin_a);
	med = lst_med(begin_a, min, max);
	if (match(begin_a, med, max, min))
		ft_rev_rotate(begin_a, 'a'); //rra
	else if (match(begin_a, max, min, med))
		ft_rotate(begin_a, 'a'); //ra
	else if (match(begin_a, max, med, min))
	{
		ft_swap(begin_a, 'a');       //sa
		ft_rev_rotate(begin_a, 'a'); //rra
	}
	else if (match(begin_a, med, min, max))
		ft_swap(begin_a, 'a'); //sa
	else if (match(begin_a, min, max, med))
	{
		ft_rev_rotate(begin_a, 'a'); //rra
		ft_swap(begin_a, 'a');       //sa
	}
}
