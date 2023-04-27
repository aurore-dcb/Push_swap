#include "push_swap.h"

void display_tab(int *tab, int len)
{
    int i = 0;
    while (i < len)
    {
        printf("tab[%d] = %d\n", i, tab[i]);
        i++;
    }
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

void displays(t_list **begin_a, t_list **begin_b)
{
	t_list *start;

	start = *begin_a;
	printf("pile a :\n");
	if (start != NULL)
	{
		while (start)
		{
			printf("%d\n", start->i);
			start = start->next;
		}
	}
	start = *begin_b;
	printf("\npile b :\n");
	if (start != NULL)
	{
		while (start)
		{
			printf("%d\n", start->i);
			start = start->next;
		}
	}
}

int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
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
		if (n * neg < -2147483648)
			return (0);
		else if (n * neg > 2147483647)
			return (-1);
		i++;
	}
	return (n * neg);
}