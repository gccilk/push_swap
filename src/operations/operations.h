/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaptan <ilkaptan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 12:50:04 by ilkaptan          #+#    #+#             */
/*   Updated: 2026/09/20 17:34:31 by ilkaptan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../../push_swap.h"

typedef enum e_output_mode
{
	OUTPUT_OPERATIONS,
	OUTPUT_BENCH
	//OUTPUT_COUNT_ONLY
}					t_output_mode;

typedef enum e_strategy
{
	STRATEGY_ADAPTIVE,
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX
}					t_strategy;

typedef enum e_operation
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}					t_operation;

typedef struct s_bench
{
	int				total;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_bench;

typedef struct s_data
{
	t_stack			a;
	t_stack			b;
	double			disorder;
	t_strategy		strategy;
	t_output_mode	output_mode;
	t_bench			bench;
}					t_data;

/* Swap */
void				sa(t_data *data);
void				sb(t_data *data);
void				ss(t_data *data);

/* Push */
void				pa(t_data *data);
void				pb(t_data *data);

/* Rotate */
void				ra(t_data *data);
void				rb(t_data *data);
void				rr(t_data *data);

/* Reverse rotate */
void				rra(t_data *data);
void				rrb(t_data *data);
void				rrr(t_data *data);

#endif
