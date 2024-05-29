/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:22:59 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/02/22 16:29:02 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack **s)
{
	t_stack	*t;
	t_stack	*last;

	if (!*s || !(*s)->next)
		return (0);
	last = get_last(*s);
	t = *s;
	*s = (*s)->next;
	t->next = NULL;
	last->next = t;
	return (1);
}

void	rotate_a(t_stack **a)
{
	if (rotate(a))
		ft_putendl_fd("ra", 1);
}

void	rotate_b(t_stack **b)
{
	if (rotate(b))
		ft_putendl_fd("rb", 1);
}

void	rotate_r(t_stack **a, t_stack **b)
{
	if (rotate(a) | rotate(b))
		ft_putendl_fd("rr", 1);
}
