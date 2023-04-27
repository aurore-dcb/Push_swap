#include "../headers/push_swap.h"

t_stock *ft_create_elem_stock(int i, int maj, int move)
{
    t_stock *elem;

    elem = malloc(sizeof(t_stock));
    if(!elem)
        return (NULL);
    elem->index = i;
    elem->index_maj = maj;
    elem->nb_move = move;
    elem->next = NULL;
    return(elem);
}

void ft_list_push_back_stock(t_stock **begin_list, int i, int maj, int move)
{
    t_stock *list;

    list = *begin_list;
    if (list)
    {
        while (list->next)
            list = list->next;
        list->next = ft_create_elem_stock(i, maj, move);
    }
	else
    {
		*begin_list = ft_create_elem_stock(i, maj, move);
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
        ft_list_push_back_stock(list, index, maj, move);
        begin = begin->next;
        index++;
    }
}

void move_stack_b(t_list **begin_b, int index)
{

    if (index <= ft_list_size(*begin_b) / 2)
    {
        while (index > 0)
        {
            ft_rotate(begin_b);
            // printf("TEST rb\n");
            printf("rb\n");
            index--;
        }
    }
    else
    {
        while (index < ft_list_size(*begin_b))
        {
            ft_rev_rotate(begin_b);
            // printf("TEST rrb\n");
            printf("rrb\n");
            index++;
        }
    }
}

void move_stack_a(t_list **begin_a, int index_maj)
{

    if (index_maj <= ft_list_size(*begin_a) / 2)
    {
        while (index_maj > 0)
        {
            ft_rotate(begin_a);
            printf("ra\n");
            index_maj--;
        }
    }
    else
    {
        while (index_maj < ft_list_size(*begin_a))
        {
            ft_rev_rotate(begin_a);
            printf("rra\n");
            index_maj++;
        }
    }
}

void move_elem(t_list **begin_a, t_list **begin_b, t_stock **list)
{
    int nb_min;
    int i;
    int maj;
    t_stock *begin;

    nb_min = (*list)->nb_move;
    // nb_min = 10;
    i = (*list)->index;
    maj = (*list)->index_maj;
    begin = *list;
    // displays(begin_a, begin_b);
    // printf("NB MIN = %d\n", nb_min);
    
    while (begin)
    {
        // printf("begin->nb_move = %d\n", begin->nb_move);
        // printf("begin->index = %d\n", begin->index);
        if (begin->nb_move <= nb_min)
        {
            // printf("--------- OK ---------\n");
            nb_min = begin->nb_move;
            i = begin->index;
            maj = begin->index_maj;
        }
        begin = begin->next;
        // printf("--- i = %d\n", i);
    }
    
    move_stack_b(begin_b, i);
    move_stack_a(begin_a, maj);
}

/* pour l'instant est sensé afficher la liste de stockage des données */
void final_sort(t_list **begin_a, t_list **begin_b, t_stock **list, int max)
{
    (void)begin_a;
    (void)begin_b;
    // t_stock *begin;

    // while (begin_b)
    // {
        create_list(begin_a, begin_b, list, max);
        // ------- affiche les données de list
        /*begin = *list;
        while (begin)
        {
            printf("index : %d\n", begin->index);
            printf("index_maj : %d\n", begin->index_maj);
            printf("nb_move : %d\n", begin->nb_move);
            begin = begin->next;
            printf("\n\n");
        }*/
        // ----------------------------
        // ------ passer le maillon qui demande le moins de move sur la pile a
        move_elem(begin_a, begin_b, list);
        ft_push(begin_a, begin_b);
        printf("pa\n");
        // ----------------------------

    // }
}

