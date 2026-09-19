/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaptan <ilkaptan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 14:19:29 by ilkaptan          #+#    #+#             */
/*   Updated: 2026/09/19 14:19:33 by ilkaptan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

/*
** Finds the index of the minimum element in stack A.
*/
static int	find_min_index(t_stack *stack)
{
	t_node	*curr;
	int		min_val;
	int		min_idx;
	int		i;

	if (!stack || !stack->top)
		return (0);
	curr = stack->top;
	min_val = curr->value;
	min_idx = 0;
	i = 0;
	while (i < stack->size)
	{
		if (curr->value < min_val)
		{
			min_val = curr->value;
			min_idx = i;
		}
		curr = curr->next;
		i++;
	}
	return (min_idx);
}

/*
** Rotates stack A to bring the minimum element to the top via shortest path.
*/
static void	bring_min_to_top(t_data *data, int min_idx)
{
	int	size;

	size = data->a.size;
	if (min_idx <= size / 2)
	{
		while (min_idx > 0)
		{
			ra(data);
			min_idx--;
		}
	}
	else
	{
		while (min_idx < size)
		{
			rra(data);
			min_idx++;
		}
	}
}

/*
** Simple Strategy - O(n^2) Selection Sort Adaptation
*/
void	run_simple(t_data *data)
{
	int	min_idx;

	if (!data || is_sorted(&data->a))
		return ;
	while (data->a.size > 0)
	{
		min_idx = find_min_index(&data->a);
		bring_min_to_top(data, min_idx);
		pb(data);
	}
	while (data->b.size > 0)
		pa(data);
}
