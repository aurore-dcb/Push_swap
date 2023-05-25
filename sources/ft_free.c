/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:51:52 by aurore            #+#    #+#             */
/*   Updated: 2023/05/25 18:34:04 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/push_swap_bonus.h"
#include "../gnl/get_next_line.h"

void	free_list1(t_list **begin)
{
	t_list	*current;
	t_list	*temp;

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
