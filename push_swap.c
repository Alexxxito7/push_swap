/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alschnei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:26:44 by alschnei          #+#    #+#             */
/*   Updated: 2025/01/23 15:26:46 by alschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**splitarr;
	int		size;

	if (argc < 2)
		return (write(1, "Error\n", 6));
	if (argc == 2)
	{
		splitarr = ft_split(argv[1], ' ');
		if (!splitarr)
			return (write(1, "Error\n", 6));
		stack_a = check_createlist(splitarr, 0);
		free_array(splitarr);
	}
	else
		stack_a = check_createlist(argv, 1);
	if (!stack_a)
		return (write(1, "Error\n", 6));
	stack_b = NULL;
	size = get_stack_size(stack_a);
	quicksort_stack(&stack_a, &stack_b, size);
	return (free_node(&stack_a), free_node(&stack_b), 0);
}
