/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaptan <ilkaptan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:29:46 by ilkaptan          #+#    #+#             */
/*   Updated: 2026/09/19 13:31:30 by ilkaptan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/*
** Generic helper function that swaps the top two elements of a circular
** doubly linked list safely, accounting for size == 2 edge cases.
*/
static void	swap_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	if (stack->size == 2)
	{
		stack->top = second;
		return ;
	}
	last = first->prev;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = last;
	last->next = second;
	stack->top = second;
}

void	sa(t_data *data)
{
	if (!data || data->a.size < 2)
		return ;
	swap_stack(&data->a);
	data->bench.sa++;
	data->bench.total++;
	if (data->output_mode == OUTPUT_OPERATIONS)
		write(1, "sa\n", 3);
}

void	sb(t_data *data)
{
	if (!data || data->b.size < 2)
		return ;
	swap_stack(&data->b);
	data->bench.sb++;
	data->bench.total++;
	if (data->output_mode == OUTPUT_OPERATIONS)
		write(1, "sb\n", 3);
}

void	ss(t_data *data)
{
	if (!data)
		return ;
	if (data->a.size >= 2 && data->b.size >= 2)
	{
		swap_stack(&data->a);
		swap_stack(&data->b);
		data->bench.ss++;
		data->bench.total++;
		if (data->output_mode == OUTPUT_OPERATIONS)
			write(1, "ss\n", 3);
	}
}
