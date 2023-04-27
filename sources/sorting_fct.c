#include "../headers/push_swap.h"

void ft_swap(t_list **begin)
{
    t_list *tmp;

    if (*begin && (*begin)->next)
    {
        tmp = (*begin)->next;
        (*begin)->next = tmp->next;
        tmp->next = *begin;
        *begin = tmp;
    }
}

void ft_push(t_list **begin_dst, t_list **begin_src)
{
    t_list *new_begin;
    t_list *new_next;
    
    if (*begin_src != NULL)
    {
        new_begin = (*begin_src)->next;
        new_next = *begin_dst;
        *begin_dst = *begin_src;
        (*begin_dst)->next = new_next;
        *begin_src = new_begin;
    }
}

void ft_rotate(t_list **begin)
{
    t_list *tmp;

    if (*begin && (*begin)->next)
    {
        tmp = *begin;
        *begin = (*begin)->next;
        while ((*begin)->next)
            *begin = (*begin)->next;
        (*begin)->next = tmp;
        *begin = tmp->next;
        tmp->next = NULL;
    }
}

void ft_rev_rotate(t_list **begin)
{
    t_list *new_tail, *tail, *before_tail;

    if (*begin && (*begin)->next)
    {
        tail = *begin;
        before_tail = NULL;
        while (tail->next)
        {
            before_tail = tail;
            tail = tail->next;
        }
        new_tail = before_tail;
        if (new_tail)
        {
            new_tail->next = NULL;
            tail->next = *begin;
            *begin = tail;
        }
    }
}