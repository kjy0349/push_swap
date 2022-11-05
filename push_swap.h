/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:55:03 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/05 20:12:26 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "./libft/libft.h"

int		pop(t_stack *stack);
void	add(t_stack *stack, int elem);
int		is_empty(t_stack *stack);
int		is_full(t_stack *stack);
void	free_stack(t_stack *stack);
void	free_all(t_info *info);
int		ft_isspace(char c);
int		split_size(char **parsed_str);
int		print_error(int type);
void	free_split(char **parsed_str);
void	check_sort(int *array, int size, int idx);
int		ft_atoichk(const char *str, int i);
void	sort_all(t_info *info);
void	sort_elem(t_info *info);
void	last_sort(t_info *info);
void	rrotate(t_info *info, int *a, int *b);
void	rotate_a(t_info *info, int a);
void	rotate_b(t_info *info, int b);
int		*make_array(int argc, char *argv[], int size);
void	arr_to_stack(t_info *info, int *array, int size);
void	set_str_array(int *array, int *arr_idx, char **str);
void	sort_triple(t_info *info);
int		set_min(t_info *info);
int		set_max(t_info *info);
int		set_mid(int num, t_info *info);
int		make_pos(int a, int b, int a_idx, int b_idx);
int		get_min_stack(t_stack *stack);
int		get_max_stack(t_stack *stack);
int		get_a_idx(int num, t_info *info);
void	get_min_rtcnt(t_info *info, int *a, int *b);
void	free_stack(t_stack *stack);
void	set_pivot_divide(t_info *info);
void	divide_triple(t_info *info, int piv1, int piv2);
int		get_input_size(int argc, char *argv[]);
int		print_error(int type);
int		is_empty(t_stack *stack);
void	check_dup(t_info *info, int arr_size);

#endif