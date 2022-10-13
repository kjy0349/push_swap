/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:55:03 by jeykim            #+#    #+#             */
/*   Updated: 2022/10/13 16:44:37 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

int		pop(t_stack *stack);
void	add(t_stack *stack, int elem);
int		is_empty(t_stack *stack);
int		is_full(t_stack *stack);

#endif