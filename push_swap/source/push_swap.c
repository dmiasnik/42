/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:32:51 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/02/26 14:05:49 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_last(t_stack *s)
{
	t_stack	*last;

	last = s;
	while (last && last->next)
		last = last->next;
	return (last);
}

int	get_count(t_stack *s)
{
	int	cnt;

	if (!s)
		return (0);
	cnt = 1;
	while (s->next)
	{
		s = s->next;
		cnt++;
	}
	return (cnt);
}

void	exit_free(t_stack *s, int err)
{
	t_stack	*t;

	while (s)
	{
		t = s->next;
		free(s);
		s = t;
	}
	if (err)
		ft_putendl_fd("Error", 1);
	exit(0);
}

void	free_arr(char **str)
{
	char	**t;

	t = str;
	while (*t)
	{
		free(*t);
		t++;
	}
	if (str)
		free(str);
}

int	main(int cnt, char *arg[])
{
	t_stack	*a;
	t_stack	*b;
	char	**str;

	if (cnt == 1)
		return (0);
	a = NULL;
	b = NULL;
	arg++;
	while (--cnt)
	{
		str = ft_split(*arg, ' ');
		create_stack(&a, str);
		free_arr(str);
		arg++;
	}
	sort_stack(&a, &b);
	exit_free(a, 0);
	return (0);
}
