/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:35:27 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/02/26 14:08:42 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack **a, int val)
{
	t_stack	*t;
	int		max;

	t = *a;
	if (!t)
		return (val);
	max = get_min_val(*a);
	if (val < max || val > get_max_val(*a))
	{
		while (t)
		{
			if (t->val > max)
				max = t->val;
			t = t->next;
		}
		return (max);
	}
	while (t)
	{
		if (t->val < val && t->val > max)
			max = t->val;
		t = t->next;
	}
	return (max);
}

void	rot_a(t_stack **a, t_step *s)
{
	int		cnt;
	int		n;
	t_stack	*t;

	cnt = get_count(*a);
	t = *a;
	n = 0;
	while (t->next)
	{
		if (t->val == s->val)
			break ;
		n++;
		t = t->next;
	}
	if (n <= cnt / 2)
		s->ra = n;
	else
		s->rra = cnt - n;
}

void	rot_b(t_stack **b, t_step *s)
{
	int		cnt;
	int		n;
	int		max;
	t_stack	*t;

	cnt = get_count(*b);
	t = *b;
	n = 0;
	max = get_max(b, s->val);
	while (t)
	{
		if (t->val == max)
			break ;
		n++;
		t = t->next;
	}
	if (n <= cnt / 2)
		s->rb = n;
	else
		s->rrb = cnt - n;
}

void	count_steps(t_stack **a, t_stack **b, t_step *s)
{
	rot_a(a, s);
	rot_b(b, s);
}
