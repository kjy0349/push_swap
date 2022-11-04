/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:56:25 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/04 18:57:25 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_min(t_info *info)
{
	int		elem;
	int		target;
	int		temp;
	t_node	*idx;

	elem = 0;
	target = 0;
	target = get_min_stack(info->a);
	idx = info->a->top->prev;
	while (idx != info->a->bot)
	{
		temp = idx->data;
		if (temp == target)
			break ;
		idx = idx->prev;
		elem++;
	}
	if (elem >= (info->a->size + 1) / 2)
		elem = (info->a->size - elem) * -1;
	return (elem);
}

int	set_max(t_info *info)
{
	int		elem;
	int		target;
	int		temp;
	t_node	*idx;

	elem = 0;
	target = 0;
	target = get_max_stack(info->a);
	idx = info->a->top->prev;
	while (idx != info->a->bot)
	{
		temp = idx->data;
		if (temp == target)
			break ;
		idx = idx->prev;
		elem++;
	}
	elem++;
	if (elem >= (info->a->size + 1) / 2)
		elem = (info->a->size - elem) * -1;
	return (elem);
}

int	set_mid(int num, t_info *info)
{
	t_node	*idx;
	int		elem;

	elem = 1;
	idx = info->a->top->prev;
	while (idx->prev != info->a->bot)
	{
		if (num > idx->data && num < idx->prev->data)
			break ;
		elem++;
		idx = idx->prev;
	}
	if (elem >= (info->a->size + 1) / 2)
		elem = (info->a->size - elem) * -1;
	return (elem);
}