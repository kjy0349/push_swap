/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:16:00 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/05 21:36:07 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(int type)
{
	if (type >= 1)
		write(2, "Error\n", 6);
	exit(1);
	return (-1);
}

void	divide_triple(t_info *info, int piv1, int piv2)
{
	if (info->a->top->prev->data < piv1)
	{
		pb(info);
		rb(info);
	}
	else if (info->a->top->prev->data < piv2)
		pb(info);
	else
		ra(info);
}

void	check_dup(t_info *info, int arr_size)
{
	int	*array;
	int	i;
	int	j;

	array = info->array;
	i = 0;
	j = 0;
	while (i < arr_size)
	{
		j = i + 1;
		while (j < arr_size)
		{
			if (array[i] == array[j])
			{
				free_stack(info->a);
				free_stack(info->b);
				free(info->array);
				print_error(1);
			}
			j++;
		}
		i++;
	}
}

int	get_input_size(int argc, char *argv[])
{
	int		idx;
	int		size;
	int		elem_cnt;
	char	**parsed_str;

	idx = 1;
	size = 0;
	while (idx < argc)
	{
		elem_cnt = 0;
		while (argv[idx][elem_cnt])
		{
			if (!ft_isspace(argv[idx][elem_cnt]))
				break ;
			elem_cnt++;
		}
		if (argv[idx][elem_cnt] == '\0')
			print_error(1);
		parsed_str = ft_split(argv[idx], ' ');
		size += split_size(parsed_str);
		free_split(parsed_str);
		idx++;
	}
	return (size);
}
