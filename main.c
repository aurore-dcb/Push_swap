#include "ft.h"

void ft_swap(t_list **begin)
{
    printf("size a : %d\n", ft_list_size(*begin));

    t_list *tmp;
    if (*begin && (*begin)->next)
    {
        tmp = (*begin)->next;
        (*begin)->next = tmp->next;
        tmp->next = *begin;
        *begin = tmp;
    }
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    t_list elem1, elem2, elem3, elem4, *begin1;

    begin1 = &elem1;
    elem1.next = &elem2;
    elem2.next = &elem3;
    elem3.next = &elem4;
    elem4.next = NULL;

    elem1.i = 4;
    elem2.i = 19;
    elem3.i = -2;
    elem4.i = 444;

    t_list *begin2, elem5, elem6, elem7;

    begin2 = &elem5;
    elem5.next = &elem6;
    elem6.next = &elem7;
    elem7.next = NULL;

    elem5.i = 1;
    elem6.i = 64;
    elem7.i = -8;

    ft_swap(&begin1);
    ft_swap(&begin2);

    while (begin1)
    {
        printf("%d, ", (begin1)->i);
        begin1 = (begin1)->next;
    }
    printf("\n");
    while (begin2)
    {
        printf("%d, ", begin2->i);
        begin2 = begin2->next;
    }
    printf("\n");
}