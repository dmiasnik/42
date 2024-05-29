/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:33:40 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/02/22 16:29:27 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **a)
{
	t_stack	*t;

	if (!*a || !(*a)->next)
		return ;
	t = *a;
	*a = (*a)->next;
	t->next = (*a)->next;
	(*a)->next = t;
	ft_putendl_fd("sa", 1);
}

void	swap_b(t_stack **b)
{
	t_stack	*t;

	if (!*b || !(*b)->next)
		return ;
	t = *b;
	*b = (*b)->next;
	t->next = (*b)->next;
	(*b)->next = t;
	ft_putendl_fd("sb", 1);
}

void	swap_ab(t_stack **a, t_stack **b)
{
	if ((!*a || !(*a)->next) && (!*b || !(*b)->next))
		return ;
	swap_a(a);
	swap_b(b);
	ft_putendl_fd("ss", 1);
}

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*t;

	if (!*b)
		return ;
	t = *b;
	*b = (*b)->next;
	t->next = *a;
	*a = t;
	ft_putendl_fd("pa", 1);
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*t;

	if (!*a)
		return ;
	t = *a;
	*a = (*a)->next;
	t->next = *b;
	*b = t;
	ft_putendl_fd("pb", 1);
}
