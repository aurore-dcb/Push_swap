/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurore <aurore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:12:40 by aurore            #+#    #+#             */
/*   Updated: 2023/05/19 11:33:53 by aurore           ###   ########.fr       */
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

void sort_lst(t_list **begin_a, t_list **begin_b, char *move)
{
    
}

int main_sort(t_list **begin_a, t_list **begin_b)
{
    int len;
    char *move;

    len = ft_list_size(*begin_a);
    while (!is_sort(&begin_a, len))
    {
        move = get_next_line(1); //lire sur l'entrée standart
        if (!move)
            return (0);
        
    }
}