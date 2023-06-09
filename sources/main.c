/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:46:30 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/27 02:55:31 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../libft/libft.h"

int	sorting(t_stack **begin_a, t_stack **begin_b)
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

int	main(int argc, char **argv)
{
	t_stack	*begin_a;
	t_stack	*begin_b;

	begin_a = NULL;
	begin_b = NULL;
	if (argc > 1)
	{
		if (ft_parsing(argv, &begin_a) == 0)
		{
			free_list1(&begin_a);
			ft_printf("Error\n");
			return (0);
		}
		if (already_sort(&begin_a) || special_cases(&begin_a, &begin_b))
			return (free_list1(&begin_a), free_list1(&begin_b), 0);
		if (sorting(&begin_a, &begin_b) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		free_list1(&begin_a);
	}
	return (0);
}
