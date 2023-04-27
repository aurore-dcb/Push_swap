# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>

typedef struct s_list
{
    int i;
    struct s_list *next;
} t_list;

typedef struct s_stock
{
    int index;
    int index_maj;
    int nb_move;
    struct s_stock *next;
} t_stock;

void display_tab(int *tab, int len);
int ft_list_size(t_list *begin);
int	ft_atoi(const char *str);


// sorting functions
void ft_swap(t_list **begin);
void ft_push(t_list **begin_dst, t_list **begin_src);
void ft_rotate(t_list **begin);
void ft_rev_rotate(t_list **begin);

// parsing
int ft_parsing(char **argv, t_list **begin_a);
int only_numbers(char **argv);
t_list *ft_create_elem(int data);

// tri
int sorting(t_list **begin_a, t_list **begin_b);

// t_stock *ft_create_elem_stock(int i, int maj, int move);

#endif