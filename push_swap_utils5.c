/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alschnei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:26:44 by alschnei          #+#    #+#             */
/*   Updated: 2025/01/23 15:26:46 by alschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_size(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
	{
		if (!is_sorted(*stack_a))
			sa(stack_a, 1);
	}
	else if (size == 3)
	{
		sort_three(stack_a);
	}
	else if (size == 4 || size == 5)
	{
		sort_fourfive(stack_a, stack_b);
	}
}

void	sort_three(t_stack **stack_a)
{
	int	top;
	int	mid;
	int	bottom;

	top = (*stack_a)->value;
	mid = (*stack_a)->next->value;
	bottom = (*stack_a)->next->next->value;
	if (top > mid && mid < bottom && top < bottom)
		sa(stack_a, 1); // Case: 2 1 3 → 1 2 3
	else if (top > mid && mid > bottom)
	{
		sa(stack_a, 1); // Case: 3 2 1 → 2 3 1
		rra(stack_a, 1); // → 1 2 3
	}
	else if (top > mid && mid < bottom && top > bottom)
		ra(stack_a, 1); // Case: 3 1 2 → 1 2 3
	else if (top < mid && mid > bottom && top < bottom)
	{
		sa(stack_a, 1); // Case: 1 3 2 → 3 1 2
		ra(stack_a, 1); // → 1 2 3
	}
	else if (top < mid && mid > bottom && top > bottom)
		rra(stack_a, 1); // Case: 2 3 1 → 1 2 3
}

void	sort_fourfive(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	while (get_stack_size(*stack_a) > 3)
	{
		min = find_min_value(*stack_a);
		while ((*stack_a)->value != min)
		{
			if (get_min_index(*stack_a) <= get_stack_size(*stack_a) / 2)
				ra(stack_a, 1);
			else
				rra(stack_a, 1);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	sort_bigger(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	n;

	n = 2;
	size = get_stack_size(*stack_a);
	n = size / 5;
	if (size > 250 && size <= 500)
		n = size / 7;
	if (size > 100 && size <= 250)
		n = size / 6;
	if (size < 20)
		n = size / 2;
	while (get_stack_size(*stack_a) > 1 && !is_sorted(*stack_a))
	{
		to_stack_b(stack_a, stack_b, find_nth_smallest(*stack_a, size), n);
	}
	to_stack_a(stack_a, stack_b);
	pa(stack_a, stack_b);
}

int	find_nth_smallest(t_stack *stack, int n)
{
	int		min_value;
	int		num;
	int		j;
	t_stack	*pnt;

	min_value = find_min_value(stack);
	j = 0;
	while (j < n)
	{
		num = __INT_MAX__;
		pnt = stack;
		while (pnt)
		{
			if (pnt->value > min_value && pnt->value < num)
				num = pnt->value;
			pnt = pnt->next;
		}
		min_value = num;
		j++;
	}
	return (min_value);
}
