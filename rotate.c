/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:53:00 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/05 20:15:50 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_info *info, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rr(info);
		*a -= 1;
		*b -= 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		rrr(info);
		*a += 1;
		*b += 1;
	}
}

void	rotate_a(t_info *info, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ra(info);
			a--;
		}
		else
		{
			rra(info);
			a++;
		}
	}
}

void	rotate_b(t_info *info, int b)
{
	while (b)
	{
		if (b > 0)
		{
			rb(info);
			b--;
		}
		else
		{
			rrb(info);
			b++;
		}
	}	
}

int	make_pos(int a, int b, int a_idx, int b_idx)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a_idx < 0)
		a_idx *= -1;
	if (b_idx < 0)
		b_idx *= -1;
	if (a + b > a_idx + b_idx)
		return (1);
	else
		return (0);
}
