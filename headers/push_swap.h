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

// ft_utils
long int	ft_atoi(const char *str);
int ft_list_size(t_list *begin);
t_list *ft_create_elem(int data);
void ft_list_push_back(t_list **begin_list, int data);
void ft_putstr(char *str);

// sorting_fct
void ft_swap(t_list **begin);
void ft_push(t_list **begin_dst, t_list **begin_src);
void ft_rotate(t_list **begin);
void ft_rev_rotate(t_list **begin);

// parsing
int only_numbers(char **argv);
int no_doubles(char **argv);
int arg_lenght(char **arg);
int already_sort(t_list **begin_a);
int ft_parsing(char **argv, t_list **begin_a);

// first_sort
int *sort_int_tab(t_list **begin_a, int *tab);
void create_sort_tab(t_list **begin_a, int *tab);
int find_max(int *tab, int len);
void keep_just_max(t_list **begin_a, t_list **begin_b, int *tab);

// create_list
t_stock *ft_create_elem_stock(int i, int maj, int move);
void ft_list_push_back_stock(t_stock **begin_list, int i, int maj, int move);
int index_maj(t_list **begin_a, int nb, int max);
int count_move(t_list **begin_a, t_list **begin_b, int index, int maj);
void create_list(t_list **begin_a, t_list **begin_b, t_stock **list, int max);

// sorting_move
void move_stack_b(t_list **begin_b, int index);
void move_stack_a(t_list **begin_a, int index_maj);
void move_elem(t_list **begin_a, t_list **begin_b, t_stock **list);
int index_in_list(t_list **begin_list, int nb);
void last_rotation(t_list **begin_a);

// main
void free_list(t_stock **begin);
int sorting(t_list **begin_a, t_list **begin_b);

#endif