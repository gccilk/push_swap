/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaptan <ilkaptan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:33:05 by ilkaptan          #+#    #+#             */
/*   Updated: 2026/09/19 13:33:10 by ilkaptan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/*
** Pop the top node from 'src' stack and push it to the top of 'dst' stack.
** Handles all edge cases for circular doubly linked list (size == 1, empty stack, etc.)
*/
static void	push_stack(t_stack *src, t_stack *dst)
{
	t_node	*pushed_node;
	t_node	*dst_last;

	if (!src || src->size == 0)
		return ;
	pushed_node = src->top;
	if (src->size == 1)
		src->top = NULL;
	else
	{
		src->top = pushed_node->next;
		pushed_node->prev->next = pushed_node->next;
		pushed_node->next->prev = pushed_node->prev;
	}
	src->size--;
	if (dst->size == 0)
	{
		dst->top = pushed_node;
		pushed_node->next = pushed_node;
		pushed_node->prev = pushed_node;
	}
	else
	{
		dst_last = dst->top->prev;
		pushed_node->next = dst->top;
		pushed_node->prev = dst_last;
		dst->top->prev = pushed_node;
		dst_last->next = pushed_node;
		dst->top = pushed_node;
	}
	dst->size++;
}

void	pa(t_data *data)
{
	if (!data || data->b.size == 0)
		return ;
	push_stack(&data->b, &data->a);
	data->bench.pa++;
	data->bench.total++;
	if (data->output_mode == OUTPUT_OPERATIONS)
		write(1, "pa\n", 3);
}

void	pb(t_data *data)
{
	if (!data || data->a.size == 0)
		return ;
	push_stack(&data->a, &data->b);
	data->bench.pb++;
	data->bench.total++;
	if (data->output_mode == OUTPUT_OPERATIONS)
		write(1, "pb\n", 3);
}
