/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alschnei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:26:44 by alschnei          #+#    #+#             */
/*   Updated: 2025/01/23 15:26:46 by alschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

t_stack	*new_node(int num)
{
	t_stack	*node;

	node = (t_stack *) malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = num;
	node->next = NULL;
	return (node);
}

void	free_node(t_stack **node)
{
	t_stack	*temp;

	if (!node || !(*node))
		return ;
	while (*node)
	{
		temp = (*node)->next;
		free(*node);
		*node = temp;
	}
	*node = NULL;
}

void	ft_add_back(t_stack **stack_a, t_stack *new)
{
	t_stack	*pnt;

	if (!new)
		return ;
	if (*stack_a == NULL)
	{
		*stack_a = new;
		return ;
	}
	pnt = *stack_a;
	while (pnt->next)
		pnt = pnt->next;
	pnt->next = new;
}

t_stack	*check_createlist(char **argv)
{
	int		i;
	int		j;
	t_stack	*stack_a;
	t_stack	*new;

	stack_a = NULL;
	i = -1;
	if (argv[0][0] == '.')
		i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]) && !(j == 0 && (argv[i][j] == '-'
			|| argv[i][j] == '+') && ft_isdigit(argv[i][j + 1])))
				return (free_node(&stack_a), NULL);
		}
		new = new_node(ft_atoi(argv[i]));
		if (!new || check_dup(stack_a, ft_atoi(argv[i])))
			return (free_node(&stack_a), NULL);
		ft_add_back(&stack_a, new);
	}
	return (stack_a);
}
