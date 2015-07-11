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

void		test_function(t_list *a)
{
	t_list		*b;

	b = NULL;
	read_list(a, "pile a : ");
	swap_a(a);
	read_list(a, "after swap : ");
	push_b(&a, &b);
	read_list(a, "a after push b");
	read_list(b, "b after push b");
	push_b(&a, &b);
	read_list(a, "a after push b");
	read_list(b, "b after push b");
	swap_b(b);
	read_list(b, "b after swap b");
}

void		swap_a(t_list *a)
{
	t_list		*ptr;
	int			temp;

	ptr = a;
	temp = ptr->content;
	ptr->content = ptr->next->content;
	ptr->next->content = temp;
}

void		swap_b(t_list *b)
{
	t_list		*ptr;
	int			temp;

	ptr = b;
	temp = ptr->content;
	ptr->content = ptr->next->content;
	ptr->next->content = temp;
}
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

void		push_b(t_list **a, t_list **b)
{
	t_list		*ptr;

	ptr = *a;
	//void	ft_lstcpelement(t_list *copy_from, t_list **copy_to)
	ft_lstcpelement(*a, b);
	*a = (*a)->next;
	free(ptr);
}

void		push_a(t_list **a, t_list **b)
{
	t_list		*ptr;

	ptr = *b;
	//void	ft_lstcpelement(t_list *copy_from, t_list **copy_to)
	ft_lstcpelement(*b, a);
	*b = (*b)->next;
	free(ptr);
}