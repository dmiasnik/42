/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:28:27 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/02/22 16:29:09 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rev_rotate(t_stack **s)
{
	t_stack	*t;
	t_stack	*last;

	if (!*s || !(*s)->next)
		return (0);
	last = get_last(*s);
	t = *s;
	while (t)
	{
		if (t->next == last)
			t->next = NULL;
		t = t->next;
	}
	last->next = *s;
	*s = last;
	return (1);
}

void	rev_rotate_a(t_stack **a)
{
	if (rev_rotate(a))
		ft_putendl_fd("rra", 1);
}

void	rev_rotate_b(t_stack **b)
{
	if (rev_rotate(b))
		ft_putendl_fd("rrb", 1);
}

void	rev_rotate_r(t_stack **a, t_stack **b)
{
	if (rev_rotate(a) | rev_rotate(b))
		ft_putendl_fd("rrr", 1);
}
