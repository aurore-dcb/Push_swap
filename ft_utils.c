#include "ft.h"

int ft_list_size(t_list *begin)
{
    int i;

    i = 0;
    while (begin)
    {
        i++;
        begin = begin->next;
    }
    return (i);
}