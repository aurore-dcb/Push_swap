#include "../headers/push_swap.h"

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