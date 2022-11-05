/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:54:00 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/05 17:10:56 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_array(int argc, char *argv[], int size)
{
	int		ac_idx;
	int		arr_idx;
	int		*array;
	char	**split_str;

	ac_idx = 1;
	arr_idx = 0;
	array = (int *)malloc(sizeof(int) * (size));
	if (!array)
		print_error(1);
	while (ac_idx < argc)
	{
		split_str = ft_split(argv[ac_idx], ' ');
		set_str_array(array, &arr_idx, split_str);
		free_split(split_str);
		ac_idx++;
	}
	return (array);
}

void	arr_to_stack(t_info *info, int *array, int size)
{
	int		idx;

	idx = size - 1;
	while (idx >= 0)
	{
		add(info->a, array[idx]);
		idx--;
	}
}

void	set_str_array(int *array, int *arr_idx, char **str)
{
	int	tmp;
	int	idx;

	idx = 0;
	while (str[idx])
	{
		tmp = ft_atoichk(str[idx], 0);
		array[*arr_idx] = tmp;
		(*arr_idx)++;
		idx++;
	}
}

int	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}
