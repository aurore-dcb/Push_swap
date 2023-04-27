#include "../headers/push_swap.h"

void free_list(t_stock *begin)
{
    t_stock *current = begin;
    t_stock *temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int index_in_list(t_list **begin_list, int nb)
{
    int i;
    t_list *list;

    i = 0;
    list = *begin_list;
    while (list)
    {
        if (list->i == nb)
            return (i);
        list = list->next;
        i++;
    }
    return (-1);
}

void derniere(t_list **begin_a)
{
    int min;
    int index;
    t_list *begin;

    min = (*begin_a)->i;
    begin = *begin_a;
    while (begin)
    {
        if (begin->i < min)
            min = begin->i;
        begin = begin->next;
    }
    index = index_in_list(begin_a, min);
    move_stack_a(begin_a, index);
}
/*fonction principale du tri*/
int sorting(t_list **begin_a, t_list **begin_b)
{
    int *tab;
    t_stock *list;
    int max;

    tab = malloc(sizeof(int) * ft_list_size(*begin_a));
    if (!tab)
        return (0);
    create_sort_tab(begin_a, tab);
    keep_just_max(begin_a, begin_b, tab);
    free(tab);
    max = (*begin_a)->i;
    while (*begin_b)
    {
        list = NULL;
        final_sort(begin_a, begin_b, &list, max);
        free_list(list);
    }
    derniere(begin_a);
    return (1);
}

int main(int argc, char **argv)
{
    t_list *begin_a;
    t_list *begin_b;

    if (argc > 1)
    {
        begin_a = NULL;
        if (ft_parsing(argv, &begin_a) == 0)
        {
            printf("Error\n");
            return (0);
        }
        begin_b = NULL;

        // algo de tri
        if (sorting(&begin_a, &begin_b) == 0)
        {
            printf("Erreur lors du tri\n");
            return (0);
        }

        // displays(&begin_a, &begin_b);
    }
    else
        printf("Error\n");
}