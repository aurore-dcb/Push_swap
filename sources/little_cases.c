/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 02:12:47 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/27 03:44:49 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../libft/libft.h"

void	taille_2(t_stack **begin_a)
{
	if ((*begin_a)->i > (*begin_a)->next->i)
		ft_swap(begin_a, 'a');
}

void	small4(t_stack **begin_a)
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
	else if (i == 3)
		ft_rev_rotate(begin_a, 'a');
}

void	taille_4(t_stack **begin_a, t_stack **begin_b)
{
	small4(begin_a);
	ft_push(begin_b, begin_a, 'b');
	taille_3(begin_a);
	ft_push(begin_a, begin_b, 'a');
}

int	special_cases(t_stack **begin_a, t_stack **begin_b)
{
	if (ft_list_size(*begin_a) >= 2 && ft_list_size(*begin_a) <= 5)
	{
		if (ft_list_size(*begin_a) == 2)
			taille_2(begin_a);
		else if (ft_list_size(*begin_a) == 3)
			taille_3(begin_a);
		else if (ft_list_size(*begin_a) == 4)
			taille_4(begin_a, begin_b);
		else if (ft_list_size(*begin_a) == 5)
			taille_5(begin_a, begin_b);
		return (1);
	}
	else
		return (0);
}
