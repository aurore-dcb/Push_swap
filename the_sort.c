#include "push_swap.h"

t_stock *ft_create_elem_stock(int n, int i, int maj, int move)
{
    t_stock *elem;

    elem = malloc(sizeof(t_stock));
    if(!elem)
        return (NULL);
    elem->n = n;
    elem->index = i;
    elem->index_maj = maj;
    elem->nb_move = move;
    elem->next = NULL;
    return(elem);
}

void ft_list_push_back_stock(t_stock **begin_list, int n, int i, int maj, int move)
{
    t_stock *list;

    list = *begin_list;
    if (list)
    {
        while (list->next)
            list = list->next;
        list->next = ft_create_elem_stock(n, i, maj, move);
    }
	else
    {
		*begin_list = ft_create_elem_stock(n, i, maj, move);
    }
}

/* Détermine l'indice du 1er majorant dans la pile a d'un maillon de la pile b */
int index_maj(t_list **begin_a, int nb, int max)
{
    t_list *begin;
    int index;
    int maj;

    begin = *begin_a;
    maj = max;
    while (begin)
    {
        if (begin->i > nb && begin->i < maj)
            maj = begin->i;
        begin = begin->next;
    }
    index = 0;
    begin = *begin_a;
    while (begin)
    {
        if (begin->i == maj)
            return (index);
        begin = begin->next;
        index++;
    }
    return (index);
}

int count_move(t_list **begin_a, t_list **begin_b, int index, int maj)
{
    int nb;

    nb = 0;
    if (index > ft_list_size(*begin_b) / 2)
        nb += ft_list_size(*begin_b) - index;
    else
        nb += index;
    if (maj > ft_list_size(*begin_a) / 2)
        nb += ft_list_size(*begin_a) - maj;
    else
        nb += maj;
    return (nb);
}

void create_list(t_list **begin_a, t_list **begin_b, t_stock **list, int max)
{
    t_list  *begin;
    int     index;
    int     maj;
    int     move;

    begin = *begin_b;
    index = 0; //indice du maillon dans la pile b
    while (begin)
    {
        maj = index_maj(begin_a, begin->i, max);
        move = count_move(begin_a, begin_b, index, maj);
        ft_list_push_back_stock(list, begin->i, index, maj, move);
        begin = begin->next;
        index++;
    }
}

void move_elem(t_list **begin_a, t_list **begin_b, t_stock **list)
{
    int nb_min;
    int i;
    // int maj;
    int number;
    t_stock *begin;
    (void)begin_a;

    nb_min = (*list)->nb_move;
    i = (*list)->index;
    // maj = (*list)->index_maj;
    number = (*list)->n;
    begin = *list;
    while (begin)
    {
        if (begin->nb_move < nb_min)
        {
            nb_min = begin->nb_move;
            i = (*list)->index;
            // maj = (*list)->index_maj;
            number = (*list)->n;
        }
        begin = begin->next;
    }
    while ((*begin_b)->i != number)
    {
        if (i > ft_list_size(*begin_b) / 2)
            ft_rev_rotate(begin_b);
        else
            ft_rotate(begin_b);
    }

}

/* pour l'instant est sensé afficher la liste de stockage des données */
void final_sort(t_list **begin_a, t_list **begin_b, t_stock **list, int max)
{
    (void)begin_a;
    (void)begin_b;
    t_stock *begin;

    // while (begin_b)
    // {
        create_list(begin_a, begin_b, list, max);
        // ------- affiche les données de list
        begin = *list;
        while (begin)
        {
            printf("index : %d\n", begin->index);
            printf("index_maj : %d\n", begin->index_maj);
            printf("nb_move : %d\n", begin->nb_move);
            begin = begin->next;
            printf("\n\n");
        }
        // ----------------------------
        // ------ passer le maillon qui demande le moins de move sur la pile a
        move_elem(begin_a, begin_b, list);
        ft_push(begin_a, begin_b);
        printf("pa");




        // ----------------------------

    // }
}

