/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_tri2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:38:11 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/27 00:45:19 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../libft/libft.h"

int	index_min(t_stack **begin_a)
{
	t_stack	*begin;
	int		index;
	int		min;

	begin = *begin_a;
	min = begin->i;
	while (begin)
	{
		if (begin->i < min)
			min = begin->i;
		begin = begin->next;
	}
	index = 0;
	begin = *begin_a;
	while (begin)
	{
		if (begin->i == min)
			return (index);
		begin = begin->next;
		index++;
	}
	return (index);
}

void	small(t_stack **begin_a)
{
	int	i;

	i = index_min(begin_a);
	if (i == 1)
		ft_swap(begin_a, 'a');
	else if (i == 2)
	{
		ft_rotate(begin_a, 'a');
		ft_rotate(begin_a, 'a');
	}
	else if (i == ft_list_size(*begin_a) - 2)
	{
		ft_rev_rotate(begin_a, 'a');
		ft_rev_rotate(begin_a, 'a');
	}
	else if (i == ft_list_size(*begin_a) - 1)
		ft_rev_rotate(begin_a, 'a');
}

void	taille_5(t_stack **begin_a, t_stack **begin_b)
{
	small(begin_a);
	ft_push(begin_b, begin_a, 'b');
	small(begin_a);
	ft_push(begin_b, begin_a, 'b');
	taille_3(begin_a);
	if ((*begin_b)->i < (*begin_b)->next->i)
		ft_swap(begin_b, 'a');
	ft_push(begin_a, begin_b, 'a');
	ft_push(begin_a, begin_b, 'a');
}
