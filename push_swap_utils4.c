/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alschnei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:26:44 by alschnei          #+#    #+#             */
/*   Updated: 2025/01/23 15:26:46 by alschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (is_sorted(*stack_a))
		return ;
	else if (size <= 5)
		sort_small_size(stack_a, stack_b, size);
	else
		sort_bigger(stack_a, stack_b);
}

void	to_stack_b(t_stack **stack_a, t_stack **stack_b, int median, int n)
{
	while (n && get_stack_size(*stack_a) > 1)
	{
		checkrotate(stack_a, stack_b, median);
		checkswap(stack_a, stack_b);
		if ((*stack_a)->value <= median)
		{
			pb(stack_a, stack_b);
			n--;
		}
		else
			ra(stack_a, 1);
	}
}

void	to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int	s_len;

	s_len = get_stack_size(*stack_b);
	while (s_len > 1)
	{
		if (!top_is_biggest(stack_b))
		{
			if (max_position(stack_b) > get_stack_size(*stack_b) / 2)
				rrb(stack_b, 1);
			else
				rb(stack_b, 1);
		}
		else
		{
			pa(stack_a, stack_b);
			s_len--;
		}
	}
}

int	top_is_biggest(t_stack **stack)
{
	int			num;
	t_stack		*pnt;

	pnt = *stack;
	num = pnt->value;
	while (pnt)
	{
		if (pnt->value > num)
		{
			return (0);
		}
		pnt = pnt->next;
	}
	return (1);
}

int	max_position(t_stack **stack)
{
	int			num;
	int			i;
	t_stack		*pnt;

	pnt = (*stack);
	num = pnt -> value;
	i = 0;
	while (pnt)
	{
		if (pnt->value > num)
		{
			num = pnt->value;
		}
		pnt = pnt->next;
	}
	pnt = (*stack);
	while (pnt)
	{
		if (pnt->value == num)
			break ;
		pnt = pnt->next;
		i++;
	}
	return (i);
}
