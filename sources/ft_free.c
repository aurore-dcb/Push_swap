/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:51:52 by aurore            #+#    #+#             */
/*   Updated: 2023/05/27 00:44:17 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/push_swap_bonus.h"
#include "../libft/libft.h"

void	free_list1(t_stack **begin)
{
	t_stack	*current;
	t_stack	*temp;

	current = *begin;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

void	free_list(t_stock **begin)
{
	t_stock	*current;
	t_stock	*temp;

	current = *begin;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}
