/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:38:11 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/16 16:35:31 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void taille_5(t_list **begin_a, t_list **begin_b)
{
    ft_push(begin_b, begin_a, 'b');
    ft_push(begin_b, begin_a, 'b');
    taille_3(begin_a);
    
}