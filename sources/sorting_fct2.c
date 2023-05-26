/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_fct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:26:05 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/27 00:45:28 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../libft/libft.h"

void	ft_sswap(t_stack **begin_a, t_stack **begin_b)
{
	ft_swap(begin_a, 's');
	ft_swap(begin_b, 's');
	write(1, "ss\n", 3);
}

void	ft_rrotate(t_stack **begin_a, t_stack **begin_b)
{
	ft_rotate(begin_a, 'r');
	ft_rotate(begin_b, 'r');
	write(1, "rr\n", 3);
}

void	ft_rrev_rotate(t_stack **begin_a, t_stack **begin_b)
{
	ft_rev_rotate(begin_a, 'r');
	ft_rev_rotate(begin_b, 'r');
	write(1, "rrr\n", 4);
}
