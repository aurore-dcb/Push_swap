/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:54:00 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/27 02:04:01 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct s_stack
{
	int				i;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stock
{
	int				index;
	int				index_maj;
	int				nb_move;
	struct s_stock	*next;
}					t_stock;

int					ft_list_size(t_stack *begin);
t_stack				*ft_create_elem(int data);
int					ft_list_push_back(t_stack **begin_list, int data);
void				ft_putstr(char *str);

void				ft_swap(t_stack **begin, char c);
void				ft_push(t_stack **begin_dst, t_stack **begin_src, char c);
void				ft_rotate(t_stack **begin, char c);
void				ft_rev_rotate(t_stack **begin, char c);

void				ft_sswap(t_stack **begin_a, t_stack **begin_b);
void				ft_rrotate(t_stack **begin_a, t_stack **begin_b);
void				ft_rrev_rotate(t_stack **begin_a, t_stack **begin_b);

int					only_numbers(char **argv);
int					no_doubles(char **argv);
int					arg_lenght(char **arg);
int					already_sort(t_stack **begin_a);
int					ft_parsing(char **argv, t_stack **begin_a);

int					*sort_int_tab(t_stack **begin_a, int *tab);
void				create_sort_tab(t_stack **begin_a, int *tab);
int					find_max(int *tab, int len);
void				keep_just_max(t_stack **begin_a, t_stack **begin_b,
						int *tab);

t_stock				*ft_create_elem_stock(int i, int maj, int move);
int					ft_list_push_back_stock(t_stock **begin_list, int i,
						int maj, int move);
int					index_maj(t_stack **begin_a, int nb, int max);
int					count_move(t_stack **begin_a, t_stack **begin_b, int index,
						int maj);
int					create_list(t_stack **begin_a, t_stack **begin_b,
						t_stock **list, int max);

void				move_stack_b(t_stack **begin_b, int index);
void				move_stack_a(t_stack **begin_a, int index_maj);
void				move_elem(t_stack **begin_a, t_stack **begin_b,
						t_stock **list);
int					index_in_list(t_stack **begin_list, int nb);
void				last_rotation(t_stack **begin_a);

void				free_list1(t_stack **begin);
void				free_list(t_stock **begin);
int					sorting(t_stack **begin_a, t_stack **begin_b);

int					special_cases(t_stack **begin_a, t_stack **begin_b);
int					match(t_stack **begin_a, int a, int b, int c);
void				taille_3(t_stack **begin_a);
void				taille_5(t_stack **begin_a, t_stack **begin_b);

#endif