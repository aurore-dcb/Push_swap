/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurore <aurore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:12:40 by aurore            #+#    #+#             */
/*   Updated: 2023/05/19 21:06:19 by aurore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/push_swap_bonus.h"
#include "../Get_next_line/get_next_line.h"

int is_sort(t_list **begin_a, int len)
{
    t_list *lst;

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

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
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

void sort_lst2(void (*fct[7])(t_list **, t_list **), char *move, t_list **begin_a, t_list **begin_b)
{
    if (ft_strncmp(move, "rra", 3) == 0)
        fct[5](begin_a, begin_b);
    else if (ft_strncmp(move, "rrb", 3) == 0)
        fct[5](begin_a, begin_b);
    else if (ft_strncmp(move, "rrr", 3) == 0)
        fct[6](begin_a, begin_b);
    else if (ft_strncmp(move, "sa", 2) == 0)
        fct[0](begin_a, begin_b);
    else if (ft_strncmp(move, "sb", 2) == 0)
        fct[0](begin_b, begin_a);
    else if (ft_strncmp(move, "ss", 2) == 0)
        fct[1](begin_a, begin_b);
    else if (ft_strncmp(move, "pa", 2) == 0)
        fct[2](begin_a, begin_b);
    else if (ft_strncmp(move, "pb", 2) == 0)
        fct[2](begin_b, begin_a);
    else if (ft_strncmp(move, "ra", 2) == 0)
        fct[3](begin_a, begin_b);
    else if (ft_strncmp(move, "rb", 2) == 0)
        fct[3](begin_b, begin_a);
    else if (ft_strncmp(move, "rr", 2) == 0)
        fct[4](begin_a, begin_b);
}

void sort_lst(t_list **begin_a, t_list **begin_b, char *move)
{
    void	(*fct[7])(t_list **, t_list **);
    
    fct[0] = ft_swap_bonus;
    fct[1] = ft_sswap_bonus;
    fct[2] = ft_push_bonus;
    fct[3] = ft_rotate_bonus;
    fct[4] = ft_rrotate_bonus;
    fct[5] = ft_rev_rotate_bonus;
    fct[6] = ft_rrev_rotate_bonus;
    sort_lst2(fct, move, begin_a, begin_b);
}

int is_a_move(char *move)
{
    if (ft_strncmp(move, "rra", 3) == 0 || ft_strncmp(move, "rrb", 3) == 0)
        return (1);
    else if (ft_strncmp(move, "rrr", 3) == 0)
        return (1);
    else if (ft_strncmp(move, "sa", 2) == 0 || ft_strncmp(move, "sb", 2) == 0)
        return (1);
    else if (ft_strncmp(move, "ss", 2) == 0 || ft_strncmp(move, "pa", 2) == 0)
        return (1);
    else if (ft_strncmp(move, "pb", 2) == 0 || ft_strncmp(move, "ra", 2) == 0)
        return (1);
    else if (ft_strncmp(move, "rb", 2) == 0 || ft_strncmp(move, "rr", 2) == 0)
        return (1);
    printf("pas valide\n");
    return (0);
}

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

int main_sort(t_list **begin_a, t_list **begin_b)
{
    int len;
    char *move;

    len = ft_list_size(*begin_a);
    // printf("lst size = %d\n", len);
    while (!is_sort(begin_a, len))
    {
        // display(begin_a, begin_b);
        // printf("is sort = %d\n", is_sort(begin_a, len));
        move = get_next_line(1);
        if (!move)
            return (0);
        // printf("move : %s\n", move);
        else 
        {
            if (is_a_move(move))
            {
                // printf("move valid\n");
                sort_lst(begin_a, begin_b, move);
            }
            free(move);
        }
    }
    return (1);
}