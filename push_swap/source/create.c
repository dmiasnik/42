/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:56:05 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/02/06 14:13:34 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_str(char *str)
{
	int	i;
	int	l;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	l = ft_strlen(str);
	if ((str[0] != '-' && l > 10) || (str[0] == '-' && l > 11))
		return (0);
	if (l == 10 && str[0] != '-' && ft_strncmp(str, "2147483647", 10) > 0)
		return (0);
	if (l == 11 && str[0] == '-' && ft_strncmp(str + 1, "2147483648", 10) > 0)
		return (0);
	return (1);
}

int	dupl_ex(t_stack	*s, int val)
{
	while (s)
	{
		if (s->val == val)
			return (1);
		s = s->next;
	}
	return (0);
}

void	create_stack(t_stack **s, char **str)
{
	t_stack	*last;
	t_stack	*t;

	last = get_last(*s);
	while (*str)
	{
		if (!check_str(*str))
			exit_free(*s, 1);
		t = malloc(sizeof(*t));
		if (!t)
			exit_free(*s, 1);
		t->val = ft_atoi(*str);
		t->next = NULL;
		if (dupl_ex(*s, t->val))
			exit_free(*s, 1);
		if (!*s)
			*s = t;
		if (last)
			last->next = t;
		last = t;
		str++;
	}
}
