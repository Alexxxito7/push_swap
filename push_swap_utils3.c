/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alschnei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:26:44 by alschnei          #+#    #+#             */
/*   Updated: 2025/01/23 15:26:46 by alschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkswap(t_stack **stack_a, t_stack **stack_b)
{
	if (get_stack_size(*stack_b) > 1 && get_stack_size(*stack_a) > 1)
	{
		if ((*stack_b)->value < (*stack_b)->next->value)
		{
			if ((*stack_a)->value > (*stack_a)->next->value)
			{
				ss(stack_a, stack_b);
			}
			else
			{
				sb(stack_b, 1);
			}
		}
		else if ((*stack_a)->value > (*stack_a)->next->value)
		{
			sa(stack_a, 1);
		}
	}
}

void	checkrotate(t_stack **stack_a, t_stack **stack_b, int median)
{
	if (get_stack_size(*stack_a) > 2 && get_stack_size(*stack_b) > 2)
	{
		if (rank((*stack_b)->value, (*stack_b)->next->value)
			> rank((*stack_b)->value, last_node(*stack_b)))
		{
			if (rank((*stack_a)->value, (*stack_a)->next->value)
				> rank((*stack_a)->value, last_node(*stack_a))
				&& (*stack_a)->value > median)
			{
				rr(stack_a, stack_b);
			}
			else
			{
				rb(stack_b, 1);
			}
		}
		else if ((rank((*stack_a)->value, (*stack_a)->next->value)
				> rank((*stack_a)->value, last_node(*stack_a)))
			&& (*stack_a)->value > median)
		{
			ra(stack_a, 1);
		}
	}
}

int	rank(int a, int b)
{
	int	result;

	result = a - b;
	if (result < 0)
		result *= -1;
	return (result);
}

int	last_node(t_stack *stack)
{
	t_stack	*pnt;

	pnt = stack;
	while (pnt->next)
	{
		pnt = pnt->next;
	}
	return (pnt->value);
}

int	*stack_to_array(t_stack *stack, int size)
{
	int		i;
	int		*arr;
	t_stack	*temp;

	i = 0;
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	temp = stack;
	while (temp && i < size)
	{
		arr[i++] = temp->value;
		temp = temp->next;
	}
	if (i != size)
		return (free(arr), NULL);
	return (arr);
}
