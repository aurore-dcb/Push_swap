/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:11:00 by aurore            #+#    #+#             */
/*   Updated: 2023/05/25 18:34:26 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../headers/push_swap.h"
#include "../headers/push_swap_bonus.h"

int	apply_sort(t_list **begin_a, t_list **begin_b)
{
	char	*move;

	move = "ok";
	while (move)
	{
		move = get_next_line(1);
		if (is_a_move(move))
			sort_lst(move, begin_a, begin_b);
		free(move);
	}
	if (is_sort(begin_a, ft_list_size(*begin_a)))
		ft_putstr("OK");
	else
		ft_putstr("KO");
	free_list1(begin_a);
	free_list1(begin_b);
	return (1);
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
		if (already_sort(&begin_a))
		{
			free_list1(&begin_a);
			return (0);
		}
		if (!apply_sort(&begin_a, &begin_b))
		{
			ft_putstr("Error\n");
			return (0);
		}
	}
	return (0);
}
