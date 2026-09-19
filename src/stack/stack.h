/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaptan <ilkaptan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 11:58:10 by ilkaptan          #+#    #+#             */
/*   Updated: 2026/09/19 11:58:20 by ilkaptan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* stack.c */
t_node	*stack_new_node(int value);
void	stack_init(t_stack *stack);
void	stack_add_front(t_stack *stack, t_node *new_node);
void	stack_add_back(t_stack *stack, t_node *new_node);

/* stack_utils.c */
int		stack_is_empty(t_stack *stack);
t_node	*stack_last(t_stack *stack);
void	stack_clear(t_stack *stack);

#endif
