/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:13:02 by aurore            #+#    #+#             */
/*   Updated: 2023/05/27 03:22:32 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

int		apply_sort(t_stack **begin_a, t_stack **begin_b);

int		ft_strlen_new_line(char *s);
int		is_sort(t_stack **begin_a, int len);
void	sort_lst(char *move, t_stack **begin_a, t_stack **begin_b);
int		is_a_move(char *move);

void	ft_swap_bonus(t_stack **begin1);
void	ft_push_bonus(t_stack **begin_dst, t_stack **begin_src);
void	ft_rotate_bonus(t_stack **begin1);
void	ft_rev_rotate_bonus(t_stack **begin1);

void	ft_sswap_bonus(t_stack **begin_a, t_stack **begin_b);
void	ft_rrotate_bonus(t_stack **begin_a, t_stack **begin_b);
void	ft_rrev_rotate_bonus(t_stack **begin_a, t_stack **begin);

#endif