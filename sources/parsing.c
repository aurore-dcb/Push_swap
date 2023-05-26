/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:46:34 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/27 00:50:05 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../libft/libft.h"

int	only_numbers(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	no_doubles(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	arg_lenght(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_long_atoi(arg[i]) < -2147483648)
			return (0);
		else if (ft_long_atoi(arg[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	already_sort(t_stack **begin_a)
{
	t_stack	*list;

	list = *begin_a;
	if (list)
	{
		while (list->next)
		{
			if (list->i > list->next->i)
				return (0);
			list = list->next;
		}
	}
	return (1);
}

int	ft_parsing(char **argv, t_stack **begin_a)
{
	int	i;

	if (!only_numbers(argv))
		return (0);
	if (!no_doubles(argv))
		return (0);
	if (!arg_lenght(argv))
		return (0);
	i = 1;
	while (argv[i])
	{
		if (!(ft_list_push_back(begin_a, ft_atoi(argv[i]))))
			return (0);
		i++;
	}
	return (1);
}
