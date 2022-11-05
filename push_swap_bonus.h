/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:08:17 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/05 20:46:19 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "./libft/libft.h"
# include "get_next_line.h"
# include "push_swap.h"

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
