/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:39:27 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/04 18:55:52 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sort(int *array, int size, int idx)
{
	int	j;
	int	checker;
	int	tmp;

	checker = 0;
	while (idx < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				checker++;
			}
				j++;
		}
		if (array[idx] == array[idx + 1])
			print_error(1);
		idx++;
	}
	if (checker == 0)
		print_error(-1);
}

void	sort_all(t_info *info)
{
	int	a;
	int	b;

	set_pivot_divide(info);
	while (info->a->size > 3)
		pb(info);
	if (info->a->size == 2)
	{
		if (info->a->top->prev->data > info->a->bot->next->data)
			sa(info);
	}
	else if (info->a->size == 3)
		sort_triple(info);
	while (info->b->size > 0)
	{
		a = 0;
		b = 0;
		get_min_rtcnt(info, &a, &b);
		rrotate(info, &a, &b);
		rotate_a(info, a);
		rotate_b(info, b);
		pa(info);
	}
	last_sort(info);
}

void	sort_elem(t_info *info)
{
	if (info->a->size == 2)
	{
		if (info->a->top->prev->data > info->a->bot->next->data)
			sa(info);
	}
	else if (info->a->size == 3)
		sort_triple(info);
	else
		sort_all(info);
}

void	last_sort(t_info *info)
{
	int	min;
	int	min_idx;

	min = get_min_stack(info->a);
	min_idx = set_min(info);
	while (min_idx)
	{
		if (min_idx > 0)
		{
			ra(info);
			min_idx--;
		}
		else
		{
			rra(info);
			min_idx++;
		}
	}
}

void	sort_triple(t_info *info)
{
	int	top;
	int	bot;
	int	mid;

	top = info->a->top->prev->data;
	bot = info->a->bot->next->data;
	mid = info->a->bot->next->next->data;
	if (top < mid && mid > bot && top < bot)
	{
		sa(info);
		ra(info);
	}
	else if (top > mid && mid < bot && top < bot)
		sa(info);
	else if (top < mid && mid > bot && top > bot)
		rra(info);
	else if (top > mid && bot > mid && top > bot)
		ra(info);
	else if (top > mid && mid > bot && top > bot)
	{
		sa(info);
		rra(info);
	}
}
