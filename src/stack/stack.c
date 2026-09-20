/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaptan <ilkaptan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 11:58:27 by ilkaptan          #+#    #+#             */
/*   Updated: 2026/09/20 17:37:41 by ilkaptan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node	*stack_new_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

void	stack_init(t_stack *stack)
{
	if (!stack)
		return ;
	stack->top = NULL;
	stack->size = 0;
}

void	stack_add_front(t_stack *stack, t_node *new_node)
{
	t_node	*last;

	if (!stack || !new_node)
		return ;
	if (!stack->top)
	{
		stack->top = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
		stack->size++;
		return ;
	}
	last = stack->top->prev;
	new_node->next = stack->top;
	new_node->prev = last;
	last->next = new_node;
	stack->top->prev = new_node;
	stack->top = new_node;
	stack->size++;
}

void	stack_add_back(t_stack *stack, t_node *new_node)
{
	t_node	*last;

	if (!stack || !new_node)
		return ;
	if (!stack->top)
	{
		stack->top = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
		stack->size++;
		return ;
	}
	last = stack->top->prev;
	new_node->next = stack->top;
	new_node->prev = last;
	last->next = new_node;
	stack->top->prev = new_node;
	stack->size++;
}
