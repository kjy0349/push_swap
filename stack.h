/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:11:35 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/05 16:50:44 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <unistd.h>

typedef struct node
{
	int			data;
	struct node	*prev;
	struct node	*next;
}	t_node;

typedef struct stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
}	t_stack;

typedef struct info
{
	t_stack	*a;
	t_stack	*b;
	int		*array;
}	t_info;

int		pop(t_stack *stack);
void	add(t_stack *stack, int elem);
void	init_stack(t_stack *stack);
int		is_empty(t_stack *stack);
void	print_stack(t_info *info);
void	addfirst(t_stack *stack, int elem);
int		popfirst(t_stack *stack);
void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);
void	pa(t_info *info);
void	pb(t_info *info);
void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);
#endif