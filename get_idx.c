/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_idx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:59:27 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/05 14:40:19 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_stack(t_stack *stack)
{
	t_node	*node;
	int		elem;

	node = stack->bot->next;
	elem = node->data;
	while (node != stack->top)
	{
		if (elem > node->data)
			elem = node->data;
		node = node->next;
	}
	return (elem);
}

int	get_max_stack(t_stack *stack)
{
	t_node	*node;
	int		elem;

	node = stack->bot->next;
	elem = node->data;
	while (node != stack->top)
	{
		if (elem < node->data)
			elem = node->data;
		node = node->next;
	}
	return (elem);
}

int	get_a_idx(int num, t_info *info)
{
	int	elem;

	if (num < get_min_stack(info->a))
		elem = set_min(info);
	else if (num > get_max_stack(info->a))
		elem = set_max(info);
	else
		elem = set_mid(num, info);
	return (elem);
}

void	get_min_rtcnt(t_info *info, int *a, int *b)
{
	int		a_idx;
	int		b_idx;
	int		idx;
	t_node	*b_node;
	int		num;

	idx = 0;
	b_node = info->b->top->prev;
	while (idx < info->b->size)
	{
		num = b_node->data;
		a_idx = get_a_idx(num, info);
		if (idx >= (info->b->size + 1) / 2)
			b_idx = (info->b->size - idx) * -1;
		else
			b_idx = idx;
		if (idx == 0 || make_pos(*a, *b, a_idx, b_idx))
		{
			*a = a_idx;
			*b = b_idx;
		}
		b_node = b_node->prev;
		idx++;
	}
}
