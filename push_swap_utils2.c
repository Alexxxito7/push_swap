/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alschnei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:26:44 by alschnei          #+#    #+#             */
/*   Updated: 2025/01/23 15:26:46 by alschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp && temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	find_min_value(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	get_min_index(t_stack *stack)
{
	int	min;
	int	index;

	min = find_min_value(stack);
	index = 0;
	while (stack)
	{
		if (stack->value == min)
			return (index);
		index++;
		stack = stack->next;
	}
	return (-1);
}

int	get_stack_size(t_stack *stack_a)
{
	int	size;

	size = 0;
	while (stack_a != NULL)
	{
		size++;
		stack_a = stack_a->next;
	}
	return (size);
}

int	check_dup(t_stack *stack, int num)
{
	t_stack	*curr_stack;

	curr_stack = stack;
	while (curr_stack)
	{
		if (curr_stack->value == num)
			return (1);
		curr_stack = curr_stack->next;
	}
	return (0);
}
