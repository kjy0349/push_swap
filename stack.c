/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoung <jeyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:54:38 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/02 14:25:45 by jeyoung          ###   ########.fr       */
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

	if (stack->top->prev != stack->bot)
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
	stack->bot = (t_node *)malloc(sizeof(t_node));
	stack->top->data = -1;
	stack->bot->data = -1;
	stack->top->next = NULL;
	stack->top->prev = stack->bot;
	stack->bot->next = stack->top;
	stack->bot->prev = NULL;
	stack->size = 0;
}

int	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}

void	print_stack(t_info *info)
{
	t_node	*idxa;
	t_node	*idxb;
	char	*elema;
	char	*elemb;

	idxa = info->a->top->prev;
	idxb = info->b->top->prev;
	while (idxa != info->a->bot || idxb != info->b->bot)
	{
		if (idxa != info->a->bot)
		{
			elema = ft_itoa(idxa->data);
			idxa = idxa->prev;
		}
		else
			elema = " ";
		if (idxb != info->b->bot)
		{
			elemb = ft_itoa(idxb->data);
			idxb = idxb->prev;
		}
		else
			elemb = " ";
		printf("%s %s\n", elema, elemb);
	}	
}
