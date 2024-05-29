/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:40:54 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/02/26 14:10:59 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_push(t_stack **a, t_stack **b, t_step *s)
{
	while (s->ra && s->rb && s->ra-- && s->rb--)
		rotate_r(a, b);
	while (s->rra && s->rrb && s->rra-- && s->rrb--)
		rev_rotate_r(a, b);
	while (s->ra && s->ra--)
		rotate_a(a);
	while (s->rb && s->rb--)
		rotate_b(b);
	while (s->rra && s->rra--)
		rev_rotate_a(a);
	while (s->rrb && s->rrb--)
		rev_rotate_b(b);
	push_b(a, b);
}

int	get_scount(t_step *s)
{
	int	n;

	if (s->ra > s->rb)
		n = s->ra;
	else
		n = s->rb;
	if (s->rra > s->rrb)
		n += s->rra;
	else
		n += s->rrb;
	return (n);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*t;
	t_step	s;
	t_step	min;

	t = *a;
	min.ra = -1;
	while (t)
	{
		s.val = t->val;
		s.ra = 0;
		s.rb = 0;
		s.rra = 0;
		s.rrb = 0;
		count_steps(a, b, &s);
		if (min.ra == -1 || get_scount(&s) < get_scount(&min))
		{
			min.val = s.val;
			min.ra = s.ra;
			min.rb = s.rb;
			min.rra = s.rra;
			min.rrb = s.rrb;
		}
		t = t->next;
	}
	rotate_push(a, b, &min);
}
