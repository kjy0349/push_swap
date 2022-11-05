/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:52:10 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/05 20:52:02 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

void	rrr(t_info *info)
{
	int	elem;

	if (info->b->size < 2 || info->a->size < 2)
		return ;
	elem = popfirst(info->a);
	add(info->a, elem);
	elem = popfirst(info->b);
	add(info->b, elem);
	write(1, "rrr\n", 4);
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
