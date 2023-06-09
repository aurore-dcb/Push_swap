/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:47:00 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/27 02:14:56 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../libft/libft.h"

int	ft_list_size(t_stack *begin)
{
	int	i;

	i = 0;
	if (!begin)
		return (0);
	while (begin)
	{
		i++;
		begin = begin->next;
	}
	return (i);
}

t_stack	*ft_create_elem(int data)
{
	t_stack	*elem;

	elem = (t_stack *)malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->i = data;
	elem->next = NULL;
	return (elem);
}

int	ft_list_push_back(t_stack **begin_list, int data)
{
	t_stack	*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(data);
		if (!list->next)
			return (0);
	}
	else
	{
		*begin_list = ft_create_elem(data);
		if (!(*begin_list))
			return (0);
	}
	return (1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
