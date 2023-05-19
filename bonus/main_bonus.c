/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurore <aurore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:11:00 by aurore            #+#    #+#             */
/*   Updated: 2023/05/19 20:53:53 by aurore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/push_swap_bonus.h"
#include "../Get_next_line/get_next_line.h"

int main(int argc, char **argv)
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
            return (0);
        if (!main_sort(&begin_a, &begin_b))
        {
            ft_putstr("Error\n");
            return (0);
        }
        ft_putstr("OK");
    }
    return (0);
}