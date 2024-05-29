/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:59:29 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/02/26 14:11:20 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_val(t_stack *a)
{
	int	min;

	min = a->val;
	while (a)
	{
		if (a->val < min)
			min = a->val;
		a = a->next;
	}
	return (min);
}

int	get_max_val(t_stack *a)
{
	int	max;

	max = a->val;
	while (a)
	{
		if (a->val > max)
			max = a->val;
		a = a->next;
	}
	return (max);
}

int	get_min(t_stack **a, int val)
{
	t_stack	*t;
	int		min;

	t = *a;
	min = get_max_val(*a);
	if (val < get_min_val(*a) || val > min)
	{
		while (t)
		{
			if (t->val < min)
				min = t->val;
			t = t->next;
		}
		return (min);
	}
	while (t)
	{
		if (t->val > val && t->val < min)
			min = t->val;
		t = t->next;
	}
	return (min);
}

void	rotate_first(t_stack **a, int first)
{
	int		cnt;
	int		s;
	t_stack	*t;

	cnt = get_count(*a);
	t = *a;
	s = 0;
	while (t->next)
	{
		if (t->val == first)
			break ;
		s++;
		t = t->next;
	}
	if (s < cnt / 2)
		while (s--)
			rotate_a(a);
	else
		while (s++ < cnt)
			rev_rotate_a(a);
}

void	return_all(t_stack **a, t_stack **b)
{
	int	val;

	while (*b)
	{
		val = get_min(a, (*b)->val);
		rotate_first(a, val);
		push_a(a, b);
	}
}
