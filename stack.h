/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:11:35 by jeykim            #+#    #+#             */
/*   Updated: 2022/10/13 17:12:40 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# define STACK_SIZE 100

typedef struct node
{
	int		data;
	t_node	*prev;
	t_node	*next;
}	t_node;

typedef struct stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
}	t_stack;

typedef struct info
{
	t_stack	a;
	t_stack	b;
}	t_info;


#endif