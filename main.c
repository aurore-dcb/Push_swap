#include "push_swap.h"

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
            printf("Erreur lors du parsing\n");
            return (0);
        }
        printf("parsing ok\n");
    }
    ft_swap(&begin_a);
    ft_push(&begin_b, &begin_a);
    ft_push(&begin_b, &begin_a);
    ft_push(&begin_b, &begin_a);
    ft_swap(&begin_a);
    ft_push(&begin_a, &begin_b);
    ft_push(&begin_a, &begin_b);
    ft_push(&begin_a, &begin_b);

    while (begin_a)
    {
        printf("%d, ", (begin_a)->i);
        begin_a = (begin_a)->next;
    }
    printf("\n");
    while (begin_b)
    {
        printf("%d, ", begin_b->i);
        begin_b = begin_b->next;
    }
    printf("\n");
}