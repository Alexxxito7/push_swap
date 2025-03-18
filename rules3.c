/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alschnei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:26:44 by alschnei          #+#    #+#             */
/*   Updated: 2025/01/23 15:26:46 by alschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a, int flag)
{
	t_stack	*last;
	t_stack	*second_last;

	if (stack_a && (*stack_a) && (*stack_a)->next)
	{
		second_last = NULL;
		last = *stack_a;
		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		if (second_last)
			second_last->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
		if (flag)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **stack_b, int flag)
{
	t_stack	*last;
	t_stack	*second_last;

	if (stack_b && (*stack_b) && (*stack_b)->next)
	{
		second_last = NULL;
		last = *stack_b;
		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		if (second_last)
			second_last->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
		if (flag)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && (*stack_a) && (*stack_a)->next)
		rra(stack_a, 0);
	if (stack_b && (*stack_b) && (*stack_b)->next)
		rrb(stack_b, 0);
	write(1, "rrr\n", 3);
}
