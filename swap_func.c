/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoung <jeyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:23:57 by jeykim            #+#    #+#             */
/*   Updated: 2022/10/22 16:36:47 by jeyoung          ###   ########.fr       */
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
	sa(info);
	sb(info);
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

void	ra(t_info *info)
{
	int	elem;

	if (info->a->size < 2)
		return ;
	elem = pop(info->a);
	addfirst(info->a, elem);
}

void	rb(t_info *info)
{
	int	elem;

	if (info->b->size < 2)
		return ;
	elem = pop(info->b);
	addfirst(info->b, elem);
}

void	rr(t_info *info)
{
	ra(info);
	rb(info);
}

void	rra(t_info *info)
{
	int	elem;

	if (info->a->size < 2)
		return ;
	elem = popfirst(info->a);
	add(info->a, elem);
}

void	rrb(t_info *info)
{
	int	elem;

	if (info->b->size < 2)
		return ;
	elem = popfirst(info->b);
	add(info->b, elem);
}

void	rrr(t_info *info)
{
	rra(info);
	rrb(info);
}
