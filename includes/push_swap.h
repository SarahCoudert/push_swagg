/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 14:01:12 by scoudert          #+#    #+#             */
/*   Updated: 2015/06/09 14:04:22 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void			read_list(t_list *list, char *name);
void			test_function(t_list *a);
void			create_list(t_list **lst, char **av, int ac);
void			check(char *s);
void			swap_a(t_list *a);
void			swap_b(t_list *b);
void			ss(t_list *a, t_list *b);
void			push_a(t_list **a, t_list **b);
void			push_b(t_list **a, t_list **b);
void			rotate_a(t_list **a);
void			rotate_b(t_list **b);
void			rr(t_list **a, t_list **b);
void			reverse_rotate_a(t_list **a);
void			reverse_rotate_b(t_list **b);
void			rrr(t_list **a, t_list **b);
void			selection(t_list **a, int size);
void			swap_element(t_list **a, t_list **b, int max, int way);
void			get_elements(t_list **a, t_list **b, int pivot);
int				check_order(t_list **ptr, int check);
void			medianne(t_list *a, int *size, int nb_rot, int *pivot);
int				selection_tab(int *tab, int size);
void			swap(int *a, int *b);
void			push_sort(t_list **a, int lst_size, int size, int pivot);
void			ft_quicksort(t_list **a, int pivot, int size, int *nb_rot);
void			order_list(t_list **a, int element_b, int *nb_rot);
void			three_elements(t_list **lst);
void			swap_elements(int way, t_list **a, int pb);
int				min_lst(t_list *a);
void			two_elements(t_list **a);
void			four_or_five_elements(int size, t_list ** a);

enum			e_sens   	
{
				UP,
				DOWN
};

#endif
