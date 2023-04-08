#include "push_swap.h"

// que des nombres
int only_numbers(char **argv)
{
    int i;
    int j;

    i = 1;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

// pas de doublons
int no_doubles(char **argv)
{
    int i;
    int j;

    i = 0;
    while (argv[i])
    {
        j = i + 1;
        while (argv[j])
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

// pas plus grand qu'un int


t_list *ft_create_elem(int data)
{
    t_list *elem;

    elem = malloc(sizeof(t_list));
    if(!elem)
        return (NULL);
    elem->i = data;
    elem->next = NULL;
    return(elem);
}

void ft_list_push_back(t_list **begin_list, int data)
{
    t_list *list;

    list = *begin_list;
    if (list)
    {
        while (list->next)
            list = list->next;
        list->next = ft_create_elem(data);
    }
	else
		*begin_list = ft_create_elem(data);
}

int ft_parsing(char **argv, t_list **begin_a)
{
    int i;

    if (!only_numbers(argv))
        return (0);
    if (!no_doubles(argv))
        return (0);
    i = 1;
    while (argv[i])
    {
        ft_list_push_back(begin_a, ft_atoi(argv[i]));
        i++;
    }
    return (1);
}