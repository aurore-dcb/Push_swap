/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurore <aurore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:38:11 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/18 18:27:28 by aurore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// tri pour 5 elements :
// - trouver le max
// - si il est dans les deux élements du haut -> le bouger pour qu'il soit dans les 3 du bas (1 move)
// - push les 2 premiers élements de la pile A sur la pile B (2 move)
// - faire le tri pour 3 elem sur la pile A (1 ou 2 move)
// - 
// - push les deux élements de la pile B sur la pile A (2 move)

// tri pour 5 elements :
// - mettre les 2 plus petits élements sur la pile B (max 6 move)
	// - a faire 2 fois : trouver le plus petit elem, le mettre en haut de la pile, push B
// - faire le tri pour 3 elem sur la pile A (1 ou 2 move)
// - sur la pile B, mettre le plus petit element en bas et le plus grand en haut (0 ou 1 move)
// - push les deux élements de la pile B sur la pile A (2 move)

int	index_min(t_list **begin_a)
{
	t_list	*begin;
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

void small(t_list **begin_a)
{
	int i;

	i = index_min(begin_a);
	if (i == 1)
		ft_swap(begin_a, 'a');//sa
	else if (i == 2)
	{
		ft_rotate(begin_a, 'a');//ra
		ft_rotate(begin_a, 'a');//ra
	}
	else if (i == ft_list_size(*begin_a) - 2)
	{
		ft_rev_rotate(begin_a, 'a');//rra
		ft_rev_rotate(begin_a, 'a');//rra
	}
	else if (i == ft_list_size(*begin_a) - 1)
		ft_rev_rotate(begin_a, 'a');//rra
}

void taille_5(t_list **begin_a, t_list **begin_b)
{
	small(begin_a);
	ft_push(begin_b, begin_a, 'b');
	small(begin_a);
	ft_push(begin_b, begin_a, 'b');
	// les deux petits elements sont sur la pile B
	taille_3(begin_a);
	// la pile A est triée
	if ((*begin_b)->i < (*begin_b)->next->i)
		ft_swap(begin_b, 'a');
	// le plus grand elem de B est au dessus de la pile
	ft_push(begin_a, begin_b, 'a');
	ft_push(begin_a, begin_b, 'a');
	// les 5 elements sont sur triés sur la pile a
}