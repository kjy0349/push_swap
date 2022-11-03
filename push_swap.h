/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:55:03 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/03 12:58:06 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

int		pop(t_stack *stack);
void	add(t_stack *stack, int elem);
int		is_empty(t_stack *stack);
int		is_full(t_stack *stack);
void	free_stack(t_stack *stack);
void	free_all(t_info *info);

#endif