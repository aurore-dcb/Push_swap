#include "push_swap.h"

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