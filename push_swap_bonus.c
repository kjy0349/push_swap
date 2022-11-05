/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:27:26 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/05 20:50:05 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrr(t_info *info)
{
	int	elem;

	if (info->b->size < 2 || info->a->size < 2)
		return ;
	elem = popfirst(info->a);
	add(info->a, elem);
	elem = popfirst(info->b);
	add(info->b, elem);
}

int	execute_commands(char *str, t_info *info, int ret)
{
	if (!ft_strncmp(str, "sa\n", sizeof(str)))
		sa(info);
	else if (!ft_strncmp(str, "sb\n", sizeof(str)))
		sb(info);
	else if (!ft_strncmp(str, "ss\n", sizeof(str)))
		ss(info);
	else if (!ft_strncmp(str, "pa\n", sizeof(str)))
		pa(info);
	else if (!ft_strncmp(str, "pb\n", sizeof(str)))
		pb(info);
	else if (!ft_strncmp(str, "ra\n", sizeof(str)))
		ra(info);
	else if (!ft_strncmp(str, "rb\n", sizeof(str)))
		rb(info);
	else if (!ft_strncmp(str, "rr\n", sizeof(str)))
		rr(info);
	else if (!ft_strncmp(str, "rra\n", sizeof(str)))
		rra(info);
	else if (!ft_strncmp(str, "rrb\n", sizeof(str)))
		rrb(info);
	else if (!ft_strncmp(str, "rrr\n", sizeof(str)))
		rrr(info);
	else
		ret = 0;
	return (ret);
}

int	check_sorted(t_info *info)
{
	int		is_sorted;
	t_node	*idx;

	is_sorted = 1;
	idx = info->a->top->prev;
	while (idx != info->a->bot->next)
	{
		if (idx->data > idx->prev->data)
		{
			is_sorted = 0;
			break ;
		}
		idx = idx->prev;
	}
	return (is_sorted);
}

void	get_commands(t_info *info)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		execute_commands(str, info, 1);
	}
	if (check_sorted(info))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
	get_commands(&info);
	free(info.array);
	free_stack(info.a);
	free_stack(info.b);
}
