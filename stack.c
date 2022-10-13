/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:54:38 by jeykim            #+#    #+#             */
/*   Updated: 2022/10/13 17:22:10 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include "ft_printf.h"
#include <stdlib.h>

int	pop(t_stack *stack)
{
	int		elem;
	t_node	*temp;

	if (stack->size > 0)
	{
		elem = stack->top->data;
		if (stack->top->prev)
		{
			temp = stack->top;
			stack->top = stack->top->prev;
			stack->top->next = NULL;
			free(temp);
		}
	}
	else
		return (-1);
	return (elem);
}

void	add(t_stack *stack, int elem)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->prev = stack->top;
	new->next = NULL;
	stack->top->next = new;
	stack->top = new;
}

int	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}
