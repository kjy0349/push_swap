/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rfunc_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:44:27 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/05 20:44:52 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	int	elem;

	if (info->b->size < 2 || info->a->size < 2)
		return ;
	elem = pop(info->a);
	addfirst(info->a, elem);
	elem = pop(info->b);
	addfirst(info->b, elem);
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
