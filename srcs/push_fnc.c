/*
** sa : swap a intervertit les 2 premiers éléments au sommet de la pile a. (ne fait rien s’il n’y en a qu’un ou aucun).
** sb : swap b - intervertit les 2 premiers éléments au sommet de la pile b.(ne fait rien s’il n’y en a qu’un ou aucun).
** ss : sa et sb en même temps.
** pa : push a - prend le premier élément au sommet de b et le met sur a. (ne fait rien si b est vide).
** pb : push b - prend le premier élément au sommet de a et le met sur b. (ne fait rien si a est vide).
** ra : rotate a - décale d’une position tous les élements de la pile a. (vers le haut, le premier élément devient le dernier).
** rb : rotate b - décale d’une position tous les élements de la pile b. (vers le haut, le premier élément devient le dernier).
** rr : ra et rb en meme temps.
** rra : reverse rotate a (vers le bas, le dernier élément devient le premier).
** rrb : reverse rotate b (vers le bas, le dernier élément devient le premier).
** rrr : rra et rrb en même temps.
*/

#include "push_swap.h"

void		read_list(t_list *list, char *name)
{
	t_list	*ptr;
	int		*j;

	j = 0;
	ft_putstr(name);
	ft_putendl("");
	ptr  = list;
	while (ptr)
	{
		ft_putstr("\t");
		ft_putnbr(ptr->content);
		putn();
		ptr = ptr->next;
	}
}

void		swap_a(t_list *a)
{
	t_list	*ptr;
	int		temp;

	ptr = a;
	temp = ptr->content;
	ptr->content = ptr->next->content;
	ptr->next->content = temp;
}

void		swap_b(t_list *b)
{
	t_list	*ptr;
	int		temp;

	ptr = b;
	temp = ptr->content;
	ptr->content = ptr->next->content;
	ptr->next->content = temp;
}

void		ss(t_list *a, t_list *b)
{
	swap_a(a);
	swap_b(b);
}


void		push_b(t_list **a, t_list **b)
{
	t_list	*ptr;

	ptr = *a;
	*b = ft_lstcpelement(*a, *b);
	*a = (*a)->next;
	free(ptr);
}

void		push_a(t_list **a, t_list **b)
{
	t_list		*ptr;

	ptr = *b;
	*b = ft_lstcpelement(*b, *a);
	*b = (*b)->next;
	free(ptr);
}

void		rotate_a(t_list **a)
{
	int		temp;
	t_list	*alst;

	alst = *a;
	temp = alst->content;
	while (alst->next)
	{
		alst->content = alst->next->content;
		alst = alst->next;
	}
	alst->content = temp;
}


void		rotate_b(t_list **b)
{
	int		temp;
	t_list	*alst;

	alst = *b;
	temp = alst->content;
	while (alst->next)
	{
		alst->content = alst->next->content;
		alst = alst->next;
	}
	alst->content = temp;
}

void		rr(t_list **a, t_list **b)
{
	rotate_a(a);
	rotate_b(b);
}

void		reverse_rotate_a(t_list **a)
{
	int		prev;
	int		tmp;
	t_list	*alst;

	alst = *a;
	tmp = 0;
	prev = (*a)->content;
	while (alst)
	{
		tmp = alst->content;
		alst->content = prev;
		prev = tmp;
		alst = alst->next;
	}
	alst = *a;
	alst->content = prev;
}

void		reverse_rotate_b(t_list **b)
{
	int		prev;
	int		tmp;
	t_list	*alst;

	alst = *b;
	tmp = 0;
	prev = (*b)->content;
	while (alst)
	{
		tmp = alst->content;
		alst->content = prev;
		prev = tmp;
		alst = alst->next;
	}
	alst = *b;
	alst->content = prev;
}

void		rrr(t_list **a, t_list **b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
}