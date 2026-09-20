/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaptan <ilkaptan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:33:05 by ilkaptan          #+#    #+#             */
/*   Updated: 2026/09/20 17:21:47 by ilkaptan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static t_node	*detach_top(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size == 0)
		return (NULL);
	node = stack->top;
	if (stack->size == 1)
		stack->top = NULL;
	else
	{
		stack->top = node->next;
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	stack->size--;
	node->next = node;
	node->prev = node;
	return (node);
}

static void	attach_top(t_stack *stack, t_node *node)
{
	t_node	*last;

	if (!stack || !node)
		return ;
	if (stack->size == 0)
	{
		stack->top = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		last = stack->top->prev;
		node->next = stack->top;
		node->prev = last;
		last->next = node;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
}

static void	push_stack(t_stack *src, t_stack *dst)
{
	t_node	*node;

	node = detach_top(src);
	if (!node)
		return ;
	attach_top(dst, node);
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
