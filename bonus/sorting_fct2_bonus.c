/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_fct2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:10:12 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/25 18:25:08 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/push_swap_bonus.h"

void	ft_sswap_bonus(t_list **begin_a, t_list **begin_b)
{
	ft_swap(begin_a, 's');
	ft_swap(begin_b, 's');
}

void	ft_rrotate_bonus(t_list **begin_a, t_list **begin_b)
{
	ft_rotate(begin_a, 'r');
	ft_rotate(begin_b, 'r');
}

void	ft_rrev_rotate_bonus(t_list **begin_a, t_list **begin_b)
{
	ft_rev_rotate(begin_a, 'r');
	ft_rev_rotate(begin_b, 'r');
}
