/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaptan <ilkaptan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 11:58:48 by ilkaptan          #+#    #+#             */
/*   Updated: 2026/09/20 17:37:45 by ilkaptan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_is_empty(t_stack *stack)
{
	if (!stack)
		return (1);
	return (stack->top == NULL);
}

t_node	*stack_last(t_stack *stack)
{
	if (!stack || !stack->top)
		return (NULL);
	return (stack->top->prev);
}

void	stack_clear(t_stack *stack)
{
	t_node	*current;
	t_node	*next;
	int		i;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	i = 0;
	while (i < stack->size)
	{
		next = current->next;
		free(current);
		current = next;
		i++;
	}
	stack->top = NULL;
	stack->size = 0;
}
