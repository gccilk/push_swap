/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaptan <ilkaptan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 15:46:28 by ilkaptan          #+#    #+#             */
/*   Updated: 2026/09/19 15:46:35 by ilkaptan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

/*
** Eleman sayısına göre kaç bit kaydırma yapacağımızı hesaplar.
*/
static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}

/*
** Complex Strategy - O(n log n) Radix Sort
*/
void	run_complex(t_data *data)
{
	int	max_bits;
	int	bit;
	int	i;
	int	size;

	if (!data || is_sorted(&data->a))
		return ;
	index_stack(&data->a);
	size = data->a.size;
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((data->a.top->index >> bit) & 1) == 1)
				ra(data);
			else
				pb(data);
			i++;
		}
		while (data->b.size > 0)
			pa(data);
		bit++;
	}
}
