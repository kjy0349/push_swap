/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:52:10 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/05 17:13:31 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

int	print_error(int type)
{
	if (type >= 1)
		write(2, "Error\n", 6);
	exit(1);
	return (-1);
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

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_info	info;
	int		arr_size;
	int		*arr;

	if (argc < 2)
		print_error(-1);
	arr_size = 0;
	init_stack(&a);
	init_stack(&b);
	info.a = &a;
	info.b = &b;
	arr_size = get_input_size(argc, argv);
	arr = make_array(argc, argv, arr_size);
	info.array = arr;
	arr_to_stack(&info, arr, arr_size);
	check_dup(&info, arr_size);
	check_sort(arr, arr_size, 0);
	sort_elem(&info);
	free(info.array);
	free_stack(info.a);
	free_stack(info.b);
}
