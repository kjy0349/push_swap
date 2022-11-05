/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:54:38 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/05 13:51:30 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include "./libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

int	pop(t_stack *stack)
{
	int		elem;
	t_node	*temp;

	if (stack->size > 0)
	{
		elem = stack->top->prev->data;
		temp = stack->top->prev;
		stack->top->prev = temp->prev;
		temp->prev->next = stack->top;
		free(temp);
		temp = NULL;
		stack->size--;
		return (elem);
	}
	else
		write(2, "stack is empty.\n", 17);
	return (-1);
}

int	popfirst(t_stack *stack)
{
	int		elem;
	t_node	*temp;

	if (stack->top->prev != stack->bot)
	{
		elem = stack->bot->next->data;
		temp = stack->bot->next;
		stack->bot->next = temp->next;
		temp->next->prev = stack->bot;
		free(temp);
		temp = NULL;
		stack->size--;
		return (elem);
	}
	else
		write(2, "stack is empty.\n", 17);
	return (-1);
}

void	add(t_stack *stack, int elem)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		print_error(1);
	new->data = elem;
	new->prev = stack->top->prev;
	stack->top->prev->next = new;
	new->next = stack->top;
	stack->top->prev = new;
	stack->size++;
}

void	addfirst(t_stack *stack, int elem)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		print_error(1);
	new->data = elem;
	new->next = stack->bot->next;
	stack->bot->next->prev = new;
	new->prev = stack->bot;
	stack->bot->next = new;
	stack->size++;
}

void	init_stack(t_stack *stack)
{
	stack->top = (t_node *)malloc(sizeof(t_node));
	if (!stack->top)
		print_error(1);
	stack->bot = (t_node *)malloc(sizeof(t_node));
	if (!stack->bot)
		print_error(1);
	stack->top->data = -1;
	stack->bot->data = -1;
	stack->top->next = NULL;
	stack->top->prev = stack->bot;
	stack->bot->next = stack->top;
	stack->bot->prev = NULL;
	stack->size = 0;
}
