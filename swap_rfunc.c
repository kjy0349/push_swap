/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:18:04 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/04 19:19:37 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ra(t_info *info)
{
	int	elem;

	if (info->a->size < 2)
		return ;
	elem = pop(info->a);
	addfirst(info->a, elem);
	write(1, "ra\n", 3);
}

void	rb(t_info *info)
{
	int	elem;

	if (info->b->size < 2)
		return ;
	elem = pop(info->b);
	addfirst(info->b, elem);
	write(1, "rb\n", 3);
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
	write(1, "rr\n", 3);
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
