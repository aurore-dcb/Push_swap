#include "push_swap.h"

/* pour le 1er tri */
int *sort_int_tab(t_list **begin_a, int *tab)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < ft_list_size(*begin_a))
    {
        j = i + 1;
        while (j < ft_list_size(*begin_a))
        {
            if (tab[i] > tab[j])
            {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
                j = i + 1;
            }
            else
                j++;
        }
        i++;
    }
    return (tab);
}

/* pour le 1er tri */
void create_sort_tab(t_list **begin_a, int *tab)
{
    t_list *tmp;
    int i;

    i = 0;
    tmp = *begin_a;
    while (tmp)
    {
        tab[i] = tmp->i;
        tmp = tmp->next;
        i++;
    }
    tab = sort_int_tab(begin_a, tab);
}

/* pour le 1er tri */
int is_max(int *tab, int len)
{
    int i;
    int max;

    i = 1;
    max = tab[0];
    while (i < len)
    {
        if (tab[i] > max)
            max = tab[i];
        i++;
    }
    return (max);
}

/* premier tri qui garde l'élément le plus grand dans la pile a, et mets les autres éléments dans la pile b (les éléments plus petits que la médiane en haut les autres en bas)*/
void keep_just_max(t_list **begin_a, t_list **begin_b, int *tab)
{
    int max;
    int compteur;
    int len;

    len = ft_list_size(*begin_a);
    max = is_max(tab, ft_list_size(*begin_a));
    compteur = -1;
    while (++compteur < len)
    {
        if ((*begin_a)->i != max)
        {
            ft_push(begin_b, begin_a);
            printf("pb\n");
            if ((*begin_b)->i >= tab[(len) / 2])
            {
                ft_rotate(begin_b);
                printf("rb\n");
            }
        }
        else
        {
            ft_rotate(begin_a);
            printf("ra\n");
        }
    }
}

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
        printf("ok\n");
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
    {
        nb += ft_list_size(*begin_b) - index;
    }
    else
    {
        nb += index;
    }

    if (maj > ft_list_size(*begin_a) / 2)
    {
        nb += ft_list_size(*begin_a) - maj;
    }
    else
    {
        nb += maj;
    }
    return (nb);
}

void create_list(t_list **begin_a, t_list **begin_b, t_stock **list)
{
    t_list  *begin;
    int     index;
    int     maj;
    int     move;

    begin = *begin_b;
    index = 0; //indice du maillon dans la pile b
    while (begin)
    {
        printf("TEST 1\n");
        maj = index_maj(begin_a, begin->i, (*begin_a)->i);
        printf("TEST 2\n");
        move = count_move(begin_a, begin_b, index, maj);
        printf("TEST 3\n");
        printf("index = %d\nmaj = %d\nmove = %d\n", index, maj, move);
        ft_list_push_back_stock(list, index, maj, move);
        printf("TEST 4\n");
        begin = begin->next;
        index++;
    }
}

void final_sort(t_list **begin_a, t_list **begin_b)
{
    t_stock *list;
    t_stock *begin;

    printf("test 1\n");
    create_list(begin_a, begin_b, &list);
    printf("test 2\n");

    printf("\nlist : \n");
    begin = list;
    while (begin)
    {
        printf("index : %d\n", begin->index);
        printf("index_maj : %d\n", begin->index_maj);
        printf("nb_move : %d\n", begin->index_maj);
        begin = begin->next;
        printf("\n\n");
    }
    
}

/*fonction principale du tri*/
int sorting(t_list **begin_a, t_list **begin_b)
{
    int *tab;

    tab = malloc(sizeof(int) * ft_list_size(*begin_a));
    if (!tab)
        return (0);
    create_sort_tab(begin_a, tab);
    keep_just_max(begin_a, begin_b, tab);

    ft_push(begin_a, begin_b);
    ft_push(begin_a, begin_b);
    ft_push(begin_a, begin_b);

    
    final_sort(begin_a, begin_b);

    free(tab);
    return (1);
}