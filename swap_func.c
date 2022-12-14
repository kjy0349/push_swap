/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:23:57 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/05 20:43:41 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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
	write(1, "sa\n", 3);
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
	write(1, "sb\n", 3);
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
	write(1, "ss\n", 3);
}

void	pa(t_info *info)
{
	int	elem;

	if (is_empty(info->b))
		return ;
	elem = pop(info->b);
	add(info->a, elem);
	write(1, "pa\n", 3);
}

void	pb(t_info *info)
{
	int	elem;

	if (is_empty(info->a))
		return ;
	elem = pop(info->a);
	add(info->b, elem);
	write(1, "pb\n", 3);
}
