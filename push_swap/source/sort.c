/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:56:44 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/02/26 14:09:32 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack **a)
{
	if ((*a)->next->val > (*a)->val && (*a)->next->val > (*a)->next->next->val)
		rev_rotate_a(a);
	if ((*a)->val > (*a)->next->val && (*a)->val > (*a)->next->next->val)
		rotate_a(a);
	if ((*a)->val > (*a)->next->val)
		swap_a(a);
}

int	is_sort(t_stack **a)
{
	t_stack	*t;
	int		c;

	t = *a;
	c = 0;
	while (t->next)
	{
		if (t->val > t->next->val)
			c++;
		if (c > 1)
			return (0);
		t = t->next;
	}
	if (c == 1 && t->val > (*a)->val)
		return (0);
	return (1);
}

void	final_sort(t_stack **a)
{
	int		cnt;
	int		s;
	t_stack	*t;

	cnt = get_count(*a);
	t = *a;
	s = 0;
	while (t)
	{
		s++;
		if (t->next && t->val > t->next->val)
			break ;
		t = t->next;
	}
	if (s <= cnt / 2)
		while (s--)
			rotate_a(a);
	else
		while (s++ < cnt)
			rev_rotate_a(a);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	cnt;

	cnt = get_count(*a);
	if (cnt <= 1)
		return ;
	if (cnt == 2)
	{
		if ((*a)->val > (*a)->next->val)
			swap_a(a);
		return ;
	}
	while (!is_sort(a))
	{
		if (cnt == 3)
		{
			sort3(a);
			break ;
		}
		push_to_b(a, b);
		cnt--;
	}	
	return_all(a, b);
	final_sort(a);
}
