/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alschnei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:26:44 by alschnei          #+#    #+#             */
/*   Updated: 2025/01/23 15:26:46 by alschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct t_stack
{
	int				value;
	struct t_stack	*next;
}					t_stack;

void	sort_stack_b(t_stack **stack_b);
void	sort_small_size(t_stack **stack_a, t_stack **stack_b, int size);
void	sort_three(t_stack **stack_a);
void	sort_fourfive(t_stack **stack_a, t_stack **stack_b);
void	sort_bigger(t_stack **stack_a, t_stack **stack_b);
int		*stack_to_array(t_stack *stack, int size);
int		max_position(t_stack **stack);
void	checkswap(t_stack **stack_a, t_stack **stack_b);
void	checkrotate(t_stack **stack_a, t_stack **stack_b, double median);
int		get_stack_size(t_stack *stack_a);
int		last_node(t_stack *stack);
int		rank(int a, int b);
void	quicksort_stack(t_stack **stack_a, t_stack **stack_b, int size);
void	to_stack_b(t_stack **stack_a, t_stack **stack_b, double median, int n);
void	to_stack_a(t_stack **stack_a, t_stack **stack_b);
int		top_is_biggest(t_stack **stack);
int		list_size(t_stack *stack);
int		find_min_value(t_stack *stack);
int		get_min_index(t_stack *stack);
int		is_sorted(t_stack *stack_a);
int		check_dup(t_stack *stack, int num);
void	free_array(char **array);
t_stack	*new_node(int num);
void	free_node(t_stack **node);
void	ft_add_back(t_stack **stack_a, t_stack *new);
t_stack	*check_createlist(char **argv);
int		find_nth_smallest(t_stack *stack, int n);
void	sa(t_stack **stack_a, int flag);
void	sb(t_stack **stack_b, int flag);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a, int flag);
void	rb(t_stack **stack_b, int flag);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a, int flag);
void	rrb(t_stack **stack_b, int flag);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif