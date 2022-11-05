/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:43:46 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/05 20:48:55 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_info *info)
{
	t_stack	*a;
	int		elem1;
	int		elem2;

	if (info->a->size < 2)
		return ;
	a = info->a;
	elem1 = pop(a);
	elem2 = pop(a);
	add(a, elem1);
	add(a, elem2);
}

void	sb(t_info *info)
{
	t_stack	*b;
	int		elem1;
	int		elem2;

	if (info->b->size < 2)
		return ;
	b = info->b;
	elem1 = pop(b);
	elem2 = pop(b);
	add(b, elem1);
	add(b, elem2);
}

void	ss(t_info *info)
{
	t_stack	*stack;
	int		elem1;
	int		elem2;

	stack = info->a;
	elem1 = pop(stack);
	elem2 = pop(stack);
	add(stack, elem1);
	add(stack, elem2);
	stack = info->b;
	elem1 = pop(stack);
	elem2 = pop(stack);
	add(stack, elem1);
	add(stack, elem2);
}

void	pa(t_info *info)
{
	int	elem;

	if (is_empty(info->b))
		return ;
	elem = pop(info->b);
	add(info->a, elem);
}

void	pb(t_info *info)
{
	int	elem;

	if (is_empty(info->a))
		return ;
	elem = pop(info->a);
	add(info->b, elem);
}
