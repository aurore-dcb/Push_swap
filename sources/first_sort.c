/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurore <aurore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:46:53 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/19 10:08:31 by aurore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	*sort_int_tab(t_list **begin_a, int *tab)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < ft_list_size(*begin_a))
	{
		j = i + 1;
		while (j < ft_list_size(*begin_a))
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
				j = i + 1;
			}
			else
				j++;
		}
		i++;
	}
	return (tab);
}

void	create_sort_tab(t_list **begin_a, int *tab)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *begin_a;
	while (tmp)
	{
		tab[i] = tmp->i;
		tmp = tmp->next;
		i++;
	}
	tab = sort_int_tab(begin_a, tab);
}

int	find_max(int *tab, int len)
{
	int	i;
	int	max;

	i = 1;
	max = tab[0];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

void	keep_just_max(t_list **begin_a, t_list **begin_b, int *tab)
{
	int	max;
	int	compteur;
	int	len;

	len = ft_list_size(*begin_a);
	max = find_max(tab, len);
	compteur = -1;
	while (++compteur < len)
	{
		if ((*begin_a)->i != max)
		{
			ft_push(begin_b, begin_a, 'b');
			if ((*begin_b)->i >= tab[(len) / 2])
				ft_rotate(begin_b, 'b');
		}
		else
			ft_rotate(begin_a, 'a');
	}
}
