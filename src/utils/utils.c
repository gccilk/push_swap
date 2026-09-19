/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaptan <ilkaptan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 14:23:13 by ilkaptan          #+#    #+#             */
/*   Updated: 2026/09/19 15:45:41 by ilkaptan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** Stack A'nın küçükten büyüğe sıralı olup olmadığını kontrol eder.
** Eğer sıralıysa 1, sıralama bozuksa 0 döndürür.
*/
int	is_sorted(t_stack *stack)
{
	t_node	*curr;
	int		i;

	if (!stack || stack->size <= 1)
		return (1);
	curr = stack->top;
	i = 0;
	while (i < stack->size - 1)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
		i++;
	}
	return (1);
}

/*
** Stack A'daki sayıları sıralı indeks değerlerine dönüştürür.
** Örn: [-5, 100, 2] -> [0, 2, 1] haline gelir.
*/
void	index_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*compare;
	int		count;
	int		i;
	int		j;

	if (!stack || !stack->top)
		return ;
	curr = stack->top;
	i = 0;
	while (i < stack->size)
	{
		count = 0;
		compare = stack->top;
		j = 0;
		while (j < stack->size)
		{
			if (compare->value < curr->value)
				count++;
			compare = compare->next;
			j++;
		}
		curr->index = count;
		curr = curr->next;
		i++;
	}
}