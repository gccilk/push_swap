/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaptan <ilkaptan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:37:54 by ilkaptan          #+#    #+#             */
/*   Updated: 2026/09/19 13:37:58 by ilkaptan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/*
** Generic helper function that rotates a circular doubly linked list upwards.
** The top element becomes the last element (top shifts to top->next).
*/
static void	rotate_stack(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->top = stack->top->next;
}

void	ra(t_data *data)
{
	if (!data || data->a.size < 2)
		return ;
	rotate_stack(&data->a);
	data->bench.ra++;
	data->bench.total++;
	if (data->output_mode == OUTPUT_OPERATIONS)
		write(1, "ra\n", 3);
}

void	rb(t_data *data)
{
	if (!data || data->b.size < 2)
		return ;
	rotate_stack(&data->b);
	data->bench.rb++;
	data->bench.total++;
	if (data->output_mode == OUTPUT_OPERATIONS)
		write(1, "rb\n", 3);
}

void	rr(t_data *data)
{
	if (!data)
		return ;
	if (data->a.size >= 2 && data->b.size >= 2)
	{
		rotate_stack(&data->a);
		rotate_stack(&data->b);
		data->bench.rr++;
		data->bench.total++;
		if (data->output_mode == OUTPUT_OPERATIONS)
			write(1, "rr\n", 3);
	}
}
