/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:12:40 by aurore            #+#    #+#             */
/*   Updated: 2023/05/27 03:14:04 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/push_swap_bonus.h"
#include "../libft/libft.h"

int	ft_strlen_new_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	is_sort(t_stack **begin_a, int len)
{
	t_stack	*lst;

	lst = *begin_a;
	if (ft_list_size(*begin_a) != len)
		return (0);
	while (lst->next)
	{
		if (lst->i > lst->next->i)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (i < n)
	{
		if (((unsigned char *)s1)[i] > ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		if (((unsigned char *)s1)[i] < ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

void	sort_lst(char *move, t_stack **begin_a, t_stack **begin_b)
{
	int	len;

	len = ft_strlen_new_line(move);
	if (ft_strncmp(move, "rra", len) == 0)
		ft_rev_rotate_bonus(begin_a);
	else if (ft_strncmp(move, "rrb", len) == 0)
		ft_rev_rotate_bonus(begin_a);
	else if (ft_strncmp(move, "rrr", len) == 0)
		ft_rrev_rotate_bonus(begin_a, begin_b);
	else if (ft_strncmp(move, "sa", len) == 0)
		ft_swap_bonus(begin_a);
	else if (ft_strncmp(move, "sb", len) == 0)
		ft_swap_bonus(begin_b);
	else if (ft_strncmp(move, "ss", len) == 0)
		ft_sswap_bonus(begin_a, begin_b);
	else if (ft_strncmp(move, "pa", len) == 0)
		ft_push_bonus(begin_a, begin_b);
	else if (ft_strncmp(move, "pb", len) == 0)
		ft_push_bonus(begin_b, begin_a);
	else if (ft_strncmp(move, "ra", len) == 0)
		ft_rotate_bonus(begin_a);
	else if (ft_strncmp(move, "rb", len) == 0)
		ft_rotate_bonus(begin_b);
	else if (ft_strncmp(move, "rr", len) == 0)
		ft_rrotate_bonus(begin_a, begin_b);
}

int	is_a_move(char *move)
{
	if (!move)
		return (0);
	if (ft_strlen_new_line(move) == 3)
	{
		if (ft_strncmp(move, "rra", 3) == 0 || ft_strncmp(move, "rrb", 3) == 0
			|| ft_strncmp(move, "rrr", 3) == 0)
			return (1);
		ft_printf("Error\n");
		return (0);
	}
	else if (ft_strlen_new_line(move) == 2)
	{
		if (ft_strncmp(move, "sa", 2) == 0 || ft_strncmp(move, "sb", 2) == 0
			|| ft_strncmp(move, "ss", 2) == 0 || ft_strncmp(move, "pa", 2) == 0
			|| ft_strncmp(move, "pb", 2) == 0 || ft_strncmp(move, "ra", 2) == 0
			|| ft_strncmp(move, "rb", 2) == 0 || ft_strncmp(move, "rr", 2) == 0)
			return (1);
		ft_printf("Error\n");
		return (0);
	}
	ft_printf("Error\n");
	return (0);
}
