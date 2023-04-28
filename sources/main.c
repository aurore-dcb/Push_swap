#include "../headers/push_swap.h"

void free_list(t_stock **begin)
{
    t_stock *current = *begin;
    t_stock *temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

/*fonction principale du tri*/
int sorting(t_list **begin_a, t_list **begin_b)
{
    int *tab;
    t_stock *list;
    int max;

    if (already_sort(begin_a))
        return (1);
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
        create_list(begin_a, begin_b, &list, max);
        move_elem(begin_a, begin_b, &list);
        ft_push(begin_a, begin_b);
        ft_putstr("pa\n");
        free_list(&list);
    }
    last_rotation(begin_a);
    return (1);
}

int main(int argc, char **argv)
{
    t_list *begin_a;
    t_list *begin_b;

    begin_a = NULL;
    begin_b = NULL;
    if (argc > 1)
    {   
        if (ft_parsing(argv, &begin_a) == 0)
        {
            ft_putstr("Error\n");
            return (0);
        }
        // algo de tri
        if (sorting(&begin_a, &begin_b) == 0)
        {
            ft_putstr("Error\n");
            return (0);
        }
    }
    else
        ft_putstr("Error\n");
}