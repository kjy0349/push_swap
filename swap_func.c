/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:23:57 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/03 17:56:48 by jeykim           ###   ########.fr       */
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
	write(1, "sa\n", 4);
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
	write(1, "sb\n", 4);
}

void	ss(t_info *info)
{
	sa(info);
	sb(info);
	write(1, "ss\n", 4);
}

void	pa(t_info *info)
{
	int	elem;

	if (is_empty(info->b))
		return ;
	elem = pop(info->b);
	add(info->a, elem);
	write(1, "pa\n", 4);
}

void	pb(t_info *info)
{
	int	elem;

	if (is_empty(info->a))
		return ;
	elem = pop(info->a);
	add(info->b, elem);
	write(1, "pb\n", 4);
}

void	ra(t_info *info)
{
	int	elem;

	if (info->a->size < 2)
		return ;
	elem = pop(info->a);
	addfirst(info->a, elem);
	write(1, "ra\n", 4);
}

void	rb(t_info *info)
{
	int	elem;

	if (info->b->size < 2)
		return ;
	elem = pop(info->b);
	addfirst(info->b, elem);
	write(1, "rb\n", 4);
}

void	rr(t_info *info)
{
	ra(info);
	rb(info);
	write(1, "rr\n", 4);
}

void	rra(t_info *info)
{
	int	elem;

	if (info->a->size < 2)
		return ;
	elem = popfirst(info->a);
	add(info->a, elem);
	write(1, "rra\n", 4);
}

void	rrb(t_info *info)
{
	int	elem;

	if (info->b->size < 2)
		return ;
	elem = popfirst(info->b);
	add(info->b, elem);
	write(1, "rrb\n", 4);
}

void	rrr(t_info *info)
{
	rra(info);
	rrb(info);
	write(1, "rrr\n", 4);
}
