/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaptan <ilkaptan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:38:07 by ilkaptan          #+#    #+#             */
/*   Updated: 2026/09/19 13:38:31 by ilkaptan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/*
** Generic helper function that rotates a circular doubly linked list downwards.
** The last element becomes the top element (top shifts to top->prev).
*/
static void	reverse_rotate_stack(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->top = stack->top->prev;
}

void	rra(t_data *data)
{
	if (!data || data->a.size < 2)
		return ;
	reverse_rotate_stack(&data->a);
	data->bench.rra++;
	data->bench.total++;
	if (data->output_mode == OUTPUT_OPERATIONS)
		write(1, "rra\n", 4);
}

void	rrb(t_data *data)
{
	if (!data || data->b.size < 2)
		return ;
	reverse_rotate_stack(&data->b);
	data->bench.rrb++;
	data->bench.total++;
	if (data->output_mode == OUTPUT_OPERATIONS)
		write(1, "rrb\n", 4);
}

void	rrr(t_data *data)
{
	if (!data)
		return ;
	if (data->a.size >= 2 && data->b.size >= 2)
	{
		reverse_rotate_stack(&data->a);
		reverse_rotate_stack(&data->b);
		data->bench.rrr++;
		data->bench.total++;
		if (data->output_mode == OUTPUT_OPERATIONS)
			write(1, "rrr\n", 4);
	}
}
