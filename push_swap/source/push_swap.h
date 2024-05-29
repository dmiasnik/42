/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:26:20 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/02/26 14:08:50 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}	t_stack;

typedef struct s_step
{
	int	val;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}	t_step;

void	exit_free(t_stack *s, int err);
void	sort_stack(t_stack **a, t_stack **b);
void	create_stack(t_stack **s, char **str);
t_stack	*get_last(t_stack *s);
int		get_count(t_stack *s);

void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_ab(t_stack **a, t_stack **b);

void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);

void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_r(t_stack **a, t_stack **b);

void	rev_rotate_a(t_stack **a);
void	rev_rotate_b(t_stack **b);
void	rev_rotate_r(t_stack **a, t_stack **b);

void	return_all(t_stack **a, t_stack **b);
void	push_to_b(t_stack **a, t_stack **b);
void	rotate_first(t_stack **a, int first);
void	count_steps(t_stack **a, t_stack **b, t_step *s);
int		get_min_val(t_stack *a);
int		get_max_val(t_stack *a);

#endif