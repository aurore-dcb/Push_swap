/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_fct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:26:05 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/25 18:29:07 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_sswap(t_list **begin_a, t_list **begin_b)
{
	ft_swap(begin_a, 's');
	ft_swap(begin_b, 's');
	write(1, "ss\n", 3);
}

void	ft_rrotate(t_list **begin_a, t_list **begin_b)
{
	ft_rotate(begin_a, 'r');
	ft_rotate(begin_b, 'r');
	write(1, "rr\n", 3);
}

void	ft_rrev_rotate(t_list **begin_a, t_list **begin_b)
{
	ft_rev_rotate(begin_a, 'r');
	ft_rev_rotate(begin_b, 'r');
	write(1, "rrr\n", 4);
}
