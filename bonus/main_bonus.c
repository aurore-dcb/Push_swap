/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:11:00 by aurore            #+#    #+#             */
/*   Updated: 2023/05/27 01:49:00 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/push_swap_bonus.h"
#include "../libft/libft.h"

int	apply_sort(t_stack **begin_a, t_stack **begin_b)
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
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_list1(begin_a);
	free_list1(begin_b);
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
		if (already_sort(&begin_a))
		{
			free_list1(&begin_a);
			return (0);
		}
		if (!apply_sort(&begin_a, &begin_b))
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	return (0);
}
