/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alschnei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:26:44 by alschnei          #+#    #+#             */
/*   Updated: 2025/01/23 15:26:46 by alschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (stack_a && (*stack_a))
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = *stack_b;
		*stack_b = temp;
		write(1, "pb\n", 3);
	}
}

void	ra(t_stack **stack_a, int flag)
{
	t_stack	*top;
	t_stack	*bottom;

	if (stack_a && (*stack_a) && (*stack_a)->next)
	{
		top = *stack_a;
		*stack_a = (*stack_a)->next;
		top->next = NULL;
		bottom = *stack_a;
		while (bottom->next)
			bottom = bottom->next;
		bottom->next = top;
		if (flag)
			write(1, "ra\n", 3);
	}
}

void	rb(t_stack **stack_b, int flag)
{
	t_stack	*top;
	t_stack	*bottom;

	if (stack_b && (*stack_b) && (*stack_b)->next)
	{
		top = *stack_b;
		*stack_b = (*stack_b)->next;
		top->next = NULL;
		bottom = *stack_b;
		while (bottom->next)
			bottom = bottom->next;
		bottom->next = top;
		if (flag)
			write(1, "rb\n", 3);
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	write(1, "rr\n", 3);
}
