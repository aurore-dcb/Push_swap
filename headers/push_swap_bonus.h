/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurore <aurore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:13:02 by aurore            #+#    #+#             */
/*   Updated: 2023/05/19 21:07:12 by aurore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
#define PUSH_SWAP_BONUS_H

#include "../headers/push_swap.h"

void	ft_swap_bonus(t_list **begin1, t_list **begin2);
void	ft_push_bonus(t_list **begin_dst, t_list **begin_src);
void	ft_rotate_bonus(t_list **begin1, t_list **begin2);
void	ft_rev_rotate_bonus(t_list **begin1, t_list **begin2);
void    ft_sswap_bonus(t_list **begin_a, t_list **begin_b);
void    ft_rrotate_bonus(t_list **begin_a, t_list **begin_b);
void    ft_rrev_rotate_bonus(t_list **begin_a, t_list **begin_b);

int main_sort(t_list **begin_a, t_list **begin_b);

#endif