#include "push_swap.h"

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

    max = (*begin_a)->i;

    displays(begin_a, begin_b);
    printf("\n");

    list = NULL;

    // affiche les données
    final_sort(begin_a, begin_b, &list, max);

    free(tab);
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
        // else
        // {
        //     printf("Tri ok\n");
        // }
        // fin tri

        // ft_swap(&begin_a);
        // ft_push(&begin_b, &begin_a);
        // ft_push(&begin_b, &begin_a);
        // ft_push(&begin_b, &begin_a);
        // ft_swap(&begin_a);
        // ft_push(&begin_a, &begin_b);
        // ft_push(&begin_a, &begin_b);
        // ft_push(&begin_a, &begin_b);

        printf("\nPile a : \n");
        while (begin_a)
        {
            printf("%d", (begin_a)->i);
            begin_a = (begin_a)->next;
            printf("\n");
        }
        printf("\nPile b : \n");
        while (begin_b)
        {
            printf("%d", begin_b->i);
            begin_b = begin_b->next;
            printf("\n");
        }
    }
    else
        printf("Error\n");
}