/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurore <aurore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:46:30 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/19 18:53:47 by aurore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	display(t_list **begin_a, t_list **begin_b)
{
	t_list *lst1;
	t_list *lst2;

	lst1 = *begin_a;
	lst2 = *begin_b;
	printf("pile A :\n");
	while (lst1)
	{
		printf("%d\n", lst1->i);
		lst1 = lst1->next;
	}
	printf("pile B :\n");
	while (lst2)
	{
		printf("%d\n", lst2->i);
		lst2 = lst2->next;
	}
}


int	sorting(t_list **begin_a, t_list **begin_b)
{
	int		*tab;
	t_stock	*list;
	int		max;

	tab = malloc(sizeof(int) * ft_list_size(*begin_a));
	if (!tab)
		return (0);
	create_sort_tab(begin_a, tab);
	keep_just_max(begin_a, begin_b, tab);
	free(tab);
	max = (*begin_a)->i;
	while (*begin_b)
	{
		list = NULL;
		if (!create_list(begin_a, begin_b, &list, max))
			return (0);
		move_elem(begin_a, begin_b, &list);
		ft_push(begin_a, begin_b, 'a');
		free_list(&list);
	}
	last_rotation(begin_a);
	return (1);
}

int	special_cases(t_list **begin_a, t_list **begin_b)
{
	if (ft_list_size(*begin_a) == 3)
	{
		taille_3(begin_a);
		return (1);
	}
	else if (ft_list_size(*begin_a) == 5)
	{
		taille_5(begin_a, begin_b);
		return (1);
	}
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_list	*begin_a;
	t_list	*begin_b;

	begin_a = NULL;
	begin_b = NULL;
	if (argc > 1)
	{
		if (ft_parsing(argv, &begin_a) == 0)
		{
			free_list1(&begin_a);
			ft_putstr("Error\n");
			return (0);
		}
		if (already_sort(&begin_a) || special_cases(&begin_a, &begin_b))
			return (0);
		if (sorting(&begin_a, &begin_b) == 0)
		{
			ft_putstr("Error\n");
			return (0);
		}
		free_list1(&begin_a);
	}
	return (0);
}
