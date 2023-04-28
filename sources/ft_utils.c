#include "../headers/push_swap.h"

long int	ft_atoi(const char *str)
{
	int		i;
	long		neg;
	long	n;

	i = 0;
	neg = 1;
	n = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n * neg);
}

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

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
